## Visões
### Identificar partes do modelo bastante suscetíveis a consultas
### Implementar pelo menos duas views para as partes do modelo

USE `DRTOK`;

########################################################################
# 1 A descoberta dos produtos (ou localizados em um estoque),
# utilizado para fazer um pedido de reposição de produtos no estoque

DROP VIEW IF EXISTS Suprimentos;
CREATE VIEW Suprimentos AS
	SELECT  p.codproduto as Código,
			p.nome as Nome,
			e.dcrestoque as Estoque,
			p.dcrproduto as Descrição,
			p.preco as Preço,
			p.validade as Validade
	FROM Produto as p, Estoque as e
	-- 1/2 Opcionalmente podemos modificar a linha para conseguir
	-- produtos de todos os estoques
	-- WHERE p.fkestoquecodestoque = (
	-- 		SELECT es.codestoque
	-- 		FROM estoque as es, endereco as e
	-- 		WHERE es.fkenderecocep = e.cep AND e.cidade = "colatina")
	WHERE p.fkestoquecodestoque = e.codestoque
	ORDER BY e.dcrestoque;

SELECT * FROM Suprimentos;

########################################################################
# 2 Descoberta de todos os produtos de um serviço e com a identificação do Fornecedor

DROP VIEW IF EXISTS FornecedorProdutoServico;
CREATE VIEW FornecedorProdutoServico AS
	SELECT  s.dcrServico as Serviço,
			p.codProduto as Código,
			p.nome as Produto,
			em.nome as Fornecedor
	FROM Produto as p, Entrega as e, coleta as c, servico as s, estoque as es, empresa as em
	WHERE em.cnpj = e.fkempresacnpj
		AND p.codProduto = e.FKProdutoCodProduto
		AND p.codProduto = c.fkprodutocodproduto
		AND c.fkservicocodservico = s.codServico
		AND p.fkestoquecodestoque = es.codEstoque
	ORDER BY s.codServico, em.cnpj;

SELECT * FROM FornecedorProdutoServico;

########################################################################
# 3 A descoberta de todos os clientes com contratos e os valores

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

#### Identificar todos os produtos de um serviço
SELECT * FROM FornecedorProdutoServico Where Serviço LIKE '%completa';

#### Identificar serviços que um produto está sendo usado
SELECT * FROM FornecedorProdutoServico Where Produto LIKE '%sanitária';