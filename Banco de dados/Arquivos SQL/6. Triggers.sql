## Triggers
### Identificar duas situações para implementação de triggers
### Implementar os triggers e os casos de testes dos triggers

USE `DRTOK`;

########################################################################
# Trigger que trata o caso de restrição de integridade do atributo DATA na tabela Contrato

DROP TRIGGER IF EXISTS TgrContratoVerificaData;
DELIMITER //
CREATE TRIGGER TgrContratoVerificaData
BEFORE INSERT ON contrato
FOR EACH ROW
BEGIN
	IF (CURDATE() > new.data) THEN
		SET new.data = NULL;
	END IF;
END //
DELIMITER ;


########################################################################
# Acompanha o Trigger TgrContratoVerificaData, no qual este trata
## o erro de inserção, caso a data ou outro campo esteja inválidado

DROP PROCEDURE IF EXISTS spInsereContrato;
DELIMITER //
CREATE PROCEDURE spInsereContrato ( IN spdcrContrato VARCHAR(50), 
									IN spvalor NUMERIC(10,2),
									IN spdata DATE,
									IN spFKEmpresaCNPJ CHAR(14))
BEGIN
	DECLARE EXIT HANDLER FOR SQLSTATE '23000'
	BEGIN
		SELECT 'Problemas com a inserção data, Data anterior à hoje!' as ERRO;
	END;
	
	INSERT INTO Contrato (dcrContrato, valor, data, FKEmpresaCNPJ) VALUES
		(spdcrContrato, spvalor, spdata, spFKEmpresaCNPJ);
	
END//
DELIMITER ;

#### Caso de teste para o TgrContratoVerificaData e spInsereContrato.

CALL spInsereContrato('MasterClean SupremeShine', 1432.22, '2019-11-30', '80367007000185');


########################################################################
# Pré Teste sobre a exclusão do Funcionario, que ainda não é permitida
# DELETE FROM funcionario WHERE cpf = '48074582728';
# Trigger para possibilitar a exclusão de um funcionario, que retira-o de todos
# os demais registros

DROP TRIGGER IF EXISTS TgrFuncionarioExcluido;
DELIMITER //
CREATE TRIGGER TgrFuncionarioExcluido
BEFORE DELETE ON funcionario
FOR EACH ROW
BEGIN
	-- SELECT v.codvencimento as Cod
	-- FROM vencimento as v, funcionario as f
	-- WHERE v.fkfuncionariocpf = '77209625755' AND v.fkfuncionariocpf = f.cpf;
	DELETE FROM vencimento WHERE FKFuncionarioCPF = old.cpf;
	
	-- SELECT c.codcontracheque as Cod 
	-- FROM contracheque as c, funcionario as f 
	-- WHERE c.fkfuncionariocpf = '77209625755' AND c.fkfuncionariocpf = f.cpf;
	DELETE FROM contracheque WHERE FKFuncionarioCPF = old.cpf;

END //
DELIMITER ;

# Teste TgrFuncionarioExcluido
DELETE FROM funcionario WHERE cpf = '48074582728';


########################################################################
# Encapsulamento, para tratar o erro da Constraint

DROP PROCEDURE IF EXISTS spDeleteFuncionario;
DELIMITER //
CREATE PROCEDURE spDeleteFuncionario ( IN trgcpf CHAR(11))
BEGIN
	DECLARE EXIT HANDLER FOR SQLSTATE '23000'
	BEGIN
		SELECT 'Problemas com a inserção data, Data anterior à hoje!' as ERRO;
	END;
	
	DELETE FROM funcionario WHERE cpf = trgcpf;
	
	SELECT 'Excluido com Sucesso!' AS MSG;
END//
DELIMITER ;

CALL spDeleteFuncionario('48074582728');


########################################################################
# Pré Teste sobre a exclusão do Produto, que ainda não é permitida
# DELETE FROM produto WHERE codProduto = 1;
# Trigger para possibilitar a exclusão de um produto, que retira-o de todos
# os demais registros

DROP TRIGGER IF EXISTS TgrProdutoExcluido;
DELIMITER //
CREATE TRIGGER TgrProdutoExcluido
BEFORE DELETE ON Produto
FOR EACH ROW
BEGIN

	DELETE FROM coleta WHERE fkprodutocodproduto = old.codProduto;
	DELETE FROM entrega WHERE fkprodutocodproduto = old.codProduto;

END //
DELIMITER ;

DELETE FROM produto WHERE codProduto = 1;