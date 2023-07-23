
# Trabalho de Banco de Dados
## Dr. TOK - O Tok da Limpeza

Elaborar e apresentar artefatos parciais relacionados a Banco de Dados, sendo eles: Modelos de Banco de Dados Relacional (conceitual, lógico, físico) acompanhado pelo dicionário de dados, bem como scripts SQL – DML e DDL e uma carga básica de dados, a partir de uma série de situações propostas e identificadas a seguir.

*O tema proposto para o nosso trabalho envolve uma empresa de terceirização de serviços de limpeza. O SGBD a ser elaborado permite gerenciar as questões de contratação do serviço (empresa-contratante), informações relacionadas aos funcionários (dados pessoais e alocação de trabalho) e estoque de produtos e materiais de limpeza.*

#### SGBD: MySQL – não será permitido o uso de outro SGBD, devido a necessidade da professora executar os scripts elaborados;


___
## Atividades

### Atividade 1 – Especificação de Requisitos
Apresentar uma breve e simplificada especificação de requisitos do sistema que deverá ter o banco de dados projetado e implementado.

#### Levantamento de Requisitos

- Fornecedor
- Cliente
- Funcionario
- Estoque
- Servico
- Administrativo
- Externo
- Contrato
- Contrata
- Aloca
- Produto
- Entrega
- Salario
- Contra Cheque
- Recebe


#### Entidades:
- Fornecedor [**CNPJ**, nome, telefone, responsavel]
- Cliente [**CNPJ**, nome, telefone, responsavel]
- Funcionario [**CPF**, nome, telefone]
	+ Administrativo [setor]
	+ Externo [funcao]
- Endereco [**CEP**, rua, numero, complemento, bairro, cidade, estado, pais]
- Contracheque [**codContraCheque**, data, observacao]
- Receita [**codReceita**, dcrReceita, valor]
- Despesa [**codDespesa**, dcrDespesa, valor]
- Estoque [**codEstoque**, dcrEstoque, responsavel]
- Servico [**codServico**, dcrServico, preco]
- Produto [**codProduto**, dcrProduto, nome, codBarras, validade, preco]
- Contrato [**codContrato**, dcrContrato, valor, data]

#### Tipagem do BD:
{
Empresa [CNPJ char(14), Nome varchar(50), InscricaoEstadual char(9), Email varchar(150), TelefoneFixo char(12), Celular char(12)]
Fornecedor [especialidade varchar(100)] 
Cliente [fidelidade date]
Funcionario [CPF char(11), nome varchar(50), rg char(9), dataNascimento date, email varchar(100), telefone char(12)]
Interno [setor varchar(50)]
Externo [funcao varchar(150)]
Endereco [CEP int, rua varchar(50), numero int, complemento varchar(50), bairro varchar(50), cidade varchar(50), estado varchar(50), pais varchar(50)]
Contracheque [codContracheque int, data date, observacao varchar(150)]
Vencimento [codVencimento int, dcrVencimento varchar(150), tipoVencimento int, valor numeric(10,2)]
Estoque [codEstoque int, dcrEstoque varchar(150)]
Servico [codServico int, dcrServico varchar(150), preco numeric(10,2)]
Produto [codProduto int, dcrProduto varchar(150), nome varchar(150), codBarras int, validade date, preco numeric(10,2)]
Contrato [codContrato int, dcrContrato varchar(150), valor numeric(10,2), data date]
}

___
### Atividade 2 – Modelagem

####  Construir o Modelo de Entidade e Relacionamento
O MER está localizado nos arquivos do BrModelo (Mr TOk - MER (Conceitual).brm3) e imagem (Mr TOk - MER (Conceitual).png)
![MER - DrTok](https://lh3.googleusercontent.com/7i6-j_e5Qn7FOniGbWP9YWc3IlomnkXKg_VXa1mX6xOuy_cIsUs78GG5rV6YtnOwT4Xi7HtCaSED5w "MER - DrTok")

#### Construir os Modelos Relacionais (lógico e físico)
O Modelo Relacional físico está localizado nos arquivos do BrModelo (Mr TOk - MER (Físico).brm3) e imagem (Mr TOk - MER (Físico).png) 
![ML - DrTok](https://lh3.googleusercontent.com/b1C1RLS4YOAazSVAnB9EmHhi0Sopi1LXdhFX4p_oxx1Sd2RUwWL08CxJaSwcMLPdeoUY4B_jAw3hZw "ML - DrTok")


##### Dicionário de dados
Pelo menos um modelo deverá ter o dicionário de dados especificado

<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Empresa</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>CNPJ</td>
		<td>xxxxxxxx</td>
		<td>char</td>
		<td>14</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>InscricaoEstadual</td>
		<td>xxxxxxxx</td>
		<td>char</td>
		<td>9</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>Email</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>TelefoneFixo</td>
		<td>xxxxxxxx</td>
		<td>char</td>
		<td>12</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>Celular</td>
		<td>xxxxxxxx</td>
		<td>char</td>
		<td>12</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Fornecedor</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>especialidade</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>100</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Cliente</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>fidelidade</td>
		<td>xxxxxxxx</td>
		<td>date</td>
		<td></td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Funcionario</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>CPF</td>
		<td>xxxxxxxx</td>
		<td>char</td>
		<td>11</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>nome</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>rg</td>
		<td>xxxxxxxx</td>
		<td>char</td>
		<td>9</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>dataNascimento</td>
		<td>xxxxxxxx</td>
		<td>date</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>email</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>100</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>telefone</td>
		<td>xxxxxxxx</td>
		<td>char</td>
		<td>12</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Interno</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>setor</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Externo</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>funcao</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Endereco</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>CEP</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>rua</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>numero</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>complemento</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>bairro</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>cidade</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>estado</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>pais</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>50</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Contracheque</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>codContracheque</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>data</td>
		<td>xxxxxxxx</td>
		<td>date</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>observacao</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</td>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Vencimento</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>codVencimento</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>dcrVencimento</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>tipoVencimento</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>valor</td>
		<td>xxxxxxxx</td>
		<td>numeric</td>
		<td>10.2</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Estoque</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>codEstoque</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>dcrEstoque</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</td>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Servico</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>codServico</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>dcrServico</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>preco</td>
		<td>xxxxxxxx</td>
		<td>numeric</td>
		<td>10.2</td>
		<td>NOT NULL</td>
	</tr>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Produto</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>codProduto</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>dcrProduto</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>nome</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>codBarras</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>validade</td>
		<td>xxxxxxxx</td>
		<td>date</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>preco</td>
		<td>xxxxxxxx</td>
		<td>numeric</td>
		<td>10.2</td>
		<td>NOT NULL</td>
	</td>
</table>

---
<table>
	<tr>
		<th>Tabela</th>
		<th colspan="4">Contrato</th>
	</tr>
	<tr>
		<td>Descrição</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td>Observações</td>
		<td colspan="4"></td>
	</tr>
	<tr>
		<td colspan="5">Campos</td>
	</tr>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Tipo</td>
		<td>Tamanho</td>
		<td>Restrições</td>
	</tr>
	<tr>
		<td>codContrato</td>
		<td>xxxxxxxx</td>
		<td>int</td>
		<td></td>
		<td>NOT NULL</td>
	</td>
	<tr>
		<td>dcrContrato</td>
		<td>xxxxxxxx</td>
		<td>varchar</td>
		<td>150</td>
		<td>NOT NULL</td>
	</tr>
	<tr>
		<td>valor</td>
		<td>xxxxxxxx</td>
		<td>numeric</td>
		<td>10.2</td>
		<td>NOT NULL</td>
	</tr>
</table>

#### Identificar as Restrições de Integridade - AINDA PENDENTE
- Grupo interno da empresa - Funcionamento mínimo, Produtos são providos por um Fornecedor. Um contrato necessita de produtos do estoque e funcionários para serem alocados. Um Funcionário recebe Salário gerando um Contracheque.
- Grupo externo da empresa - Funcionamento Normal, Um Cliente Contrata um Serviço


___
### Atividade 3 – Scripts

#### Gerar script de criação do banco de dados: esquema, tabelas e restrições de integridade
A criação do esquema, das tabelas já com as restrições de integridade presentes do Banco de dados Dr. Tok, estão no arquivo ``DRTOK.sql``.

#### Gerar script de carga de dados para testes com o banco de dados
A carga de dados de teste está no arquivo ``Inserts.sql``

___
### Atividade 4 – Elementos de Programação

#### Selects examples
Identificar selects básicos para exemplificar o funcionamento do BD

#### Visões
Identificar partes do modelo bastante suscetíveis a consultas
Implementar pelo menos duas views para as partes do modelo
Implementar pelo menos um relatório em potencial para cada parte identificada

#### Stored Procedures
Identificar duas situações para implementação de procedures
Implementar as procedures e os casos de testes das procedures

#### Triggers
Identificar duas situações para implementação de triggers
Implementar os triggers e os casos de testes dos triggers


___
## Relatório
### Além dos artefatos acima identificados, também deverá ser entregue um relatório descrevendo a atividade executada (desde a definição do tema até a elaboração da apresentação), bem como instruções básicas para executar os scripts SQLs. Esse relatório será um relato de experiência para que a professora corrija a atividade e acompanhe o grupo;