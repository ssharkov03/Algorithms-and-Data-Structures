#include <stdio.h>
#define N 256


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int quantity[N] = {0};

    unsigned char current_symbol;
    while (scanf("%c", &current_symbol) == 1){
        quantity[(int) current_symbol] += 1;
    }

    for (int i = 12; i < N; ++i){
        if (quantity[i] > 0){
            printf("%d : %c - %d\n", i, i, quantity[i]);
        }
    }

    return 0;
}