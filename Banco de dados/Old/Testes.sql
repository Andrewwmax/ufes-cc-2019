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
SELECT f.Nome as Nome, f.funcao as Função, SUM(v.valor)
FROM vencimento as v, contracheque as c, funcionario as f
WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf AND v.tipovencimento = "RECEITA"
GROUP BY f.nome;

#### Ver as Despesas dos funcionários
SELECT f.Nome as Nome, f.funcao as Função, SUM(v.valor)
FROM vencimento as v, contracheque as c, funcionario as f
WHERE v.fkcontrachequecodcontracheque = c.codcontracheque AND v.fkfuncionariocpf = f.cpf AND v.tipovencimento = "DESCONTO"
GROUP BY f.nome;

#### Ver todos os contratos
SELECT c.codcontrato as Contrato_Nº, e.nome as Cliente, s.dcrservico as Servico, c.valor as Valor
FROM Funcionario as f, Empresa as e, contrato as c, servico as s, inclui as i
WHERE e.tipoempresa = 1 AND e.CNPJ = c.fkempresacnpj AND i.fkservicocodservico = s.codservico AND i.fkcontratocodcontrato = c.codcontrato
GROUP BY c.codcontrato;

#### Ver um funcionário alocado em um serviço
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

#### ITS A VERY AND VERY DIFICULTY { IMPUSSIBRU }
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