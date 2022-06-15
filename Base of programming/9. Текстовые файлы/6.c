#include <stdio.h>
#include <string.h>
#define N 1010
#define word_size 1010

unsigned char strings[N][word_size];

int main(){

    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");


    int n = 0;
    while (fgets(strings[n], word_size, input) != NULL){
        n += 1;
    }
    for (int i = n - 1; i >= 0; i -= 1){
        fprintf(output, "%s\n", strings[i]);
    }
    fclose(output);
    return 0;
}