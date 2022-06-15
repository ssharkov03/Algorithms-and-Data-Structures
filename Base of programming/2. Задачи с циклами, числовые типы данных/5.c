#include <stdio.h>
#include <math.h>


int reverse(int n, int len){
    int new_num = 0;

    while (n > 0){
        new_num = new_num * 10 + (n % 10);
        n /= 10;
    }

    return new_num;
}



int main() {
    int n;
    scanf("%d", &n);
    printf("%d", reverse(n, 1));
    return 0;
}