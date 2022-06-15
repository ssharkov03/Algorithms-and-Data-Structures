#include <stdio.h>
#define K 2001
int main() {
    int n, elem;
    int count = 0;
    int b[K] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; ++i){
        scanf("%d", &elem);
        b[elem + 1000] += 1;
    }
    for (int i = 0; i < K; ++i){
        if (b[i] != 0){
            count += 1;
        }
    }
    printf("%d", count);
    return 0;
}