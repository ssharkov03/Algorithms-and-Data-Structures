#include <stdio.h>
#include <math.h>


int main() {
    double eps, x, y = 0, cur_x;
    // 𝑦 = 𝑎𝑟𝑐𝑡𝑔(𝑥) = 𝑥 − 𝑥^3/3 + 𝑥^5/5 − ... +(−1)^𝑛 * 𝑥^(2n -1) / (2n - 1) + ...
    scanf("%lf%lf", &x, &eps);

    int n = 1;
    double cur = x;
    while (cur >= eps) {
        if (n % 4 == 3)
            y -= cur;
        else
            y += cur;
        n += 2;
        cur = (cur * x * x * (n - 2)) / n;
        //printf("%0.5lf %0.5lf\n", cur, y);

    }
    if (n % 4 == 3)
        y -= cur;
    else
        y += cur;
    printf("%0.5lf", y);
    return 0;
}