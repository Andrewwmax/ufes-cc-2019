
# Atividade 4 – Elementos de Programação

USE `DRTOK`;
## Teste de construção
DESCRIBE Endereco;
DESCRIBE Funcionario;
DESCRIBE Estoque;
DESCRIBE Servico;
DESCRIBE Produto;
DESCRIBE Contracheque;
DESCRIBE Vencimento;
DESCRIBE Empresa;
DESCRIBE Contrato;
DESCRIBE Aloca;
DESCRIBE Entrega;
DESCRIBE Coleta;
DESCRIBE Inclui;

## Exemplos de Selects
### Identificar selects básicos para exemplificar o funcionamento do BD
#### Ver todos os funcionários de uma mesma cidade
SELECT f.nome as Nome, e.cep as CEP, e.rua as Rua, e.cidade as Cidade
FROM Funcionario as f, Endereco as e
WHERE e.cep = f.FKenderecocep AND e.cidade = "Colatina"
ORDER BY f.nome;

#### Ver o endereço dos Estoques
SELECT es.dcrestoque as Estoque, e.cep as CEP, e.rua as Rua, e.cidade as Cidade
FROM Estoque as es, Endereco as e
WHERE e.cep = es.FKenderecocep
ORDER BY e.cidade;

#### Ver todos os Funcionários que são analistas
SELECT f.nome as Nome, f.setor as Setor, f.funcao as Função 
FROM Funcionario as f
WHERE f.funcao = "analista"
ORDER BY f.setor;

#### Ver todos os produtos de um estoque de uma cidade 
SELECT p.codproduto as Código, p.nome as Nome, p.dcrproduto as Descrição, p.preco as Preço
FROM Produto as p, Estoque as e
WHERE p.fkestoquecodestoque = (SELECT es.codestoque from estoque as es, endereco as e where es.fkenderecocep = e.cep AND e.cidade = "colatina")
GROUP BY p.codproduto
ORDER BY p.preco;

#### Ver as Receitas dos funcionários
SELECT f.cpf as CPF, f.Nome as Nome, f.funcao as Função, SUM(v.valor)
FROM vencimento as v, contracheque as c, funcionario as f
WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf AND v.tipovencimento = "RECEITA"
GROUP BY f.nome;

#### Ver as imposto dos funcionários
SELECT f.cpf as CPF, f.Nome as Nome, f.funcao as Função, SUM(v.valor)
FROM vencimento as v, contracheque as c, funcionario as f
WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf AND v.tipovencimento = "DESCONTO"
GROUP BY f.nome;

#### Ver todos os contratos
SELECT c.codcontrato as Contrato_Nº, e.nome as Cliente, s.dcrservico as Servico, c.valor as Valor
FROM Funcionario as f, Empresa as e, contrato as c, servico as s, inclui as i
WHERE e.tipoempresa = 1 AND e.CNPJ = c.fkempresacnpj AND i.fkservicocodservico = s.codservico AND i.fkcontratocodcontrato = c.codcontrato
GROUP BY c.codcontrato;

#### Ver um funcionário e seus serviços
SELECT f.nome as Funcionário, s.dcrservico as Serviço
FROM Funcionario as f, Servico as s, Aloca as a
WHERE f.cpf = (
	SELECT cpf from funcionario where nome = "Stella Aline da Paz") 
	AND s.codservico = a.fkservicocodservico
GROUP BY s.dcrservico;

#### Ver funcionários alocados em um serviço
SELECT f.nome as Funcionário, s.dcrservico as Serviço
FROM Funcionario as f, Servico as s, Aloca as a
WHERE f.cpf = a.fkfuncionariocpf AND s.codservico = a.fkservicocodservico AND s.codservico = (
	SELECT codservico from servico where dcrservico = "Faxina completa")
GROUP BY f.nome;

#### Ver os funcionários alocados em um serviço de um contrato
SELECT c.codcontrato as Contrato_Nº, e.nome as Empresa, s.dcrservico as Serviço, f.nome as Funcionário
FROM Funcionario as f, Servico as s, Aloca as a, contrato as c, empresa as e, inclui as i
WHERE f.cpf = a.fkfuncionariocpf AND s.codservico = a.fkservicocodservico AND s.codservico = (
	SELECT codservico from servico where dcrservico = "Faxina completa"
	) AND c.codcontrato = i.fkcontratocodcontrato AND e.cnpj = (
	SELECT cnpj from empresa where nome = "Renan e Rebeca Assessoria Jurídica ME")
GROUP BY f.nome;

#### Ver os produtos entregues por um fornecedor
SELECT e.nome as Fornecedor, p.nome as Produto
FROM Empresa as e, Produto as p, Entrega as t
WHERE e.cnpj = (
	SELECT cnpj from empresa where nome = "Luciana e Kamilly Transportes ME") 
	AND e.cnpj = t.fkempresacnpj
	AND p.codproduto = t.fkprodutocodproduto
ORDER BY e.cnpj;

#### ITS A VERY AND VERY DIFICULTY { IMPUSSIBRU } Everything with procedures
#SET @idPedidos = (SELECT COUNT(cpf) from funcionario);
#SELECT MONTH(c.data) as Mês, f.nome as Funcionario, SUM((
#	SELECT SUM(v.valor)
#	FROM vencimento as v, contracheque as c, funcionario as f
#	WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf AND v.tipovencimento = "RECEITA"
#	GROUP BY f.nome
#	) - (SELECT SUM(v.valor)
#	FROM vencimento as v, contracheque as c, funcionario as f
#	WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf AND v.tipovencimento = "DESCONTO"
#	GROUP BY f.nome
#	))
#FROM contracheque as c, Funcionario as f
#GROUP BY f.nome;


## Visões
### Identificar partes do modelo bastante suscetíveis a consultas
### Implementar pelo menos duas views para as partes do modelo
# 1 A descoberta dos produtos (ou localizados em um estoque), utilizado para fazer um pedido de reposição de produtos no estoque
DROP VIEW IF EXISTS Suprimentos;
CREATE VIEW Suprimentos AS
SELECT p.codproduto as Código, p.nome as Nome, e.dcrestoque as Estoque, p.dcrproduto as Descrição, p.preco as Preço, p.validade as Validade
FROM Produto as p, Estoque as e
# 1/5 Opcionalmente podemos modificar a linha para conseguir produtos de todos os estoques
# WHERE p.fkestoquecodestoque = (SELECT es.codestoque from estoque as es, endereco as e where es.fkenderecocep = e.cep AND e.cidade = "colatina")
WHERE p.fkestoquecodestoque = e.codestoque
ORDER BY e.dcrestoque;

SELECT * FROM Suprimentos;

# 2 A descoberta de todos os clientes com contratos e os valores
DROP VIEW IF EXISTS HistoricoCliente;
CREATE VIEW HistoricoCliente AS
SELECT c.codcontrato as Contrato_Nº, e.CNPJ as CNPJ, e.nome as Cliente, s.dcrservico as Serviço, c.valor as Valor
FROM Funcionario as f, Empresa as e, contrato as c, servico as s, inclui as i
WHERE e.tipoempresa = 1 AND e.CNPJ = c.fkempresacnpj AND i.fkservicocodservico = s.codservico AND i.fkcontratocodcontrato = c.codcontrato
GROUP BY c.codcontrato;

SELECT * FROM HistoricoCliente;

### Implementar pelo menos um relatório em potencial para cada parte identificada
#### Identificar o valor do Contrato mais rentável, para possibilitar negociações de novos e futuros contratos
SELECT Cliente, valor as Contrato_Mais_Rentável FROM HistoricoCliente WHERE valor = (SELECT MAX(valor) FROM HistoricoCliente);

#### Identificar o valor do Contrato mais simples, para possibilitar negociações de inclusão de serviços nos novos contratos
SELECT Cliente, valor as Contrato_Mais_Simples FROM HistoricoCliente WHERE valor = (SELECT MIN(valor) FROM HistoricoCliente);

#### Identificar o valor médio dos Contratos, para analisar a rotatividade de crédito ou lucros dos contratos
SELECT AVG(valor) as Contrato_Médio FROM HistoricoCliente;

#### Identificar todos produtos próximos ao vencimento (1 ano)
SELECT Código, Estoque, Nome, Validade FROM Suprimentos WHERE validade < "2020-12-03";


## Stored Procedures
### Identificar duas situações para implementação de procedures
### Implementar as procedures e os casos de testes das procedures

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
					WHERE nome = nomeFuncionario)
			AND v.tipovencimento = 'RECEITA'
		) - (SELECT SUM(v.valor)
			FROM vencimento as v, contracheque as c, funcionario as f
			WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf
			AND f.cpf = (
				SELECT cpf
				FROM Funcionario
				WHERE nome = nomeFuncionario) AND v.tipovencimento = 'DESCONTO'
		)) 
		as Pagamento
	FROM vencimento as v, contracheque as c, funcionario as f
	WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf
	AND f.cpf = (
		SELECT cpf 
		FROM Funcionario
		WHERE nome = nomeFuncionario)
	GROUP BY f.nome;
END // 
DELIMITER ;

CALL Pagamento('Cláudio Thales da Mota');

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


DROP PROCEDURE IF EXISTS duplicarTgrCalculaDesconto;
DELIMITER //
CREATE PROCEDURE duplicarTgrCalculaDesconto ()
BEGIN
	CREATE TABLE newVencimento AS SELECT * FROM vencimento;
	ALTER TABLE newVencimento CHANGE codVencimento newcodVencimento INT;
	ALTER TABLE newVencimento CHANGE FKContrachequeCodContracheque FKnewContrachequeCodContracheque INT;
	ALTER TABLE newVencimento CHANGE FKFuncionarioCPF FKnewFuncionarioCPF CHAR(11);
	ALTER TABLE newVencimento ADD PRIMARY KEY (newcodVencimento);
	ALTER TABLE newVencimento ADD CONSTRAINT FKnewVencimentoContraCheque FOREIGN KEY (FKnewContrachequeCodContracheque) REFERENCES Contracheque (codContracheque) ON DELETE RESTRICT ON UPDATE RESTRICT;
	ALTER TABLE newVencimento ADD CONSTRAINT FKnewVencimentoFuncionario FOREIGN KEY (FKnewFuncionarioCPF) REFERENCES Funcionario (CPF) ON DELETE RESTRICT ON UPDATE RESTRICT;
END //
DELIMITER ;

CALL duplicarTgrCalculaDesconto();


DROP PROCEDURE IF EXISTS deletarTgrCalculaDesconto;
DELIMITER //
CREATE PROCEDURE deletarTgrCalculaDesconto ()
BEGIN
	DROP TABLE IF EXISTS newVencimento;
END //
DELIMITER ;

CALL deletarTgrCalculaDesconto();


## Triggers
### Identificar duas situações para implementação de triggers
### Implementar os triggers e os casos de testes dos triggers

DROP TRIGGER IF EXISTS TgrCalculaDesconto;
DELIMITER //
CREATE TRIGGER TgrCalculaDesconto
AFTER INSERT ON vencimento
FOR EACH ROW
BEGIN		

	#### FAZER UMA FUNCAO PRA ESSA
	CALL duplicarTgrCalculaDesconto();

	DECLARE rowcount INT;
    
    SELECT COUNT(*) INTO rowcount
    FROM newVencimento as v, contracheque as c, funcionario as f
	WHERE 	v.fkcontrachequecodcontracheque = c.codcontracheque AND
			v.fkfuncionariocpf = f.cpf AND
			v.tipovencimento = 'RECEITA' AND f.cpf = new.fkfuncionariocpf;
    
    IF rowcount > 0 THEN
	
		SET @receitas = 0, @imposto = 0, @empregado = 0;
		SET @receitas = (
			SELECT SUM(v.valor)
			FROM newVencimento as v, contracheque as c, funcionario as f
			WHERE 	v.fkcontrachequecodcontracheque = c.codcontracheque AND
					v.fkfuncionariocpf = f.cpf AND
					v.tipovencimento = 'RECEITA' AND f.cpf = new.fkfuncionariocpf
		);

		IF @receitas < 1751.82 THEN 
			SET @imposto = 8;
		ELSEIF @receitas > 1751.81 AND @receitas < 2919.73 THEN
			SET @imposto = 9;
		ELSEIF @receitas > 2919.72 AND @receitas < 5839.46 THEN
			SET @imposto = 11;
		ELSE
			SET @imposto = 11;
		END IF;

		CALL buscaFuncionario(new.fkfuncionariocpf, @empregado);
		
		UPDATE vencimento 
		SET valor = ((@receitas * @imposto) / 100)
		WHERE new.fkfuncionariocpf = @empregado AND new.fkfuncionariocpf = (
			SELECT f.cpf
			FROM newVencimento as v, funcionario as f 
			WHERE v.dcrVencimento = 'INSS' AND f.cpf = v.fkfuncionariocpf);

		UPDATE vencimento 
		SET valor = ((@receitas * 6) / 100)
		WHERE new.fkfuncionariocpf = @empregado AND new.fkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f 
			WHERE v.dcrVencimento = 'VALE TRANSPORTE' AND f.cpf = v.fkfuncionariocpf);

		UPDATE vencimento 
		SET valor = ((@receitas * 2) / 100)
		WHERE new.fkfuncionariocpf = @empregado AND new.fkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f 
			WHERE v.dcrVencimento = 'CONVÊNIO' AND f.cpf = v.fkfuncionariocpf);

		UPDATE vencimento 
		SET valor = ((@receitas * 30) / 100)
		WHERE new.fkfuncionariocpf = @empregado AND new.fkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f 
			WHERE v.dcrVencimento = 'ADIANTAMENTO QUINZENAL' AND f.cpf = v.fkfuncionariocpf);

		UPDATE vencimento 
		SET valor = ((@receitas * 3.33) / 100)
		WHERE new.fkfuncionariocpf = @empregado AND new.fkfuncionariocpf = (
			SELECT f.cpf
			FROM vencimento as v, funcionario as f 
			WHERE v.dcrVencimento = 'CONTIBUIÇÃO SINDICAL' AND f.cpf = v.fkfuncionariocpf);
	END IF;
	
	CALL deletarTgrCalculaDesconto();

END //
DELIMITER ;
	
INSERT INTO Funcionario (CPF, nome, rg, dataNascimento, email, telefone, funcao, setor, tipoFuncionario, FKEnderecoCEP) VALUES
	("59059947762", "Márcia Luiza Josefa Rodrigues", "497772991", "1999-04-22", "mmarcialuizajosefarodrigues@publifix.com.br", "27987354954",  "FAXINEIRO", "OPERACIONAL", 2, 29221270),
	("78613999786", "Marina Natália Maria da Mata", "336118016", "1959-11-19", "mmarinanataliamariadamata@wizardsjc.com.br", "27981537296",  "FAXINEIRO", "OPERACIONAL", 2, 29045453);

INSERT INTO Contracheque (data, observacao, FKFuncionarioCPF) VALUES
	("2019-12-01", "***", "59059947762"),
	("2019-12-01", "***", "78613999786");

INSERT INTO Vencimento (dcrVencimento, valor, tipoVencimento, FKContrachequeCodContracheque, FKFuncionarioCPF) VALUES
	("SALÁRIO BASE", 1401.24, "RECEITA", 301, "59059947762"),
	("SALÁRIO FAMÍLIA", 922.76, "RECEITA", 301, "59059947762"),
	("FÉRIAS", 497.12, "RECEITA", 301, "59059947762"),
	("GRATIFICAÇÃO", 312.50, "RECEITA", 301, "59059947762"),
	("BONIFICAÇÃO", 459.55, "RECEITA", 301, "59059947762"),
	("HORAS EXTRAS", 323.87, "RECEITA", 301, "59059947762"),
	("ADICIONAL INSALUBRIDADE", 922.98, "RECEITA", 301, "59059947762"),
	("ADICIONAL NOTURNO", 986.84, "RECEITA", 301, "59059947762"),
	("ADICIONAL PONTUALIDADE", 257.90, "RECEITA", 301, "59059947762"),
	("AUXILIO ALIMENTAÇÃO", 318.28, "RECEITA", 301, "59059947762"),
	("FALTAS", 884.45, "DESCONTO", 301, "59059947762"),
	("INSS", 194.16, "DESCONTO", 301, "59059947762"),
	("VALE TRANSPORTE", 985.60, "DESCONTO", 301, "59059947762"),
	("CONVÊNIO", 730.23, "DESCONTO", 301, "59059947762"),
	("ADIANTAMENTO QUINZENAL", 468.15, "DESCONTO", 301, "59059947762"),
	("CONTIBUIÇÃO SINDICAL", 360.85, "DESCONTO", 301, "59059947762"),
	
	("SALÁRIO BASE", 5939.04, "RECEITA", 302, "78613999786"),
	("SALÁRIO FAMÍLIA", 716.72, "RECEITA", 302, "78613999786"),
	("FÉRIAS", 423.88, "RECEITA", 302, "78613999786"),
	("GRATIFICAÇÃO", 789.74, "RECEITA", 302, "78613999786"),
	("BONIFICAÇÃO", 830.18, "RECEITA", 302, "78613999786"),
	("HORAS EXTRAS", 913.94, "RECEITA", 302, "78613999786"),
	("ADICIONAL INSALUBRIDADE", 183.85, "RECEITA", 302, "78613999786"),
	("ADICIONAL NOTURNO", 705.46, "RECEITA", 302, "78613999786"),
	("ADICIONAL PONTUALIDADE", 384.64, "RECEITA", 302, "78613999786"),
	("AUXILIO ALIMENTAÇÃO", 582.49, "RECEITA", 302, "78613999786"),
	("FALTAS", 551.48, "DESCONTO", 302, "78613999786"),
	("INSS", 582.44, "DESCONTO", 302, "78613999786"),
	("VALE TRANSPORTE", 809.42, "DESCONTO", 302, "78613999786"),
	("CONVÊNIO", 639.70, "DESCONTO", 302, "78613999786"),
	("ADIANTAMENTO QUINZENAL", 995.31, "DESCONTO", 302, "78613999786"),
	("CONTIBUIÇÃO SINDICAL", 158.04, "DESCONTO", 302, "78613999786");

CALL Pagamento('Márcia Luiza Josefa Rodrigues');

UPDATE vencimento 
SET valor = ((@receitas * @imposto) / 100)
WHERE fkfuncionariocpf = '78613999786' AND dcrvencimento = 'INSS';

CALL Pagamento('Márcia Luiza Josefa Rodrigues');
