#include <stdio.h>
#define N 1000000
double a[N];

int main(){

    int x, pos = 0, n;
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; ++i){
        scanf("%lf", &a[i]);
    }

    while (n != 1){
        double diff_with_left = x - a[pos + n / 2 - 1];
        double diff_with_right = a[pos + n / 2] - x;

        if (diff_with_right < diff_with_left){
            pos += n / 2;
            n -= n / 2;
        }
        else {
            n -= n / 2 + 1 * (n % 2 == 1);
        }
    }
    printf("%d", pos);
    return 0;
}