#include <stdio.h>
long long gcd(long long a, long long b){
    if (a * b == 0){
        return a + b;
    }
    return gcd(b, a % b);
}

int main(){
    int n;
    long long a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", (a * b) / gcd(a, b));
    }
    return 0;
}