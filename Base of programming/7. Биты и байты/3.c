#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 21

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    unsigned int number;
    scanf("%d", &number);
    unsigned int copy = number;
    int power = 1;
    unsigned int reversed_number = 0;
    for (int i = 0; i < 32; ++i){

        reversed_number += (copy & 1) * (1 << (32 - i - 1));
        copy >>= 1;

    }

    unsigned int copy_reversed = reversed_number;
    for (int i = 0; i < 32; ++i){
        printf("%d", copy_reversed & 1);
        copy_reversed >>= 1;

    }
    printf("\n%d\n", reversed_number);

    for (int i = 0; i < 32; ++i){
        printf("%d", number & 1);
        number >>= 1;

    }

    return 0;
}