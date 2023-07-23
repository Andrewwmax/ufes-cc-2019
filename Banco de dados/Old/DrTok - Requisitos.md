# Simples Levantamento de Requisitos
## Para DrTok
Versão 1.6
Preparado por André, Guilherme, Igor, Rafael
UFES
23/10/2019

Sumário
=================
* [Histórico de revisões](#histórico-de-revisões)
* [Introdução](#1-introdução)
  * 1.1 [Finalidade do documento](#11-finalidade-do-documento)
  * 1.2 [Escopo do produto](#12-escopo-do-produto)
  * 1.3 [Referências](#13-referências)
  * 1.4 [Visão geral](#14-visão-geral)
* [Descrição geral](#2-descrição-geral)
  * 2.1 [Funções do produto](#21-product-functions)
  * 2.2 [Características do usuário](#22-características-do-usuário)
* [Requisitos](#3-requisitos)
* 3.1 [Interfaces de hardware](#31-hardware-interfaces)
* 3.2 [Interfaces de software](#32-interfaces-de-software)

## Histórico de Revisão
|  Nome  |    Data    | 			Motivo p/ alterações 		| Versão |
|:------:|:----------:|:---------------------------------------:|:------:|
| André  | 23/10/2019 |				Criação do arquivo			|   1.0  |
| André  | 26/10/2019 |				Adição de descrições    	|   1.1  |
| André  | 29/10/2019 | 	Adição de Requisitos funcionais 	|   1.2  |
| André  | 31/10/2019 | 			  Correções gerais  		|   1.3  |
| André  | 06/11/2019 |  		Mudança de alguns requisitos  	|   1.3  |
| André  | 16/11/2019 | Modificações/atualização de requisitos 	|   1.5  |
| André  | 23/11/2019 | 		   Limpeza e organização 		|   1.6  |

## 1. Introdução
Vamos apresentar um simples definição, análise e especificação de requisitos de uma empresa de terceirização de serviços de limpeza. Para permitindo gerenciar as questões de contratação do serviço (empresa-contratante), informações relacionadas aos funcionários (dados pessoais e alocação de trabalho) e estoque de produtos e materiais de limpeza.*

### 1.1 Objetivo do documento
O foco principal deste documento é o desenvolvimento de informações inerentes ao banco de dados, levando em consideração que estamos desenvolvendo este trabalho para a disciplina de banco de dados, então alguns requisitos estarão superficialmente desenvolvidos para preencher com profundidade suficiente, para focalizar no objetivo da disciplina.

### 1.2 Escopo do produto
O sistema a ser desenvolvido é a base da empresa DrTok, que atua no ramo de terceirização de limpeza, o sistema fará a gerência de seus funcionários e suas distinções, juntamente com o controle de estoque e a organização dos contratos com seus clientes. Todos estes recursos, são de extrema importância para o funcionamento da empresa, onde temos a presença de cerca de trezentos funcionários, ou seja, é de grande importância a gestão de cada setor da empresa.

### 1.3 Referências
[Catálogo de base dos produtos](https://www.comercialdesafio.com.br/wp-content/uploads/2017/12/Cat%C3%A1logo-Oficial-Comercial-Desafio-1.pdf)

### 1.4 Visão geral
Generalizando a pesquisa de produção do sistema, vamos desenvolver simplificadamente os requisitos para a construção parcial do software de gestão da empresa, focando principalmente nas modelagens que são necessárias para a manipulação do banco de dados.

___
## 2. Descrição geral
Esta seção do SRS deve descrever os fatores gerais que afetam o produto e seus requisitos. Esta seção não indica requisitos específicos. Em vez disso, fornece um plano de fundo para esses requisitos, que são definidos em detalhes na Seção 3 da SRS, e os torna mais fáceis de entender.

Na 1ª reunião, foi discutido abertamente o funcionamento da empresa e suas necessidades, levando o método de brainstorming como escolhido, por ser mais dinâmico e recebendo opiniões diferentes com mais rapidez, assim ajudando na evolução da pesquisa dos requisitos.
Após toda a discussão, obtivemos alguns pontos, que foram identificados, analisados e escolhidos como base para o sistema, são eles:
- Funcionário Administrativo
- Funcionário Externo
- Salario
- Contra Cheque
- Aloca
- Estoque
- Serviço
- Fornecedor
- Entrega
- Cliente
- Contrato
- Produto

Na seção 3 iremos aprofundar à cada requisito identificado, citado acima.

### 2.2 Funções do produto
Em resumo, algumas das funcionalidades que devem estar presentes no sistema.

- Gerenciamento de contratos
	+ Gravando detalhes do Cliente
	+ Atualização do registro com contrato
	+ Impressão de despesas
	+ Renovação de contrato

- Sistema de gerenciamento de funcionários e salários
	+ Atendimento e horário dos funcionários
	+ Aprovações de férias
	+ Horário de trabalho
	+ Cálculo impostos

- Gerenciamento de Estoque
	+ Gerenciamento de estoque
	+ Notificação de vencimento
	+ Notificação de falta de produto
	+ Cálculo de faturamento
	+ Busca

- Gestão de Veículos e Transportes (**Invalidado**)
	+ Gerenciamento de vans
	+ Manuseio de implantação de veículos
	+ Gerenciamento de tempo
	+ Cálculos de faturamento

### 2.4 Características do usuário
- Administrador
	+ Gerencia todas as funções do sistema
- Gerente Comercial
	+ Gerencia as funcionalidades de contratos com clientes
- Gerente Financeiro
	+ Gerencia as funcionalidades de compra de produtos
- Gerente Recursos Humanos
	+ Gerencia as funcionalidades de funcionários
- Gerente Operacional
	+ Gerencia as funcionalidades que envolvem os serviços
- Sistema
	+ Gerencia os cálculos automáticos presentes no sistema (Preferencialmente em nível de Banco de dados)

___
## 3. Requisitos
O sistema DrTok é um sistema que deverá conter funcionalidades que atendam os funcionários, cada setor tem suas próprias funções, sendo eles Administrativo, Comercial, Financeiro, Recursos Humanos E Operacional, que ficam alocados no escritório da empresa, exceto os de nível operacional, eles são os funcionários que fazem os serviços na empresa contratante do serviço (Cliente), de um funcionário precisamos saber, Nome, CPF, Data De Nascimento, Os Vencimentos E Seu Endereço. Os vencimentos do funcionário ficam armazenados nos contracheques, que são divididos por mês. De um cliente, precisamos de CNPJ, Endereço, InscricaoEstadual, E-mail, TelefoneFixo, Celular, Nome, data de criação do cadastro (fidelidade). Cada cliente gera um contrato de serviço e precisamos armazenar as informações de descrição e preço. Para os produtos, precisamos saber seu Nome, Código de Barras, Validade e Preço, esse produto é comprado de algum fornecedor de produtos de limpeza, que precisamos saber o CNPJ, Endereço, InscricaoEstadual, E-mail, TelefoneFixo, Celular, Nome, especialidade de seus produtos e data de criação do cadastro (fidelidade). Todos os produtos ficam localizados em estoques, que podem estar espalhados por diversas cidades, precisamos saber o Nome e Endereço.

#### 3.1 Interfaces de hardware
- Notebook/Desktop PC
	+ Processador Core i3
	+ RAM 4GB
	+ HDD 500GB
	+ A proposta deste PC é para a utilização no ambiente interno da empresa, no qual todos os setores necessários para o funcionamento são afetados. Para a execução simples do sistema, precisamos de um PC razoavelmente rápido, para atender à mínima demanda, sem perda de desempenho por longos períodos, facilitado por ser um sistema implantado localmente.
- LED/LCD Monitor/TV
	+ Com o intuito das equipes ficarem sempre a par de seus próximos trabalhos, tela em pública da empresa, onde os funcionários terão acesso fácil. 
- Impressora Laser (P/B)
	+ Dispositivo para impressão de relatórios.
- Roteador Wi-Fi
	+ Dispositivo para possibilitar o acesso à internet, aos serviços do servidor de dados do sistema.

#### 3.2 Interfaces de software
- OS 			- Windows 7 ou posterior, Linux Mint ou equivalente.
- JRE 1.8 		- JAVA Runtime Environment para uma possível implementação gráfica do sistema
- MySQL server 	- Conexão com o banco de Dados.