#include <stdio.h>
#define N 1000000
int a[N];

int main(){

    int x, pos = 0, n;
    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    while (n != 1){
        if (a[pos + n / 2] <= x){
            pos += n / 2;
            n -= n / 2;
        }
        else{
            n -= n / 2 + 1 * (n % 2 == 1) ;
        }
    }
    if (a[pos] != x){
        printf("-1");
    }
    else{
        printf("%d", pos);
    }
    return 0;
}