## Stored Procedures
### Identificar duas situações para implementação de procedures
### Implementar as procedures e os casos de testes das procedures

USE `DRTOK`;

########################################################################
# Procedure que calcula os ganhos de um funcionário com os descontos

DROP PROCEDURE IF EXISTS Pagamento;
DELIMITER //
CREATE PROCEDURE Pagamento(IN nomeFuncionario varchar(50))
BEGIN
	SELECT f.Nome as Nome, f.funcao as Função, (
		(SELECT SUM(v.valor)
			FROM vencimento as v, contracheque as c, funcionario as f
			WHERE v.fkcontrachequecodcontracheque = c.codcontracheque
				AND v.fkfuncionariocpf = f.cpf
				AND f.cpf = (
					SELECT cpf 
					FROM Funcionario 
					WHERE nome = nomeFuncionario) AND v.tipovencimento = 'RECEITA'
		) - (SELECT SUM(v.valor)
			FROM vencimento as v, contracheque as c, funcionario as f
			WHERE v.fkcontrachequecodcontracheque = c.codcontracheque
				AND v.fkfuncionariocpf = f.cpf
				AND f.cpf = (
					SELECT cpf
					FROM Funcionario
					WHERE nome = nomeFuncionario) AND v.tipovencimento = 'DESCONTO'
		)
	) as Pagamento
	FROM vencimento as v, contracheque as c, funcionario as f
	WHERE v.fkcontrachequecodcontracheque = c.codcontracheque
		AND v.fkfuncionariocpf = f.cpf
		AND f.cpf = (
			SELECT cpf 
			FROM Funcionario
			WHERE nome = nomeFuncionario)
	GROUP BY f.nome;
END // 
DELIMITER ;

CALL Pagamento('Cláudio Thales da Mota');

########################################################################
# Procedure que exibe os funcionários de um cargo específico

DROP PROCEDURE IF EXISTS Cargo;
DELIMITER //
CREATE PROCEDURE Cargo(IN funcao varchar(50))
BEGIN
	SELECT f.nome as Nome, f.setor as Setor, f.funcao as Função, e.cidade as Cidade
	FROM Funcionario as f, endereco as e
	WHERE f.funcao = funcao AND f.fkenderecocep = e.cep
	ORDER BY e.cep;
END // 
DELIMITER ;

CALL Cargo('Supervisor');

########################################################################
# A descoberta dos funcionários que são faxineiros de uma mesma cidade, que é prático para alocar equipes em determinados serviços locais 

DROP PROCEDURE IF EXISTS FuncionariosCidade;
DELIMITER //
CREATE PROCEDURE FuncionariosCidade(IN cidade varchar(50), IN funcao varchar(50))
BEGIN
	SELECT f.nome as Nome, e.cep as CEP, e.rua as Rua, e.cidade as Cidade
	FROM Funcionario as f, Endereco as e
	WHERE e.cep = f.FKenderecocep AND e.cidade = cidade AND f.funcao = funcao
	ORDER BY f.nome;
END // 
DELIMITER ;

CALL FuncionariosCidade('COLATINA','FAXINEIRO');


########################################################################
# Procedure para retornar a soma dos preços de um serviço, utilizando uma busca por parte do nome.

DROP PROCEDURE IF EXISTS ProdutoServico;
DELIMITER //
CREATE PROCEDURE ProdutoServico(IN dcr varchar(50))
BEGIN
	UPDATE Servico
	SET preco = (
		SELECT SUM(p.preco)
		FROM Produto as p, Servico as s, Coleta as c
		WHERE p.codproduto = c.fkprodutocodproduto AND s.codservico = c.fkservicocodservico AND s.codservico = (
			SELECT codservico FROM Servico WHERE dcrservico LIKE dcr))
	WHERE Servico.codservico = (
			SELECT codservico FROM Servico WHERE dcrservico LIKE dcr);
END // 
DELIMITER ;

CALL ProdutoServico('%completa');


########################################################################
# Procedure para a busca de um funcionario, onde ela também retorna o mesmo

DROP PROCEDURE IF EXISTS buscaFuncionario;
DELIMITER //
CREATE PROCEDURE buscaFuncionario(IN cpf varchar(12), OUT outcpf varchar(11))
BEGIN
	SET outcpf = (
		SELECT f.cpf as CPF
		FROM Funcionario as f
		WHERE f.cpf = cpf
	);
END //
DELIMITER ;

########################################################################
# Teste da Procedure anterior

DROP PROCEDURE IF EXISTS testeBuscaFuncionario;
DELIMITER //
CREATE PROCEDURE testeBuscaFuncionario(IN cpf varchar(12))
BEGIN
	SET @outcpf = '12345678901';
	CALL buscaFuncionario(cpf, @outcpf);
	SELECT @outcpf;
END //
DELIMITER ;

CALL testeBuscaFuncionario('77209625755');


########################################################################
# Procedure inicialmente pensada para o trabalho como um Trigger,
# Porem as restições de atualização em dados que estão sendo lidos,
# não permitia que fizesse na a partir de um evento
# convertendo estaticamente para uma Procedure temos o resutado,
# os calculos dos descontos de um funcionario.

DROP PROCEDURE IF EXISTS calculaDesconto;
DELIMITER //
CREATE PROCEDURE calculaDesconto (  IN trgCodVencimento INT,
									IN trgTipoVencimento varchar(50),
									IN trgFKContrachequeCodContracheque INT,
									IN trgFKFuncionarioCPF CHAR(11))
BEGIN

	SET @receitas = 0, @imposto = 0, @empregado = 0;
	SET @receitas = (
		SELECT SUM(v.valor)
		FROM vencimento as v, contracheque as c, funcionario as f
		WHERE 	v.fkcontrachequecodcontracheque = c.codcontracheque AND
				v.fkfuncionariocpf = f.cpf AND
				v.tipovencimento = 'RECEITA' AND v.codVencimento = trgCodVencimento
	);

	IF @receitas < 1751.82 THEN 
		SET @imposto = 8;
	ELSEIF @receitas > 1751.81 AND @receitas < 2919.73 THEN
		SET @imposto = 9;
	ELSEIF @receitas > 2919.72 AND @receitas < 5839.46 THEN
		SET @imposto = 11;
	ELSE
		SET @imposto = 13;
	END IF;

	CALL buscaFuncionario(trgfkfuncionariocpf, @empregado);
	
	UPDATE vencimento 
	SET valor = ((@receitas * @imposto) / 100)
	WHERE trgfkfuncionariocpf = @empregado
		AND dcrVencimento = 'INSS'
		AND fkcontrachequecodcontracheque = trgFKContrachequeCodContracheque
		AND trgfkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f, contracheque as c
			WHERE v.dcrVencimento = 'INSS' 
				AND trgfkfuncionariocpf = v.fkfuncionariocpf 
				AND f.cpf = v.fkfuncionariocpf
				AND v.fkcontrachequecodcontracheque = c.codcontracheque);

	UPDATE vencimento 
	SET valor = ((@receitas * 6) / 100)
	WHERE trgfkfuncionariocpf = @empregado
		AND dcrVencimento = 'VALE TRANSPORTE'
		AND fkcontrachequecodcontracheque = trgFKContrachequeCodContracheque
		AND trgfkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f, contracheque as c
			WHERE v.dcrVencimento = 'VALE TRANSPORTE'
				AND trgfkfuncionariocpf = v.fkfuncionariocpf 
				AND f.cpf = v.fkfuncionariocpf
				AND v.fkcontrachequecodcontracheque = c.codcontracheque);

	UPDATE vencimento 
	SET valor = ((@receitas * 2) / 100)
	WHERE trgfkfuncionariocpf = @empregado
		AND dcrVencimento = 'CONVÊNIO'
		AND fkcontrachequecodcontracheque = trgFKContrachequeCodContracheque
		AND trgfkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f, contracheque as c
			WHERE v.dcrVencimento = 'CONVÊNIO' 
				AND trgfkfuncionariocpf = v.fkfuncionariocpf 
				AND f.cpf = v.fkfuncionariocpf
				AND v.fkcontrachequecodcontracheque = c.codcontracheque);

	UPDATE vencimento 
	SET valor = ((@receitas * 30) / 100)
	WHERE trgfkfuncionariocpf = @empregado
		AND dcrVencimento = 'ADIANTAMENTO QUINZENAL'
		AND fkcontrachequecodcontracheque = trgFKContrachequeCodContracheque
		AND trgfkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f, contracheque as c
			WHERE v.dcrVencimento = 'ADIANTAMENTO QUINZENAL' 
				AND trgfkfuncionariocpf = v.fkfuncionariocpf 
				AND f.cpf = v.fkfuncionariocpf
				AND v.fkcontrachequecodcontracheque = c.codcontracheque);

	UPDATE vencimento 
	SET valor = ((@receitas * 3.33) / 100)
	WHERE trgfkfuncionariocpf = @empregado
		AND dcrVencimento = 'CONTIBUIÇÃO SINDICAL'
		AND fkcontrachequecodcontracheque = trgFKContrachequeCodContracheque
		AND trgfkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f, contracheque as c
			WHERE v.dcrVencimento = 'CONTIBUIÇÃO SINDICAL' 
				AND trgfkfuncionariocpf = v.fkfuncionariocpf 
				AND f.cpf = v.fkfuncionariocpf
				AND v.fkcontrachequecodcontracheque = c.codcontracheque);
END //
DELIMITER ;

CALL calculaDesconto(1, 'RECEITA', 1, '77209625755');