#include <stdio.h>
#include <math.h>
int a[1000001] = {1, 1};
int main() {
    int n;
    scanf("%d", &n);

    for (int k = 2; k <= sqrt(n) ; ++k){
        for (int i = k * k; i <= n; i += k){
            a[i] = 1;
        }
    }
    for (int i = 2; i <= n; ++i){
        if (a[i] == 0){
            printf("%d ", i);
        }
    }
    return 0;
}