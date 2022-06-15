#include <stdio.h>
#include <math.h>
int main()

{
    double a;
    int b;
    
    scanf("%lf%d", &a, &b);
    int res = floor(a / b);
    int res1 = ceil(a / b);
    int res2 = a / b;
    int res3 = ((int) a % b >= 0)?((int)a % b):(b + (int)a % b);
    printf("%d %d %d %d", res, res1, res2, res3);
    return 0;
}