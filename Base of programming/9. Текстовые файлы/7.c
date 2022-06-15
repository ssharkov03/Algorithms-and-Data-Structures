#include <stdio.h>
#include <string.h>
#define MAX 3000002

char all_symbols[MAX];
int positions[MAX];


int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    positions[0] = -1;
    int current_line_index = 1;
    int current_symbol_index = 0;

    unsigned char current_symbol;
    while (scanf("%c", &all_symbols[current_symbol_index]) == 1){
        if (all_symbols[current_symbol_index] == '\n'){
            positions[current_line_index] = current_symbol_index;
            current_line_index += 1;
        }
        current_symbol_index += 1;
    }
    int left_boarder, right_boarder, was_here = 0;
    for (int left = current_line_index - 1; left >= 0; left -= 1){
        left_boarder = positions[left];
        right_boarder = positions[left + 1];
        was_here = 0;
        for (int symbol = left_boarder + 1; symbol < right_boarder; ++symbol){
            printf("%c", all_symbols[symbol]);
            was_here = 1;
        }
        if (was_here == 1){
            printf("\n");
        }
    }



    return 0;
}