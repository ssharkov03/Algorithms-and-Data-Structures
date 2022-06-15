#include <stdio.h>
#define N 100001
#define K 10001
int main() {
    int n;
    scanf("%d", &n);
    int a[N];
    int b[K] = {0};

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);

    }

    for (int i = 0; i < n; ++i){
        b[a[i]] += 1;
    }
    for (int i = 0; i < K; ++i){
        if (b[i] != 0){
            printf("%d: %d\n", i, b[i]);
        }
    }
    return 0;
}