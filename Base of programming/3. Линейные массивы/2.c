#include <stdio.h>
#define N 100001
int main() {
    int n;

    scanf("%d", &n);
    int result[N];
    for (int i = 1; i <= n; ++i){
        scanf("%d", &result[i]);


    }
    for (int j = 1; j <= n; ++j){
        for (int i = j * 2; i <= n; i += j){
            result[j] += result[i];
        }
        printf("%d\n", result[j]);
    }
    return 0;
}