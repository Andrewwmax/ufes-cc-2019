// exemplo by Cooler_
#include <stdio.h>
#include <math.h>
#include <gmp.h>

int ehPerfeito(mpz_t n) {
    mpz_t i, sum, res, respow, resdiv, ressum;
	mpz_init(i);
	mpz_init(sum);
	mpz_init(res);
	mpz_init(respow);
	mpz_init(resdiv);
	mpz_init(ressum);

	mpz_set_ui(i, 2);
	mpz_set_ui(sum, 1);
    
    for(i; mpz_pow_ui(respow, i, 2), mpz_cmp(respow, n) <= 0; mpz_add_ui(i, i, 1))
        // if(n % i == 0) sum = sum + i + (n / i);
        if(mpz_mod(res, n, i), mpz_cmp(res, 0) == 0) 
        	mpz_div(resdiv, n, i);
        	mpz_add(ressum, i, resdiv);
        	mpz_add(sum, sum, ressum);
	
	if(mpz_cmp(n, sum) && mpz_cmp_ui(n, 1) != 1){
		mpz_clear(respow);
		mpz_clear(res);
		mpz_clear(sum);
		mpz_clear(i);
		return 1;
	}

	return 0; 
} 

int main() {
// var do gmp para trabalhar com signed int
	mpz_t sum, sumPow;
	// mpz_t sum, s1, s2;
// inciando
	mpz_init(sum);
	mpz_init(sumPow);
	// mpz_init(s1);
	// mpz_init(s2);
// mnemônico para atribuição x=y
	// mpz_set_ui(sum,Y);
	
	for (int n = 2; n < 15; n++) {
		// mpz_set(sum, 1 + (mpz_pow_ui (X,X,Y)));
		
		mpz_set_ui(sumPow, 1 + ((pow(2, n) - 2) * (pow(2, n) + 1) / 2));
		mpz_set(sum,sumPow);
		if (ehPerfeito(sum)) gmp_fprintf(stdout,"Eh Perfeito: %Zd\n", sum);
	}
	// for (int n = 2; n < 32; n++) {
	// 	sum = 1 + (mpz_pow_ui (X,X,Y));
	// 	sum = 1 + ((pow(2, n) - 2) * (pow(2, n) + 1) / 2);
	// 	if (ehPerfeito(sum)) printf("Eh Perfeito: %lld\n", sum);
	// }
// mnemônico para soma x+=y
	// mpz_add_ui(X,X,Y);
// 1024^512 qual seria o resultado ?
	// mpz_pow_ui (X,X,Y);

	// gmp_fprintf(stdout,"%Zd  %s\n",X,"legal");
/*
gmp tem um próprio método de OUTPUT
explicando o format string

F         mpf_t, float conversions
Q         mpq_t, integer conversions
M         mp_limb_t, integer conversions
N         mp_limb_t array, integer conversions
Z         mpz_t, integer conversion

para INPUT use o gmp_scanf() e gmp_sscanf()
*/


/*
expoente
mpz_pow (mpz_t ROP, mpz_t BASE, mpz_t EXP)

resto
mpz_mod (mpz_t R, mpz_t N, mpz_t D)

testa se é divisível
int mpz_divisible_p (mpz_t N, mpz_t D)

adição
void mpz_add (mpz_t ROP, mpz_t OP1, mpz_t OP2)

subtração
void mpz_sub (mpz_t ROP, mpz_t OP1, mpz_t OP2)

produto
void mpz_mul (mpz_t ROP, mpz_t OP1, mpz_t OP2)

divisão
void mpz_div (mpz_t ROP, mpz_t OP1, mpz_t OP2)

raiz quadrada
void mpz_sqrt (mpz_t ROP, mpz_t OP)

comparar dois números
int mpz_cmp (mpz_t OP1, mpz_t OP2)
...

OBS: usamos "_ui" com nome da função quando precisamos usar "unsigned int"

*/


// limpando a bagunça
	mpz_clear(sum);

	return 0;
}