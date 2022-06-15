#include <stdio.h>
#include <math.h>
int main()

{
    double K;
	scanf("%lf", &K);
    /*
Пусть "1" стоит на k-ом месте в последовательности
Пусть число (10 ** (n - 1)), стоящее перед k - длины n
Тогда кол-во символов до k (1) = (1 + 2 + 3 + ... + n) + 1
k = (1 + 2 + 3 + ... + n) + 1
k = (n * (n + 1)) / 2 + 1
2k = n * (n + 1) + 2
n*n + n + (2 - 2k) = 0
d = 1 + 4*(2k - 2)) = 8k - 7
n = (-1 + sqrt(d) / 2
=> если sqrt(d) - не целое число, то значит, что k - не 1
	*/
	double D = 8 * K - 7;
	if (sqrt(D) - (int) sqrt(D) == 0)
		printf("1");
	else
		printf("0");

	return 0;
}