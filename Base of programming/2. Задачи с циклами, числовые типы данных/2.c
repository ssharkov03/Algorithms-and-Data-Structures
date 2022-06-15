#include <stdio.h>
int main() {
    int n, sum = 0, cur;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &cur);
        if (cur % 2 == 0){
            sum += cur;
        }
    }
    printf("%d", sum);
    return 0;
}