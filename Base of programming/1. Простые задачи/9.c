#include <stdio.h>
#include <math.h>
int main()

{
    double N, M, P, K, L;
    
    scanf("%lf%lf%lf%lf%lf", &N, &M, &P, &K, &L);

	double q; // кол-во квартир на этаже
	// L * q - n квартир во всем подьезде

	q = ceil(M / ((L*(P - 1) + K))); // M - n квартиры, L * (P - 1) + K - этажей до квартиры всего
	
	// вычисляем подъезд квартиры N
	int p = ceil(N/(L*q));
	
	// вычисляем этаж кввартиры N  
	int N1 = N - (p - 1)*L*q; // если предствить, что дом - единственный
	int f = ceil(N1/q);

	printf("%d %d", p, f);
	return 0;
}