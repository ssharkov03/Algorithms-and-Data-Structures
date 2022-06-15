#include <stdio.h>
#include <math.h>
int is_prime(int n) {
    if (n == 1) {
        return 1;
    }
    for (int i = 2; i < (int)(sqrt(n)) + 1; i++) {
        if (n % i == 0) {
            return 1;
        }
    }
    return 0;
}

int print(int n){
    for (int i = 2; i <= n; i++){

        if (is_prime(i) == 0){
            printf("%d ", i);
        }
    }
    return 0;
}



int main() {
    int n;
    scanf("%d", &n);
    print(n);
    return 0;
}