#include <stdio.h>
#include <string.h>
#define N 256
#define word_size 100


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int quantity[N] = {0};

    unsigned char current_word[word_size];
    while (scanf("%s", current_word) == 1){
        quantity[strlen(current_word)] += 1;
    }

    for (int i = 1; i < N; ++i){
        if (quantity[i] > 0){
            printf("%d - %d\n", i, quantity[i]);
        }
    }

    return 0;
}