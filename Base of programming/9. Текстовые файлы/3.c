#include <stdio.h>
#include <string.h>
#define N 256
#define word_size 100


int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int number_of_lines = 0;

    unsigned char current_symbol;
    while (scanf("%c", &current_symbol) == 1){
        if (current_symbol == '\n'){
            number_of_lines += 1;
        }
    }

    printf("%d", number_of_lines);
    return 0;
}