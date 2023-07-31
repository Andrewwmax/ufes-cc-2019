//Inteiros
(p|n)?(0|1|2|3|4|5|6|7|8|9)+

//Reais
(p|n)?(0|1|2|3|4|5|6|7|8|9)*(.)?(0|1|2|3|4|5|6|7|8|9)+


//4.a Números romanos de 1 a 99.
UNIDADES	= I|II|III|IV|V|VI|VII|VIII|IX
DEZENAS		= X|XX|XXX|XL|L|LX|LXX|LXXX|XC
CENTENAS	= C|CC|CCC|CD|D|DC|DCC|DCCC|CM
MILHARES	= M|MM|MMM
(MILHARES) (CENTENAS)? (DEZENAS)? (UNIDADES)? |
(MILHARES)? (CENTENAS) (DEZENAS)? (UNIDADES)? |
(MILHARES)? (CENTENAS)? (DEZENAS) (UNIDADES)? |
(MILHARES)? (CENTENAS)? (DEZENAS)? (UNIDADES) 

//4.b Valores monetários em Reais. Possuem exatamente duas casas decimais depois 
da vírgula, e usam ponto como separador de milhar. 
Exemplos: { R$2,35 ; R$1.546,98 ; R$1,00 ; R$10.000.000.000,00 }
(R$) (0|1|2|3|4|5|6|7|8|9)?(0|1|2|3|4|5|6|7|8|9)?(0|1|2|3|4|5|6|7|8|9) 
(.(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9))* 
(,) (0|1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9) 

//4.c. Strings que possuem uma quantidade par de a’s sobre o alfabeto Σ = {a,b,c}
Resp1 ((b|c)* a (b|c)* a (b|c)*)* (b|c)*
Resp2 ((b|c)* (a(b|c)*a)?(b|c)*)*

//4.d. Strings que possuem tamanho múltiplo de três, sobre o alfabeto Σ = {a,b,c}
((a|b|c)(a|b|c)(a|b|c))*

//4.e. Strings com pelo menos um ‘1’ sobre o alfabeto Σ = {0,1}
(0|1)* (1) (0|1)*

//4.f. Strings terminadas em ‘110’ sobre o alfabeto Σ = {0,1}
(0|1)* (110)

//4.g. Strings contendo ‘00’ sobre o alfabeto Σ = {0,1}
(0|1)* (00) (0|1)*

//4.h. Strings iniciadas e terminadas em ‘10’ sobre o alfabeto Σ = {0,1}
Resp1 ((10) (0|1)* (10)) | (10)
Resp2 (10) ((0|1)* (10))?

//4.i. Strings formadas por uma seqüência de a's seguida de uma seqüência de b's e 
//terminada por uma seqüência de c's. É possível que cada uma das três seqüências 
descritas não possuam caracteres, mas se eles ocorrerem devem estar na ordem: 
a’s, b’s e c’s. A string vazia não pode ser aceita. Considere o alfabeto Σ = {a,b,c}
(a+|b*|c*)|(a*|b+|c*)|(a*|b*|c+)


////////////////////////////////////////////////////////////////////////////////////
5 - A
6 - B
7 - D
8 - D (contra exemplo = 'b')
9 - E
10 - C
11 - A
12 - D
13 - D
14 - D
15 - C
16 - A
17 - B
18 - C
21 D
22 B

////////////////////////////////////////////////////////////////////////////////////


24
Para cada uma das linguagens regulares descritas a seguir, faça uma ER 
(expressão regular), em seguida faça um AFD (autômato finito determinístico), 
e por último escreva a GR (gramática regular) equivalente a partir do algoritmo de 
transformação de ADF em GR.
Considere as letras minúsculas {a,b,c} como alfabeto.
a. { a^i b^n a^p b^k 	| i >= 0, n >= 1, p >= 2, k >= 3 }
	ER: a*b+a(a)+bb(b)+
	GR:	A -> aA
		A -> bB
		B -> aC
		B -> bB
		C -> aD
		C -> bB 
		D -> aD 
		D -> bE 
		E -> aA 
		E -> bF 
		F -> aA 
		F -> bG 
		G -> aA 
		G -> bG
		G -> λ

b. { a^i ba b^2k 		| i >= 1, k>=0 }
	ER:	a+ba(b)*
	GR:	S -> aA
		A -> aA
		A -> bB
		B -> aC
		B -> bA
		C -> aA
		C -> bC
		C -> λ

c. { a^2i b^2n+1 c^k 	| i,n,k >= 0 }
	ER:	a*b*c*
	GR:	S -> aS
		S -> bA
		S -> cB
		S -> λ
		A -> bA
		A -> cB
		A -> λ
		B -> cB
		B -> λ

d. { (ab)^i c b^k 		| i,k >= 0}
	ER: (ab)* c b*
	GR: S -> aA
		S -> cB
		A -> bC
		C -> aA
		C -> cB
		B -> bD
		B -> λ
		D -> bD
		D -> λ

////////////////////////////////////////////////////////////////////////////////////
25 - A
29 - E
32 - E
33 - B (o correto seria VFVVF)
34 - C
38 - D
39 - B
40 - A
////////////////////////////////////////////////////////////////////////////////////

42
Faça uma gramática livre de contexto (GLC) para cada uma das linguagens de 
nível 2, ou seja, livres de contexto.
a. { a^2i b^2i c^2k 	| i >= 0, k >= 0 }
	GLC:	
		S -> AAB
		A -> aabbA | λ
		B -> ccB | λ

b. { a^i b^i a^k b^k 	| i >= 0, k >= 1 }
	GLC:
		S -> AB
		A -> abA | λ
		B -> abB | ab

c. { a^i b^k a^k b^i 	| i,k >= 0}
	GLC:
		S -> aSb | A
		A -> bAa | λ

d. { (ab)^i c b^i 		| i >= 0}
	GLC:
		S -> abSb | c

e. { a^i c^k b^2i 		| i >= 1, k >= 0}
	GLC:
		S -> aSbb | aAbb
		A -> Ac |  λ

f. { a^i c^k b^n 		| i=k ou inclusivo k=n}
	GLC:
		S -> AB | CD
		A -> aAc | λ
		B -> bB | λ
		C -> aC | λ
		D -> cDb | λ

g. { a^i b^n 			| i é diferente de n}
	GLC:
		S -> aSb | A | B
		A -> aA | a
		B -> bB | b

h. { a^i b^n 			| 0 <= i <= n <= 2i}
	GLC:
		S -> aSb | aSbb | λ

i. { a^i+n b^i c^n 		| i,n >= 0}
	GLC:
		S -> aSc | B
		B -> aBb | λ

j. palíndromos ímpares sobre {a,b}
	GLC:
		S -> aSa | bSb | a | b

k. strings sobre {a,b} com a mesma quantidade de a's e b's.
	GLC:
		S -> aSb | abS | baS | λ


////////////////////////////////////////////////////////////////////////////////////
43 - A
44 - E
45 - D
////////////////////////////////////////////////////////////////////////////////////

46
A partir da gramática fornecida, descreva, com precisão a linguagem gerada. 
Se a linguagem for regular, use a notação de expressão regular para a representá-la. 
Considere letras maiúsculas como símbolos não terminais (variáveis) e letras 
minúsculas como símbolos terminais.

a. 	S -> aS | bB | λ
	B -> cB | λ
		ER: a*(b)c*
		Gera:
			λ
			b
			a b
			b c
			a b c
			a a b c c
			a a a a a a a a b
			a a a a b c c c c
			b c c c c c c c c

b. 	S -> aSb | aAb
	A -> bAa | λ
		GLC: a^n b^k a^k b^n >= 0
		Gera:
			a b
			a a b b
			a b a b
			a a a b b b
			a a a b a b b b
			a a b b a a b b
			a b b b a a a b

c. 	S -> aSbb | A
	A -> cA | c
		GLC: a^n c^k b^2n  > 0
		Gera:
			c
			c c
			c c c
			a c b b
			a a c b b b b
			a a a c c c c b b b b b b b

d. 	S -> AAASb | λ
	A -> a | λ
		//GLC: a^3n b^k 	>= 0
		ER: (a*)(b)+
		Gera: 
			λ
			a b
			a a b
			a a a b
			a b b b b
			Qualquer valor de a ou b

e. 	S -> aaSB | λ
	B -> bB | b
		//GLC: a^2n b^k
		ER: ((aa)+ (b)+)*
		Gera:
			a a b
			a a b b b b b b b b
//Confirmar

////////////////////////////////////////////////////////////////////////////////////
47 D
////////////////////////////////////////////////////////////////////////////////////

48
Crie uma gramática livre de contexto para gerar uma lista de expressões aritméticas 
formadas apenas por números inteiros sem sinal de 20 a 99 e pelo operador de adição 
(as expressões são separadas por ponto e vírgula). 
Assuma a existência dos seguintes tokens:

	<DÍGITO1> - representa exatamente um dígito de 0 a 9.
	<DÍGITO2> - representa exatamente um dígito de 2 a 9.
	<SOMA> - representa o caractere ‘+’.
	<PT-VIRG> - representa o caractere ‘;’.

Observe um exemplo de string que deve ser gerada pela gramática:
23 + 44 + 99 ; 25 ; 51 + 20

S -> AB | AC
A -> <DÍGITO1> <DÍGITO2>
B -> <SOMA> A B | C
C -> <PT-VIRG>

////////////////////////////////////////////////////////////////////////////////////
49 D
////////////////////////////////////////////////////////////////////////////////////

50
Elabore uma gramática livre de contexto para gerar expressões com parênteses, 
colchetes e chaves balanceadas, as quatro operações básicas, números e variáveis.
Admita a existência de tokens para representar cada um dos elementos citados.
Observe exemplos de strings da linguagem:
	[2*(4+3)], 
		100, 
			{w -[3-5]+{4-( x - ((y)) )-1}-9}-8 , 
				valor+contador,
					({[(2)]}),
						[ 2- {x -5 }]

EXP 	->  EXP <OP> EXP
		  | <APAR> EXP <FPAR>
	 	  | <ACOL> EXP <FCOL>
	 	  | <ACHA> EXP <FCHA>
	 	  | <VAR>
	 	  | <NUM>

<OP> 	->  + 
		  | - 
		  | * 
		  | /

<VAR>	-> a | b | c | d | e | f | g | h | i | j | k | l | m 
		 | n | o | p | q | r | s | t | u | v | w | x | y | z

<NUM> 	-> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

<APAR> 	-> (
<FPAR>	-> )
<ACOL>	-> [
<FCOL>	-> ]
<ACHA>	-> {
<FCHA>	-> }

////////////////////////////////////////////////////////////////////////////////////

51 e 52
A partir do exercício anterior, faça a seguinte modificação: parênteses, colchetes e 
chaves são opcionais, mas se eles aparecerem na mesma expressão eles devem obedecer
a seguinte ordem: parênteses (mais internos), colchetes e chaves (mais externos).

Exemplos corretos:
	[2*(4+3)], 
		100, 
			{w -[3-5]+{4-( x - ((y)) )-1}-9}-8,
				valor+contador

Exemplos incorretos:
	({[(2)]}),
		[ 2- {x -5 }]

EXP 	-> EXP <OP> EXP 
		 | <ACHA> A <FCHA> 
		 | B 
		 | C

A 		-> A <OP> A 
		 | <ACHA> A <FCHA> 
		 | <ACOL> B <FCOL>
		 | B 

B 		-> B <OP> B 
		 | <ACOL> B <FCOL> 
		 | <APAR> C <FPAR> 
		 | C 

C 		-> C <OP> C 
		 | <APAR> C <FPAR> 
		 | TERMO

TERMO 	-> <NUM> | <VAR>

<VAR>	-> a | b | c | d | e | f | g | h | i | j | k | l | m 
		 | n | o | p | q | r | s | t | u | v | w | x | y | z

<NUM> 	-> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

<APAR> 	-> (
<FPAR>	-> )
<ACOL>	-> [
<FCOL>	-> ]
<ACHA>	-> {
<FCHA>	-> }

////////////////////////////////////////////////////////////////////////////////////

Desafio (52): no exercício anterior, somente permita a ocorrência de colchetes se 
houver parênteses internos, e chaves se houver colchetes.

EXP 	-> PAR 
		 | COL
		 | CHA

PAR  	-> <APAR> PAR <APAR> 
		 | PAR <OP> PAR 
		 | TERMO

COL 	-> <ACOL> COL <FCOL> 
		 | COL <OP> COL 
		 | PAR <OP> PAR 
		 | PAR <OP> COL 
		 | COL <OP> PAR 
		 | <APAR> PAR <FPAR>

CHA 	-> <ACHA> CHA <FCHA> 
		 | CHA <OP> CHA 
		 | PAR <OP> CHA 
		 | CHA <OP> PAR 
		 | COL <OP> CHA 
		 | CHA <OP> COL 
		 | <ACHA> COL <FCHA>

TERMO 	-> <NUM> | <VAR>

<VAR>	-> a | b | c | d | e | f | g | h | i | j | k | l | m 
		 | n | o | p | q | r | s | t | u | v | w | x | y | z

<NUM> 	-> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

<APAR> 	-> (
<FPAR>	-> )
<ACOL>	-> [
<FCOL>	-> ]
<ACHA>	-> {
<FCHA>	-> }


////////////////////////////////////////////////////////////////////////////////////

53
Desenvolva uma gramática livre de contexto para gerar expressões aritméticas no estilo da linguagem LISP. Use
apenas números inteiros sem sinal. Considere, para cada operação, exatamente dois operandos. Suponha a existência
de tokens para os elementos que compõem as expressões.
Exemplos: 
( + 2 3);
	( - ( * 20 30) 4);
		( + ( + 1 4) ( + 3 ( + 3 5))).

EXP 	-> <AP> <OP> TERMO TERMO <FP>
TERMO 	-> <NUM> 
		 | <IDENT> 
		 | EXP

////////////////////////////////////////////////////////////////////////////////////

57
Retire a recursividade à esquerda e fatore (quando for possível) os trechos de gramáticas a seguir.

a 	
		lista 	-> <IDENT> R 
		R		-> <VIRG> lista | λ

b 	
	COMANDOS 	-> <FIM> R 
	R 			-> COMANDO | λ

	COMANDO 	-> <IDENT> S
	S 			-> <ATRIB> EXP | TIPO

		tipo 	-> <REAL> | <INT>
			EXP	-> <APAR> exp <FPAR> P
			 	 | <NUM> P
			 	 | <IDENT> P
			P 	-> <OP> EXP P | λ

c 
			S -> b S2
			     | a S1
			     | c S
			S1  -> S
			     | A
			     | B
			     | C
			S2 -> S
			     | A
			     | B
			     | C
			A 	-> a
			B 	-> b
			C 	-> c

d 
		LISTA 	-> FIM R
	 		R 	-> <VIRG> FIM R
				 | <PT-VIRG> FIM R 
				 | λ

e
 		TERMO 	-> FATOR R R1 
			R1 	-> OUTRO R1 | λ
			R	-> <OP> | <OPCONT>

f
 			S 	-> AaS1
    			 | a
			S1	-> B
			     | S
 			A 	-> b
			B 	-> c

g
		  	S 	-> aS2
		  		 | bBC
		  		 | g 
		  		 | h
			S1  -> B
			     | C
			S2  -> bS1
			     | B 
			     | g
			A 	-> y
			B 	-> k

h 
 			A  -> A A1
 				| b
 			 	| c
			A1 -> a 
				| d

i 
			S 	-> a S2
			     | S S1
			     | c
			S1 	-> a b
			     | A
			S2  -> A
			     | S

j 
		exp 	-> termo exp1
		exp1 	-> <OP> exp exp1
		       	 | λ
		termo 	-> <ABRE-PAR> exp <FECHA-PAR>
		       	 | <NUM>
		       	 | <IDENT>


////////////////////////////////////////////////////////////////////////////////////
56 B
////////////////////////////////////////////////////////////////////////////////////

61
Refaça o exercício 53 (gramática livre de contexto para gerar expressões aritméticas 
no estilo da linguagem LISP) utilizando-se do recurso do formato BNF.
LISP
	( + 2 3);
		( - ( * 20 30) 4);
			( + ( + 1 4) ( + 3 ( + 3 5))).
GLC:
	EXP 	-> <AP> <OP> TERMO TERMO <FP>
	TERMO 	-> <NUM> 
			 | <IDENT> 
			 | EXP

BNF:
	EXP -> <AP> <OP> (<NUM> | <IDENT> | EXP) (<NUM> | <IDENT> | EXP) <FP>

EBNF:
	EXP -> <AP> <OP> (<NUM> | <IDENT> | EXP) (<NUM> | <IDENT> | EXP) <FP>

////////////////////////////////////////////////////////////////////////////////////

62 - D
67 - D
68 - E
69 - C
72 - E
73 - A
74 - E
76 - C
77 - D
78 - B
79 - anulada
80 - A