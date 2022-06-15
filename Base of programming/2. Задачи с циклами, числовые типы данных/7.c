#include <stdio.h>
#include <math.h>


int main() {
    int n, min = 10001, max = -10001, cur, num_min = 0, num_max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &cur);
        if (cur < min){
            min = cur;
            num_min = i + 1;
        }
        if (cur > max){
            max  = cur;
            num_max = i + 1;
        }
    }
    printf("%d %d %d %d", min, num_min, max, num_max);
    return 0;
}