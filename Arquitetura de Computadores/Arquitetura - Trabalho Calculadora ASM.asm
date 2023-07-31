.data
	#Download do M.A.R.S 'http://courses.missouristate.edu/kenvollmar/mars/'
	#Para Entrada
	printTitle: .asciiz "***** CASIO  S.x *****\n"
	printExp1: .asciiz "Entre com o Primeiro Numero: "
	printExp2: .asciiz "Entre com o Segundo Numero: "
	
	#Escolha do Usuario
    	AddiExp: .asciiz "\n1 - Adicao"
    	SubExp: .asciiz "\n2 - Subtracao"
    	MulExp: .asciiz "\n3 - Multiplicacao"
    	DivExp: .asciiz "\n4 - Divisao"
    	UserChoice: .asciiz "\nEscolha: "
    	
    	ResultExp: .asciiz "\nResult: "
    	SBNPPL: .asciiz "\n" #Simples Barra N Para Proxima Linha
    	
    	#	li $v0, 4 == Printf(%s);
    	#	li $v0, 7 == Scanf();
    	#	li $v0, 1 == Printf(%d);
    	
    	A:      .float  0.0
    	B:	.word 5
    	C:	.word -1
.text
.globl main

main:
	la $a0, printTitle
	li $v0, 4 
	syscall
	
	#Pegando a entrada 1
	#printExp1
	la $a0, printExp1
	li $v0, 4 
	syscall
	
	#pegando a entrada
	li $v0, 7
	syscall
	
	#movendo de f0 para f4
	mov.d $f4, $f0

loop:
	l.d $f10, A
	
	la $a0, SBNPPL
	li $v0, 4
	syscall
	
	#Pegando a entrada 2
	#printExp2
	la $a0, printExp2
	li $v0, 4
	syscall
	
	#pegando a entrada
	li $v0, 7
	syscall
	
	#addi $t0, $zero, 0
	#mfc1 $t1, $f6
	
	c.eq.d $f10, $f0
	bc1t TheEnd  #exit se true
	
	#movendo de f0 para f6
	mov.d $f6, $f0
	
Operadores:		
	#Adicao
	la $a0, AddiExp
	li $v0, 4
	syscall
	
	#Subtracao
	la $a0, SubExp
	li $v0, 4
	syscall
	
	#Multiplicacao
	la $a0, MulExp
	li $v0, 4
	syscall
	
	#Divisao
	la $a0, DivExp
	li $v0, 4
	syscall
	
	#Escolha
	la $a0, UserChoice
	li $v0, 4
	syscall
	
	#Pegando a escolha
	li $v0, 5
	syscall
	
	#movendo a entrada de v0 para t0
	move $t0, $v0
	
	lw $t7, C
	ble $t0, $t7, Operadores
	lw $t7, B
	bge $t0, $t7, Operadores
	
	#Constantes para comparacao
	addi $t1, $zero, 1 #para Adicao
	addi $t2, $zero, 2 #para Subtracao
	addi $t3, $zero, 3 #para Multiplicacao
	addi $t4, $zero, 4 #para Divisao
	
	#Se for 1
	#Adicao
	beq $t0, $t1, Adicao
	
	#Subtracao
	beq $t0, $t2, Subtracao
	
	#Multiplicacao
	beq $t0, $t3, Multiplicacao
	
	#Divisao
	beq $t0, $t4, Divisao
	
	#fim do programa - At the world ends
	li $v0, 10
	syscall
	
#Executando o calculo Adicao
Adicao:
	add.d $f4, $f4, $f6
	
	#Resultado
	la $a0, ResultExp
	li $v0, 4
	syscall
	
	#print
	mov.d $f12, $f4
	li $v0, 3
	syscall
	
	j loop
	#Fim da Adicao
	
#Executando o calculo Subtracao
Subtracao:
	sub.d $f4, $f4, $f6
	
	#Resultado
	la $a0, ResultExp
	li $v0, 4
	syscall
	
	#print
	mov.d $f12, $f4
	li $v0, 3
	syscall
	
	j loop
	#Fim da Subtracao
	

#Executando o calculo Multiplicacao
Multiplicacao:
	mul.d $f4, $f4, $f6
	
	#Resultado
	la $a0, ResultExp
	li $v0, 4
	syscall
	
	#print
	mov.d $f12, $f4
	li $v0, 3
	syscall
	
	j loop
	#Fim da Multiplicacao
	

#Executando o calculo Divisao
Divisao:
	div.d $f4, $f4, $f6
	
	#Resultado
	la $a0, ResultExp
	li $v0, 4
	syscall
	
	#print
	mov.d $f12, $f4
	li $v0, 3
	syscall
	
	j loop
	#Fim da Divisao
	
TheEnd:
	li $v0, 10
	syscall
