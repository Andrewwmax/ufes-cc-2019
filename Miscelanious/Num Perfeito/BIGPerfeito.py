from functools import lru_cache

@lru_cache(maxsize=None)
def isPerfect(n):
	soma = 1
	for i in range(2,n):
		if (n % i) == 0:
			soma += i + (n / i)
			if((soma == n) and (n != 1)):
				print(i, "Eh Perfeito: ", n)

def main() -> None:
	for i in range(2, 20):
		soma = 1 + (((2**i) - 2) * ((2**i) + 1) / 2)
		isPerfect(int(soma))
		# print(soma)


if __name__ == '__main__':
	main()
	print(isPerfect.cache_info())