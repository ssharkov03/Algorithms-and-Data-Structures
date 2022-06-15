#include <stdio.h>

int main() {
    int base[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &base[i]);
    }
    int result[100] = {0};
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (base[i] > base[j]){
                result[i] += 1;
            }
        }
    }
    for (int i = 0; i < n; ++i){
        printf("%d ", result[i]);
    }
    return 0;
}