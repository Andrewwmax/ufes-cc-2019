#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct operandos {
    float a;
    float b;
    float res;
    int count;
    int lastOperation;
    int opc;
} tOperando;

float fAdd(float a, float b) {
    a = a + b;
    return a;
}

float fSub(float a, float b) {
    a = a - b;
    return a;
}

float fMul(float a, float b) {
    a = a * b;
    return a;
}

float fDiv(float a, float b) {
    if (b <= 0) printf("Erro!!!Divisao por Zero nao e possivel!!!\n\n");
    a = a / b;
    return a;
}

//float fExp(float a, float b) { 
//int fFat(float a, float b) {

int fFib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    return fFib(n - 1) + fFib(n - 2);
}

float inserirA() {
    float a;
    printf("\nEntre com o valor de 'A': ");
    scanf("%f", &a);
    return a;
}

float inserirB() {
    float b;
    printf("\nEntre com o valor de 'B': ");
    scanf("%f", &b);
    return b;
}

tOperando menuOperacao(tOperando user) {

    if (user.opc == 1) {
        user.res = fAdd(user.a, user.b);
    } else if (user.opc == 2) {
        user.res = fSub(user.a, user.b);
    } else if (user.opc == 3) {
        user.res = fMul(user.a, user.b);
    } else if (user.opc == 4) {
        user.res = fDiv(user.a, user.b);
    }
    return user;
}

tOperando menu(tOperando user) {
    do {
        printf("\n\t*****CASIO S3.X*****");
        printf("\n\nOperacoes para o limite de 32 bits\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("\nEscolha a operacao:");
        scanf("%d", &user.opc);

        if (user.opc < 1 || user.opc > 4) {
            printf("\nOpcao invalida!!!");
        }
    } while (user.opc < 1 || user.opc > 4);

    if (user.count++ == 0) user.a = inserirA(); //Primeira vez, temos que inserir o operando A;
    else printf("'A' = %f",user.a);
    user.b = inserirB();
    if (user.b == 0) return user;

    user.lastOperation = user.opc;
    user = menuOperacao(user);
    return user;
}

void resPrint(tOperando user) {
    printf("Resultado\n");
    printf("Operacao n: %d\n", user.count);
    printf("\t'A' + 'B' = 'C'\n");
    if (user.opc == 1) {
        printf("%f + %f = %f", user.a, user.b, user.res);
    } else if (user.opc == 2) {
        printf("%f - %f = %f", user.a, user.b, user.res);
    } else if (user.opc == 3) {
        printf("%f * %f = %f", user.a, user.b, user.res);
    } else if (user.opc == 4) {
        printf("%f / %f = %f", user.a, user.b, user.res);
    }
}

int main() {
    tOperando oop;
    oop.a = 0;
    oop.b = 1;
    oop.count = 0;
    oop.lastOperation = 0;
    oop.opc = 0;

    do {
        oop = menu(oop);
        if (oop.b != 0) {
            resPrint(oop);
            oop.a = oop.res;
        }
        printf("\n\n\n\n");
    } while (oop.b != 0);

    printf("In the End!!!");
    return 0;
}