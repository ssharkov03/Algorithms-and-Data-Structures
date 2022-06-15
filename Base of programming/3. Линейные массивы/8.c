#include <stdio.h>
#include <math.h>

#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))


int main() {
    int n, k, temp;
    int a[100000];

    scanf("%d%d", &n, &k);

    k = k % n;

    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= n / 2 - 1; ++i){
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    for (int i = 0; i <= k / 2 - 1; ++i){
        temp = a[i];
        a[i] = a[k - i - 1];
        a[k - i - 1] = temp;
    }

    for (int i = k; i <= (n - k) / 2 + k - 1; ++i){
        temp = a[i];
        a[i] = a[n + k - (i + 1)];
        a[n + k - (i + 1)] = temp;
    }

    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }

    return 0;
}