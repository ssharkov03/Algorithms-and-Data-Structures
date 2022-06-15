#include <stdio.h>
#include <math.h>


int main() {
    int n, cur;
    double positive = 0, negative = 0, zero = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &cur);
        if (cur > 0){
            positive++;
        }
        else{
            if (cur == 0){
                zero++;
            }
            else{
                negative++;
            }
        }
    }
    printf("%lf %lf %lf", negative / n, zero / n, positive / n);
    return 0;
}