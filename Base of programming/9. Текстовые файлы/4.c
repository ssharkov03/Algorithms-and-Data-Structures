#include <stdio.h>
#define N 128


int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int quantity[N] = {0};

    unsigned char current_symbol;
    while (scanf("%c", &current_symbol) == 1){
        quantity[(int) current_symbol] += 1;
    }

    for (int i = 32; i < 127; ++i) {
        if (quantity[i] > 0) {
            printf("%c ", i);
            for (int j = 0; j < quantity[i]; ++j) {
                printf("#");
            }
            printf("\n");
        }
    }
    return 0;
}