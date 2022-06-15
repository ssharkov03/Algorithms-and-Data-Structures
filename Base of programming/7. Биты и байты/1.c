#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cur_number = 0, n = 0;
    char cur_bit;

    scanf("%d", &n);
    scanf("%c", &cur_bit);
    for (int i = 0; i < n; ++i){
        scanf("%c", &cur_bit);
        cur_number += (cur_bit - '0') * (1 << i % 8);
        if ((i + 1) % 8 == 0 && i > 0){
            printf("%d ", cur_number);
            cur_number = 0;
        }
    }
    if (n % 8 == 0){
        return 0;
    }
    printf("%d", cur_number);
    return 0;
}