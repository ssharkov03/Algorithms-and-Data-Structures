#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 21

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    unsigned int number;
    scanf("%d", &number);

    int cur_bit, cur_max = 0;
    int max_in_a_row = 0;
    while (number != 0){
        cur_bit = number % 2;
        if (cur_bit){
            cur_max += 1;
            if (cur_max > max_in_a_row){
                max_in_a_row = cur_max;
            }
        }
        else{
            cur_max = 0;
        }
        number /= 2;
    }
    printf("%d", max_in_a_row);
    return 0;
}