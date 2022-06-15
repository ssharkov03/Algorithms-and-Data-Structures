#include <stdio.h>
#include <math.h>


int main() {
    int n, num_min_dif = 0;
    double min_diff = 1, cur, cur_min_diff, diff1, diff2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%lf", &cur);

        diff1 = cur - floor(cur);
        diff2 = ceil(cur) - cur;
        if (diff1 <= diff2)
            cur_min_diff = diff1;
        else
            cur_min_diff = diff2;


        if (cur_min_diff < min_diff){
            min_diff = cur_min_diff;
            num_min_dif = i + 1;
        }
    }
    printf("%d", num_min_dif);
    return 0;
}