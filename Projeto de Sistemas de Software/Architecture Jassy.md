# Projeto de Arquitetura
### JASSY


## 1. Introdução
Este documento fornece uma visão geral de alto nível e explica a arquitetura do Jassy (Just Another Student System for You).

Definindo metas da arquitetura, os casos de uso suportados pelo sistema, estilos e componentes arquitetônicos que foram selecionados. O documento fornece uma base racional para a arquitetura e design decisões tomadas a partir da ideia conceitual para a sua implementação. Complementando a Definição das tecnologias que serão utilizadas, como Apache, Mysql, PHP, Javascript, Python, Bootstrap, HTML5, CSS, Node.js. Assim desenvolvendo o Backend que será utilizado em PHP, envolvendo as operações de requisições web, juntamente com a parte gráfica e as interfaces com o usuário.

### 1.1 Finalidade
``[Esta seção define a finalidade do Documento de Projeto de Software, na documentação geral do projeto, e contém uma breve descrição da estrutura do documento.]``


Este documento apresenta uma View geral abrangente da arquitetura do sistema e utiliza uma série de visões arquiteturais diferentes para ilustrar os diversos aspectos do sistema. Sua intenção é capturar e transmitir as decisões significativas do ponto de vista da arquitetura que foram tomadas em relação ao sistema.

Para representar o software com a maior precisão, a estrutura deste documento é baseada na visualização do modelo "4 + 1" de [Philippe Kruchten], este modelo de exibição “4 + 1” permite que várias partes interessadas contribuam na arquitetura de software.

``[Os públicos específicos do documento devem ser identificados, com uma indicação de como devem usá-lo.]``


Os 4 grupos de interesse, que são:
- Lógica
- Implantação
- Processos
- Dados
- Além dos Casos de Uso, que abrangem todos os grupos em um nível estrutural.

Desse modo temos uma conexão entre todos os elementos necessários para a base sólida do Software, sendo pontos principais, Estrutural, Componentes, Escalabilidade, Topologia, Implantação, Comunicação.

### 1.2 Escopo
``[Faça uma breve descrição da aplicação do Documento de Projeto de Software;]``

O escopo deste documento é explicar a arquitetura do sistema JASSY, que é focado em integração dos sistemas de um ambiente escolar, sendo relevantes, mais propriamente ditos, nas bases do documento de Engenharia de Requisitos.

``[o que é afetado ou influenciado por este documento.]``

Este documento descreve os vários aspectos do design do sistema JASSY que são considerados relevantes para a construção da arquitetura. Esses elementos e comportamentos são fundamentais para orientar a construção do sistema e para entender esse projeto como um todo. As partes interessadas que requerem um entendimento técnico do sistema são incentivadas a começar lendo os documentos de Proposta, Conceito de Operações e Especificação de Requisitos de Software desenvolvidos para este sistema [SRS].

### 1.3 Definições, Acrônimos e Abreviações
``[Esta subseção deve apresentar as definições de todos os termos, acrônimos e abreviações necessários para a correta interpretação do Documento de Projeto de Software. Essas informações podem ser fornecidas mediante referência ao Glossário do projeto.]``

- Apache - Servidor Web
- HTTP - Protocolo de transferência de hipertexto
- WWW - World Wide Web
- SAD - Documento de Arquitetura de Software
- UML - Linguagem de Modelagem Unificada
- Usuário - qualquer usuário registrado no site do JASSY
- Mysql - Banco de Dados Utilizado
- PHP - Linguagem de programação no Backend
- Javascript - Linguagem de programação iterativa em ambiente Web
- Python - Linguagem de programação complementar utilizada no Backend (Funcionalidades)
- CSS - Biblioteca de funcionalidades para estilo de Web Design
- Bootstrap - Complemento do CSS
- HTML5 - Linguagem para construção de páginas Web


### 1.4 Referências
``[Esta subseção deve apresentar uma lista completa de todos os documentos mencionados no Documento de Projeto de Software. Cada documento deve ser identificado por título, número de relatório (se aplicável), data e organização responsável pela publicação. Especifique as fontes das quais é possível obter referências. Essas informações podem ser fornecidas por um anexo ou outro documento.]``

[PP]: Proposta de projeto
[SPMP]: Plano de gerenciamento de projetos de software
[SRS]: Especificação de Requisitos de Software

### 1.5 Visão Geral
``[Esta subseção deve descrever o conteúdo restante do Documento de Projeto de Software e explicar como o Documento de Projeto de Software está organizado.]``

Para documentar completamente todos os aspectos da arquitetura, o Documento de Arquitetura de Software contém as seguintes subseções.
- Seção 2: Descreve o uso de cada View, ou seja, cada grupo de interesse
- Seção 3: Descreve os objetivos e restrições de arquitetura do projeto do sistema
- Seção 4: Descreve as realizações de casos de uso
- Seção 5: Descreve a View lógica do sistema, com definições de interface e operação.
- Seção 6: Descreve elementos significativos de persistência.
- Seção 7: Descreve como o sistema será implantado.


## 2. Representação da Arquitetura
``[Esta seção descreve qual é a arquitetura de software do sistema atual e como ela é representada. Nas Visões de Casos de Uso, Lógica, do Processo, de Implantação e de Implementação, este documento enumera as visões necessárias e, para cada uma delas, explica os tipos de elementos do modelo que contém.]``

Este documento detalha a arquitetura usando as visualizações definidas no modelo "4 + 1" [Kruchten]. As visualizações usadas para documentar o sistema DMM são:

**View de Caso de Uso**
*Público-alvo:* Todas as partes interessadas do sistema, incluindo os usuários finais.
*Área:* Descreve o conjunto de cenários ou casos de uso que representam alguma funcionalidade identificada durante a análise do levantamento do sistema. Descreve os atores e os casos de uso do sistema; Essa View apresenta as necessidades do usuário e é elaborada mais detalhadamente no nível do design para descrever fluxos e restrições simples com mais detalhes. Esse vocabulário de domínio é independente de qualquer modelo de processamento ou sintaxe representacional.
*Artefatos relacionados:* Modelo de Caso de Uso, Documentos de Caso de Uso

**View lógica**
*Público:* Designers.
*Área:* Requisitos funcionais - Descreve o modelo de objeto do Design. Também descreve as realizações de casos de uso mais importantes e os requisitos de negócios do sistema.
*Artefatos relacionados:* Modelo de Design

**View de dados**
*Público:* Especialistas em dados, administradores de banco de dados
*Área:* Persistência - Descreve os elementos persistentes significativos da arquitetura no Modelo de Dados, bem como os dados que são manipulados pelo sistema, os sistemas de dados, banco de dados e estruturas utilizadas pelo sistema.
*Artefatos relacionados:* Modelo de Dados.

**View de implantação**
*Público:* Gerentes de implantação.
*Área:* Topologia - Descreve o mapeamento do software no hardware e mostra os aspectos distribuídos do sistema. Descreve os modelos de implantação que são possíveis, incluindo cenários de implantação conhecidos e previstos na arquitetura, permitindo que os implementadores entendam e tenham margem para manobra fazendo certas suposições sobre o desempenho da rede, a interação do sistema e funcionamento geral do sistema.
*Artefatos relacionados:* Modelo de Implementação.



## 3. Metas e Restrições de Arquitetura
``[Esta seção descreve os requisitos de software e os objetivos que têm um impacto significativo na arquitetura]``

Existem alguns requisitos principais e restrições de sistema que têm uma influência significativa na arquitetura. Eles são:

- O sistema é uma prova de conceito para que o projeto em real e todas as suas necessidades sejam atendidas, bem como a previsão para um projeto mais completo seja construído no futuro. Portanto, uma das principais partes interessadas neste documento e no sistema como um todo são arquitetos e designers que agregará o conceito de manutenibilidade. Como resultado, um objetivo deste documento é ser útil para futuras manutenções e ampliações, e logicamente para o acompanhamento da equipe para a construção bem organizada das primeiras versões.

- O sistema será escrito usando as tecnologias PHP, Javascript e Python, mas utilizará um sistema SGBD de código aberto (MySQL) para persistência dos dados e será implantado em um servidor Web Linux executando Apache. Esses requisitos não estruturais de implantação requerem algumas considerações consideravelmente relevantes para o desenvolvimento da arquitetura.

- O sistema deve se comunicar com outros sistemas, possibilitando a integração com o sistema interno da UFES para garantir a integração de dados. Definir como o sistema faz interface com esse sistema é uma das preocupações principais da arquitetura.

- O documento de Especificação de Requisitos de Software descreve várias alterações antecipadas que o aplicativo pode enfrentar com o tempo. Um dos principais objetivos da arquitetura do sistema é minimizar o impacto dessas alterações, reduzindo a quantidade de código que precisaria ser modificado para implementá-las. A arquitetura procura fazer isto através do uso de modularização e encapsulamento de informações para isolar componentes que provavelmente serão alterados sem a necessidade de alteração no restante do sistema.

Alguns quesitos mais específicos, tendem a ter detalhes e a serem alterados constantemente, sendo assim, os requisitos abaixo são de grande rotatividade quanto a real necessidade, sendo visto que temos que ter atenção para o atendimento desses objetivos, seguem:

``[Proteção]``

- A proteção do sistema deve ser fundamental, tanto para o servidor, quanto para os dados do usuário, sendo assim a proteção e a disponibilidade da informação é de grande importância.

``[Segurança]``

- A segurança, caminha juntamente com a proteção, tanto aos dados quanto ao meio físico que será implantado, logo temos um grande interesse em agregar esse ponto à estrutura do sistema.

``[Privacidade]``

- A Privacidade, traz consigo a restrição dos dados à apenas a processamento do sistema, sem a disponibilidade do mesmo para o meio público, sendo assim, após os usuários entrarem, cadastrarem, inserirem seus dados no sistema, o mesmo deve garantir que estes dados não sejam divulgados. 

``[Portabilidade]``

- A portabilidade, está representada pela disponibilidade de utilização do sistema, ou seja, o desenvolvimento web, deve torna-lo disponível para o máximo de plataformas, sendo possível tanto a utilização no PCs, tablets ou smartphones.

``[Distribuição]``

- A distribuição, tem o objetivo de difundir o sistema, para os usuários aptos, então levando em consideração que o JASSY tem o público alvo como alunos universitários, temos este ponto aplicado para a comunidade universitária.

``[Reutilização]``

- A Reutilização, vai ser encontrada em trabalhos futuros, porém é uma qualidade que pode ser aplicada a qualquer sistema em produção, então em qualquer momento, para evitar retrabalho, deve-se procurar padrões para o aproveitamento direto, ou futuro de partes estudadas e já desenvolvidas.
  
``[Ferramentas de desenvolvimento]``

- **As ferramentas que serão utilizadas, serão IDE's e framework's que se encaixarem no estilo de desenvolvimento, além de ferramentas de apoio em SQL, para modelagem** 

``[Estrutura das equipes]``

- As Equipes serão divididas em times de desenvolvimento, que utilizaram a metodologia de desenvolvimento de prototipagem, para que o desenvolvimento tenha retorno o mais rápido possível dos resultados, e consequentemente dos erros que estão presentes, evitando assim, retrabalhos muito longos, essa será a melhor maneira de organizar o projeto, para a prática e experiencia de equipe, onde todos passaram por cada etapa, para identificar-se com a sua área de escolha, porém conhecendo todas as outras, para saber o momento e o lugar que algum problema foi encontrado, logo as iterações de funcionalidades da equipe e individuais serão elevadas como experiência pratica.
 
``[Cronograma]``

- O cronograma deve ser atendido de acordo com o limite disponível, que foi dado de 1 ano, seguiremos o modelo de prototipagem, logo teremos diversos ajustes em partes do sistema, então o protótipo será construído de modo a se tornar a versão final, mais trabalhosa, porém evita o retrabalho e economiza tempo.
- Seguido as datas, temos um ciclo de vida do primeiro protótipo mais longo, para as adequações com os levantamentos e análises preliminares que foram retirados dos documentos de requisitos, sendo assim, separamos 3 meses para o primeiro protótipo, e sequencialmente teremos a distribuição de pequenas reuniões e apresentações de resultados mensalmente até o fim do projeto.
  + Sequência da produção com prototipagem.

Início
||
||
||>>>>> Coleta e Refinamento de Dados
		||
		||
  ||>>>>||>>>>> Projeto Rápido 
  ||            ||
  ||            ||
  ||            ||>>>>> Construção do Protótipo
  ||                    ||
  || /\                 ||
  || /\                 ||>>>>> Avaliação do Protótipo pelo Cliente
  ||  |                         ||
  ||  |                         ||
  ||  |                         ||>>>>> Refinamento do Protótipo 
  ||  |                                 ||
  ||  ---------                         ||
  ||<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<||>>> Engenharia de Produto
														  ||
														  ||
														  ||>>>>> Fim


``[Código-fonte legado e etc, assim por diante.]``

``[Uso de um produto desenvolvido internamente e adquirido pronto para ser usado]``

``[Ela também captura as restrições especiais que podem ser aplicáveis: estratégia de design e implementação]``

Minimalista, com a utiliação dos padrões de Material design, com cores pasteis, simples e com baixo contraste.
**Quado tiver mais ideias::::::::::::::::::::::::::::::::::::::::::::::::::::::::**


## 4. View de Casos de Uso
``[Esta seção lista os casos de uso ou cenários do modelo de casos de uso se eles representam uma funcionalidade central e significativa do sistema final ou se têm uma ampla cobertura de arquitetura, ou seja, se experimentam muitos elementos arquiteturais ou se enfatizam ou ilustram um determinado ponto frágil da arquitetura.]``

O objetivo da View de casos de uso é fornecer contexto aprofundado em torno do uso do sistema e das interações entre seus componentes. Para os fins deste documento, cada componente se torna um ator de caso de uso, que será descrito com mais detalhes a seguir. A Seção 4.1 lista os atores atuais e fornece uma breve descrição de cada um no contexto geral de uso do sistema. Na seção 4.2, os casos de uso mais comuns são descritos e ilustrados usando diagramas de casos de uso UML e diagramas de sequência para esclarecer as interações entre os componentes.

### 4.1 Atores
``[Esta seção ilustra o funcionamento do software, apresentando algumas realizações (ou cenários) de casos de uso selecionadas e explica como os diversos elementos do modelo de design contribuem para a respectiva funcionalidade.]``


#### 4.1.1 Administrador
É o usuário dos sitema que conduz a operação de controle do software, manipula usuários e outras funcionalidades do sistema.

#### 4.1.2 Professor
É o usuário do sistema que realiza operações em conjunto com os alunos do sistema, e tem é parte principal para o funcionamento completo do sistema.

#### 4.1.3 Aluno
É o usuário do sistema que realiza operações em conjunto com os professores do sistema, e é o público alvo para a utilização do sistema.

### 4.2 Realizações de Casos de Uso
``[Esta seção lista os casos de uso]``

#### 4.2.1 UC01 - Cadastrar Usuário
    Escopo - Sistema acadêmico administrativo
    Descrição do Propósito - Este caso de uso permite ao administrador criar os outros usuários do sistema. Considerando os tipos de usuários como administrador, professor e aluno
    Ator Primário - administrador
    Interessados e Interesses - administrador deseja cadastrar outros usuários no sistema.
    Pré-condições - O administrador deve estar logado no sistema.
    Pós-condições - Os usuários devem estar disponíveis após o cadastro, com o usuário recebendo o email de  confirmação com o usuário e a primeira senha, e para o administrador como confirmação de sucesso.
    Fluxo de Eventos Normal
        - Se Professor:
            + Criar professor: O administrador informa os dados do professor, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
            + Alterar Dados: O administrador informa o professor do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
            + Consultar Dados: O administrador informa o professor que deseja consultar. Os dados do professor são apresentados.
            + Excluir professor: O administrador informa o professor que deseja excluir. Os dados do professor são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o professor é excluído.
        - Se Aluno:
            + Criar aluno: O administrador informa os dados do aluno, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
            + Alterar Dados: O administrador informa o aluno do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
            + Consultar Dados: O administrador informa o aluno que deseja consultar. Os dados do aluno são apresentados.
            + Excluir aluno: O administrador informa o aluno que deseja excluir. Os dados do aluno são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o aluno é excluído.
    Fluxo de Eventos Alternativos
        - Incluir professores / Alterar Dados: Dados do professores inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF01, RF02
    Classes / Entidades - Professor, Administrador
    
#### 4.2.2 UC02 - Cadastrar Disciplina
    Escopo - Sistema acadêmico administrativo
    Descrição do Propósito - Este caso de uso permite ao administrador realizar o cadastro de disciplinas
    Ator Primário - administrador
    Interessados e Interesses - administrador deseja cadastrar uma nova disciplina
    Pré-condições - O administrador deve estar logado no sistema.
    Pós-condições - O administrador deve receber uma mensagem visual de confirmação
    Fluxo de Eventos Normal
        - Criar disciplina: O administrador informa os dados da disciplina, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O administrador informa a disciplina do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O administrador informa a disciplina que deseja consultar. Os dados da disciplina são apresentados.
        - Excluir disciplina: O administrador informa a disciplina que deseja excluir. Os dados do disciplina são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, a disciplina é excluída.
    Fluxo de Eventos Alternativos
        - Incluir disciplina / Alterar Dados: Dados da disciplina inválidos: uma mensagem de erro é exibida, solicitando correção   da informação inválida.
    Requisitos Relacionados - RF02
    Classes / Entidades - Curso, Administrador

#### 4.2.3 UC03 - Cadastrar Curso
    Escopo - Sistema acadêmico administrativo
    Descrição do Propósito - Este caso de uso permite ao administrador o cadastro de um curso
    Ator Primário - administrador
    Interessados e Interesses - administrador 
    Pré-condições - O administrador deve estar logado no sistema.
    Pós-condições -  administrador deve receber uma mensagem visual de confirmação
    Fluxo de Eventos Normal
        - Criar curso: O administrador informa os dados do curso, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O administrador informa o curso do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O administrador informa o curso que deseja consultar. Os dados do curso são apresentados.
        - Excluir curso: O administrador informa o curso que deseja excluir. Os dados do curso são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o curso é excluído.
    Fluxo de Eventos Alternativos
        - Incluir curso / Alterar Dados: Dados do curso inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF02, RF09
    Classes / Entidades - Curso
    
#### 4.2.4 UC04 - Cadastrar Turma
    Escopo - Sistema acadêmico administrativo
    Descrição do Propósito - Este caso de uso permite ao administrador o cadastro de uma turma
    Ator Primário - administrador
    Interessados e Interesses - O administrador deseja cadastrar novas turmas.
    Pré-condições - O administrador deve estar logado no sistema.
    Pós-condições -  administrador recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal 
        - Criar turma: O administrador informa os dados do turma, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas. 
        - Alterar Dados: O administrador informa o turma do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O administrador informa o turma que deseja consultar. Os dados do turma são apresentados.
        - Excluir [Objeto]: O administrador informa o turma que deseja excluir. Os dados do turma são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o turma é excluído.
    Fluxo de Eventos Alternativos
        - Incluir turma / Alterar Dados: Dados do turma inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF02, RF09
    Classes / Entidades - Turma, Administrador
        
#### 4.2.5 UC05 - Cadastrar Período
    Escopo - Sistema acadêmico administrativo
    Descrição do Propósito - Este caso de uso permite ao administrador o cadastro de um período
    Ator Primário - administrador
    Interessados e Interesses - O administrador deseja cadastrar novos períodos.
    Pré-condições - O administrador deve estar logado no sistema.
    Pós-condições -  administrador recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal
        - Criar período: O administrador informa os dados do período, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O administrador informa o período do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O administrador informa o período que deseja consultar. Os dados do período são apresentados.
        - Excluir período: O administrador informa o período que deseja excluir. Os dados do período são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o período é excluído.
    Fluxo de Eventos Alternativos
        - Incluir período / Alterar Dados: Dados do período inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF02, RF09
    Classes / Entidades - Períodos, Administrador
    
#### 4.2.6 UC06 - Cadastrar Histórico
    Escopo - Sistema acadêmico administrativo
    Descrição do Propósito - Este caso de uso permite ao administrador o cadastro de um Histórico
    Ator Primário - administrador
    Interessados e Interesses - O administrador deseja cadastrar novos históricos.
    Pré-condições - O administrador deve estar logado no sistema.
    Pós-condições -  administrador recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal 
        - Criar histórico: O administrador informa os dados do histórico, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O administrador informa o histórico do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O administrador informa o histórico que deseja consultar. Os dados do histórico são apresentados.
        - Excluir histórico: O administrador informa o histórico que deseja excluir. Os dados do histórico são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o histórico é excluído.
    Fluxo de Eventos Alternativos - Incluir histórico / Alterar Dados: Dados do histórico inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF02, RF09
    Classes / Entidades - Históricos, Administrador
    
#### 4.2.7 UC07 - Cadastrar Prova
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor o cadastro de uma prova
    Ator Primário - professor
    Interessados e Interesses - O professor deseja cadastrar novas provas.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal 
        - Criar prova: O professor informa os dados da prova, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O professor informa a prova do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O professor informa o prova que deseja consultar. Os dados da prova são apresentados.
        - Excluir [Objeto]: O professor informa o prova que deseja excluir. Os dados da prova são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o prova é excluído.
    Fluxo de Eventos Alternativos
        - Incluir prova / Alterar Dados: Dados da prova inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF03
    Classes / Entidades - Prova, Professor
    
#### 4.2.8 UC08 - Cadastrar Postagem em Fórum
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor o cadastro de um fórum
    Ator Primário - professor
    Interessados e Interesses - O professor deseja cadastrar novos fóruns.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal 
        - Criar fórum: O professor informa os dados do fórum, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O professor informa o fórum do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O professor informa o fórum que deseja consultar. Os dados do fórum são apresentados.
        - Excluir fórum: O professor informa o fórum que deseja excluir. Os dados do fórum são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o fórum é excluído.
    Fluxo de Eventos Alternativos
        - Incluir fórum / Alterar Dados: Dados do fórum inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF04
    Classes / Entidades - Fórum, Professor
    
#### 4.2.9 UC09 - Cadastrar Atividade Acadêmica
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor o cadastro de uma atividade acadêmica
    Ator Primário - professor
    Interessados e Interesses - O professor deseja cadastrar novas atividade acadêmica.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal 
        - Criar atividade acadêmica: O professor informa os dados da atividade acadêmica, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O professor informa a atividade acadêmica do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O professor informa a atividade acadêmica que deseja consultar. Os dados da atividade acadêmica são apresentados.
        - - Excluir atividade acadêmica: O professor informa a atividade acadêmica que deseja excluir. Os dados da atividade acadêmica são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, aatividade acadêmica é excluído. 
    Fluxo de Eventos Alternativos
        - Incluir atividade acadêmica / Alterar Dados: Dados da atividade acadêmica inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF03
    Classes / Entidades - Atividade Acadêmica, Professor
    
#### 4.2.10 UC10 - Manipular Histórico de Disciplina
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor a manipulação do histórico de uma disciplina
    Ator Primário - professor
    Interessados e Interesses - O professor deseja cadastrar novo histórico de uma disciplina.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal 
        - Criar histórico de disciplina: O professor informa os dados do histórico de disciplina, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O professor informa o histórico de disciplina do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O professor informa o histórico de disciplina que deseja consultar. Os dados do histórico de disciplina são apresentados.
        - Excluir histórico de disciplina: O professor informa o histórico de disciplina que deseja excluir. Os dados do histórico de disciplina são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o histórico de disciplina é excluído.
    Fluxo de Eventos Alternativos
        - Incluir histórico de disciplina / Alterar Dados: Dados do histórico de disciplina inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF09
    Classes / Entidades - Histórico de Disciplina, Professor
    
#### 4.2.11 UC11 - Preencher Pauta
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor o cadastro de uma pauta
    Ator Primário - professor
    Interessados e Interesses - O professor deseja cadastrar novas pauta.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de confirmação.
    Fluxo de Eventos Normal 
        - Criar pauta: O professor informa os dados do pauta, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas.
        - Alterar Dados: O professor informa o pauta do qual deseja alterar dados e os novos dados. Os novos dados são validados e a alteração registrada.
        - Consultar Dados: O professor informa o pauta que deseja consultar. Os dados do pauta são apresentados.
        - Excluir pauta: O professor informa o pauta que deseja excluir. Os dados do pauta são apresentados e é solicitada uma confirmação. Se a exclusão for confirmada, o pauta é excluído.
    Fluxo de Eventos Alternativos
        - Incluir pauta / Alterar Dados: Dados do pauta inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF08
    Classes / Entidades - Pauta, Professor
    
#### 4.2.12 UC12 - Enviar Email
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor o envio de email
    Ator Primário - professor
    Interessados e Interesses - O professor deseja enviar emails.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de confirmação de envio.
    Fluxo de Eventos Normal 
        - Enviar email: O professor informa os dados do email, a saber: [atributos e associações do email]. Caso os dados sejam válidos, as informações são registradas.
    Fluxo de Eventos Alternativos
        - Enviar email: Dados do email inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida
    Requisitos Relacionados - RF07
    Classes / Entidades - Professor
    
#### 4.2.13 UC13 - Avaliar Projeto
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor avaliar um projeto
    Ator Primário - professor
    Interessados e Interesses - O professor deseja avaliar projetos enviados pelos alunos.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de confirmação de avaliação, e registra-se a avaliação ao projeto, e envia-se o feedback para o aluno envolvido no projeto.
    Fluxo de Eventos Normal 
        - Avaliar projeto: O professor entra na página de avaliação de projetos, sendo exibida uma lista de projetos, ao selecionar um projeto, é aberta uma página com as informações referentes ao projeto, a saber: [atributos e associações do objeto]. O professor aceita o projeto, comentando sua opinião em um feedback para o aluno.
    Fluxo de Eventos Alternativos
        - Avaliar projeto: O professor rejeita o projeto, comentando sua opinião em um feedback para o aluno.
    Requisitos Relacionados - RF11
    Classes / Entidades - Projeto, Professor, Aluno
    
#### 4.2.14 UC14 - Buscar Salas ou Equipamento
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor buscar por salas e equipamentos disponíveis
    Ator Primário - professor
    Interessados e Interesses - O professor deseja procurar por salas e equipamentos que estão disponíveis, que possam ser utilizados para ministrar aulas.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de todos as salas disponíveis e as salas existentes. - O professor recebe uma mensagem visual de todos os equipamentos disponíveis e os equipamentos existentes
    Fluxo de Eventos Normal
        - Buscar sala ou equipamento: - O professor seleciona entre as opções, sala ou equipamento.
            + Se selecionado sala:
                * Informa os dados da busca por sala, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são exibidas para o professor.
            + Se selecionado equipamento:
            	* Informa os dados da busca por equipamento, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são exibidas para o professor.
    Fluxo de Eventos Alternativos 
        - Não existirem salas disponíveis: uma mensagem com a informação da sala e a não existência das salas disponíveis. 
    Requisitos Relacionados - RF06
    Classes / Entidades - Professor,  Sala, Equipamento
    
#### 4.2.15 UC15 - Requisitar Disponibilidade de horário
    Escopo - Sistema acadêmico docente
    Descrição do Propósito - Este caso de uso permite ao professor requisitar informações dos horários de seus alunos
    Ator Primário - professor
    Interessados e Interesses - O professor deseja requisitar informações dos horários dos alunos de determinada disciplina, em caso de necessidade de realocação de aulas, para que possam ser utilizados horários disponíveis para todos os alunos e ministrar aulas.
    Pré-condições - O professor deve estar logado no sistema.
    Pós-condições -  professor recebe uma mensagem visual de sucesso na busca.
    Fluxo de Eventos Normal
        - Requisitar disponibilidade de horário: O professor informa os dados da disciplina que deseja identificar os horários livres entre os alunos, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são exibidas na tela.
    Fluxo de Eventos Alternativos
        - Requisitar disponibilidade de horário: Não existirem horários disponíveis: uma mensagem com a informação da disciplina e não existem horários disponíveis. 
    Requisitos Relacionados - RF05
    Classes / Entidades - Professor, Aluno
    
#### 4.2.16 UC16 - Submeter Projeto
    Escopo - Sistema acadêmico discente
    Descrição do Propósito - Este caso de uso permite ao aluno submeter informações de um projeto
    Ator Primário - aluno
    Interessados e Interesses - O aluno deseja submeter informações de um projeto para determinado professor. - O professor deseja avaliar informações do projeto.
    Pré-condições - O aluno deve estar logado no sistema.
    Pós-condições -  aluno recebe uma mensagem visual de sucesso na submissão.
    Fluxo de Eventos Normal -  - Submeter projeto: O aluno informa os dados do projeto, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são enviadas para o professor.
    Fluxo de Eventos Alternativos - Submeter projeto: Dados do projeto inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida.
    Requisitos Relacionados - RF14
    Classes / Entidades - Projeto, Aluno, Professor
    
#### 4.2.17 UC17 - Exibir Histórico de disciplina
    Escopo - Sistema acadêmico discente
    Descrição do Propósito - Este caso de uso permite ao aluno buscar Histórico de disciplina
    Ator Primário - aluno
    Interessados e Interesses - O aluno deseja buscar o Histórico de uma disciplina.
    Pré-condições - O aluno deve estar logado no sistema.
    Pós-condições -  aluno recebe uma mensagem visual de confirmação da visualização.
    Fluxo de Eventos Normal 
        - Exibir Histórico de disciplina: O aluno informa os dados da disciplina, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são exibidas em seguida.
    Fluxo de Eventos Alternativos
        - Exibir Histórico de disciplina: Dados da disciplina não existem: uma mensagem de erro é exibida, solicitando correção da informação da disciplina, por uma existente.
    Requisitos Relacionados - RF09
    Classes / Entidades - Disciplina, Aluno
    
#### 4.2.18 UC18 - Enviar Atividade Acadêmica
    Escopo - Sistema acadêmico discente
    Descrição do Propósito - Este caso de uso permite ao aluno enviar atividade acadêmica
    Ator Primário - aluno
    Interessados e Interesses - O aluno deseja enviar uma atividade acadêmica para a disciplina.
    Pré-condições - O aluno deve estar logado no sistema.
    Pós-condições -  aluno recebe uma mensagem visual de confirmação do envio.
    Fluxo de Eventos Normal
        - Enviar Atividade Acadêmica: O aluno seleciona a disciplina, em seguida informa os dados da atividade acadêmica, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são registradas e enviadas para o sistema.
    Fluxo de Eventos Alternativos
        - Enviar Atividade Acadêmica: Dados da atividade acadêmica inválidos: uma mensagem de erro é exibida, solicitando correção da informação inválida para o envio.
    Requisitos Relacionados - RF12, RF03
    Classes / Entidades - Disciplina, Aluno, Atividade acadêmica
    
#### 4.2.19 UC19 - Exibir Disciplina
    Escopo - Sistema acadêmico discente
    Descrição do Propósito - Este caso de uso permite ao aluno buscar as informações de uma disciplina
    Ator Primário - aluno
    Interessados e Interesses - O aluno deseja buscar informações de uma disciplina.
    Pré-condições - O aluno deve estar logado no sistema.
    Pós-condições -  aluno recebe uma mensagem visual de confirmação da visualização.
    Fluxo de Eventos Normal 
        - Exibir disciplina: O aluno informa os dados da disciplina, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são exibidas em seguida.
    Fluxo de Eventos Alternativos 
        - Exibir disciplina: Dados da disciplina não existem: uma mensagem de erro é exibida, solicitando correção da informação da disciplina, por uma existente.
    Requisitos Relacionados - RF02
    Classes / Entidades - Disciplina, Aluno
    
#### 4.2.20 UC20 - Exibir Prova
    Escopo - Sistema acadêmico discente
    Descrição do Propósito - Este caso de uso permite ao aluno buscar as informações de uma prova
    Ator Primário - aluno
    Interessados e Interesses - O aluno deseja buscar informações de uma prova.
    Pré-condições - O aluno deve estar logado no sistema.
    Pós-condições -  aluno recebe uma mensagem visual de confirmação da visualização.
    Fluxo de Eventos Normal
        - Exibir prova: O aluno seleciona uma disciplina informa os dados da prova, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são exibidas em seguida.
    Fluxo de Eventos Alternativos
        - Exibir prova: Dados da prova não existem: uma mensagem de erro é exibida, solicitando correção da informação da prova, por uma existente.
    Requisitos Relacionados - RF03
    Classes / Entidades - Prova, Disciplina, Aluno
    
#### 4.2.21 UC21 - Exibir Pauta
    Escopo - Sistema acadêmico discente
    Descrição do Propósito - Este caso de uso permite ao aluno buscar as informações de uma pauta
    Ator Primário - aluno
    Interessados e Interesses - O aluno deseja buscar informações de uma pauta.
    Pré-condições -  aluno deve estar logado no sistema.
    Pós-condições -  aluno recebe uma mensagem visual de confirmação da visualização.
    Fluxo de Eventos Normal 
        - Exibir pauta: O aluno seleciona uma disciplina informa os dados da pauta, a saber: [atributos e associações do objeto]. Caso os dados sejam válidos, as informações são exibidas em seguida.
    Fluxo de Eventos Alternativos
        - Exibir pauta: Dados da pauta não existem: uma mensagem de erro é exibida, solicitando correção da informação da pauta, por uma existente.


## 5. View Lógica
``[Esta seção descreve as partes significativas do ponto de vista da arquitetura do modelo de design, como sua divisão em componente e pacotes]``

O principal objetivo da visão lógica é definir os componentes que formarão o sistema e as interfaces através das quais eles se comunicarão e interagirão. O principal fator de tomada de decisão por trás da definição dos componentes do sistema é a necessidade de isolar os componentes que provavelmente serão alterados do restante do sistema. Definindo claramente as interfaces desses componentes e ocultando suas implementações internas do restante do sistema, o impacto das mudanças esperadas pode ser minimizado. 

``[Além disso, para cada pacote significativo, ela mostra sua divisão em classes e utilitários de classe]``


``[Apresente as classes significativas do ponto de vista da arquitetura e descreva suas responsabilidades, bem como alguns relacionamentos, operações e atributos de grande importância.]``


### 5.1 View Geral
``[Esta subseção descreve toda a decomposição do modelo de design em termos de camadas e de hierarquia de pacotes.]``


``[Para cada pacote significativo, inclua uma subseção com o respectivo nome, uma breve descrição e um diagrama com todos os pacotes e classes significativos nele contidos. Para cada classe significativa no pacote, inclua o respectivo nome, uma breve descrição e, opcionalmente, uma descrição de algumas de suas responsabilidades, operações e atributos mais importantes.]``


#### 5.3 Interfaces

##### 5.3.1 Professor

Tela de Login

- Autenticar o usuário, permitindo que ele se identifique com suas credenciais.

Dashboard

- Mostrar ao usuário uma visão geral das suas informações e um menu que permita ao usuário escolher o que ele quer realizar ou acessar, dentro do sistema.

Atividade Acadêmica:

- Exibir ao professor as atividades já cadastrados
- Exibir as submissões enviadas pelos alunos
- Permitir que ele avalie as atividades acadêmicas submetidas
- Perimitir que cadastre novas Atividades.

Horários Disponíveis

- Exibir horários disponíveis

Histórico da Disciplina

- Permitir que o professor gerencie (adicionar, remover, editar) os arquivos relacionados à uma disciplina

Pauta

- Permitir que o professor administre a pauta das turmas, atribuindo presença aos alunos

Projeto

- Avaliar

Fórum

- Exibir fóruns
- Criar postagens

E-mail

- Enviar E-mail
- Caixa de entrada

Reserva

- Salas
  + Exibir as salas de aula disponíveis para serem usadas
  + Permitir que o professor faça reserva de uma sala.
- Equipamentos
  + Exibir os equipamentos disponíveis para utilização
  + Permitir que o professor faça reserva de um equipamento


##### 5.3.2 Aluno

Tela de Login

- Autenticar o usuário, permitindo que ele se identifique com suas credenciais

Dashboard

- Mostrar ao usuário uma visão geral das suas informações e um menu que permita ao usuário escolher o que ele quer realizar ou acessar, dentro do sistema.

Atividade Acadêmica

- Exibir as atividades e trabalhos a serem realizadas
- Permitir que os alunos submetam as atividades.

Horários Disponíveis

Disciplina

- Histórico de Disciplina para exibir os arquivos relacionados às disciplinas e permitir que os alunos contribuam com o histórico.
- Disciplina para exibir as informações relacionadas às disciplinas nas quais os alunos estão matriculados.
- Permitir que os alunos visualizem as datas de provas e a correção (resultado) das provas já realizadas.

Pauta

- Permitir que os alunos acompanhem, em tempo real, as pautas das disciplinas nas quais estão matriculados.

Projeto

- Permitir que o alunos submetam projetos a serem avaliados pelo professor.

Fórum

- Exibir fóruns
- Criar postagens

Reserva

- Salas
  + Exibir as salas de aula disponíveis para serem usadas
  + Permitir que o professor faça reserva de uma sala.
- Equipamentos
  + Exibir os equipamentos disponíveis para utilização
  + Permitir que o professor faça reserva de um equipamento


##### 5.3.3 Administrador

Tela de Login

Usuário

- Inserir, alterar, excluir *usuários* do sistema

Disciplina

- Inserir, alterar, excluir *disciplinas* do sistema

Curso

- Inserir, alterar, excluir *cursos* do sistema

Turma

- Inserir, alterar, excluir *turmas* do sistema

Período

- Inserir, alterar, excluir *períodos* do sistema

Histórico

- Inserir, alterar, excluir *históricos de disciplinas* do sistema

Reserváveis

- Inserir, alterar, excluir *itens de reserva* do sistema



## 6. View de Processos
``[Esta seção descreve a decomposição do sistema em processos leves (threads simples de controle) e processos pesados (agrupamentos de processos leves)]``


``[Organize a seção em grupos de processos que se comunicam ou interagem. Descreva os modos principais de comunicação entre processos, como transmissão de mensagens e interrupções.]``



## 8. Tamanho e Desempenho
A arquitetura de software escolhida suporta os principais requisitos de tamanho e tempo, conforme estipulado pelos requisitos originais das entrevistas:

- 1. O sistema deve suportar no mínimo 2.000 usuários simultâneos no sistema online central (Alunos e Professores mais especificamente) a qualquer momento e no mínimo 50 usuários simultâneos nos servidores locais (mais especificamente administradores) a qualquer momento.
- 2. O sistema deve fornecer acesso ao banco de dados com uma latência menor que 5 segundos.
- 3. O sistema deve ser capaz de concluir todas as transações dentro de 20 segundos (sendo transação, qualquer operação que insere/modifica o banco de dados).

A arquitetura selecionada suporta os requisitos de dimensionamento e tempo por meio da implementação de uma arquitetura cliente-servidor.

## 9. Qualidade
``[Uma descrição de como a arquitetura do software contribui para todos os recursos (exceto a funcionalidade) do sistema:]``
A arquitetura do software suporta os requisitos de qualidade, conforme estipulado na pelos requisitos originais das entrevistas:

- 1. A interface do usuário do sistema deve ser projetada para facilitar o uso e deve ser apropriada para uma comunidade de usuários com conhecimentos em informática, sem treinamento adicional no sistema.
- 2. Cada recurso do sistema deve ter ajuda on-line integrada para o usuário. A Ajuda on-line deve incluir instruções passo a passo sobre o uso do sistema. E também deve incluir definições para termos e acrônimos.
- 3. O sistema estará disponível 24 horas por dia, 7 dias por semana. Não deve haver mais de 5% de tempo de inatividade.
- 4. O tempo médio entre falhas deve exceder 250 horas, ou duas semanas entre manutenções.

``[extensibilidade]``
- 5. O sistema deve permitir a adição de novos módulos, como futuramente será desenvolvido (gestão de RH, gestão de Biblioteca, gestão de Obras, gestão de Materiais, entre outros) para o sistema se tornar único na gestão de uma universidade, e a possivel integração entre sistemas de polos da universidade.
- 6. O sistema deve ser desenvolvido com o intuito de poder ser utilizado em dispositivos móveis inicialmente via web browser, e futuramente, ser desenvolvido um app para a melhor usabilidade do mesmo.
- 7. O sistema deve permitir a alteração do formato dos relatórios, e a partir de futuras reuniões melhorar os formatos e dados dos mesmos.
``[confiabilidade]``

``[Se essas características tiverem significado especial, como, por exemplo, implicações de proteção, segurança ou privacidade, elas devem ser claramente delineadas.]``

