#include <stdio.h>
#include <math.h>
int is_prime(int n) {
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i < (int)(sqrt(n)) + 1; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    if (is_prime(n) == 0)
        printf("NO");
    else
        printf("YES");
    return 0;
}