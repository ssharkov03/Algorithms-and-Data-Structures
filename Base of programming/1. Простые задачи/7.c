#include <stdio.h>
#include <math.h>

int main()

{
    int H, M, S, K;
    scanf("%d%d%d%d", &H, &M, &S, &K);
	// (S + K) / 60) seconds added
	// (M + ((S + K) / 60) / 60) minutes added
    H = (H + ((M + ((S + K) / 60)) / 60)) % 24;   
	M = (M + ((S + K) / 60)) % 60;
	S = (S + K) % 60;
	printf("%d %d %d", H, M, S);
    return 0;
}