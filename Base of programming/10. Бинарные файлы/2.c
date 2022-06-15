#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LIMIT 21

int reverse(unsigned int a){

    unsigned int b = a;
    unsigned int * p = &b;
    char *c = (char*) p;
    char temp;

    temp = c[0];
    c[0] = c[3];
    c[3] = temp;

    temp = c[1];
    c[1] = c[2];
    c[2] = temp;

    return b;
}


int main()
{

    FILE * in, *out;
    in = fopen("input.bin", "rb");
    out = fopen("output.bin", "wb");

    int n;
    fread(&n, sizeof(int), 1, in);

    if (n > 10000){
        int real_n = reverse(n);
        int sum = 0;
        int current_big;
        for (int i = 0; i < real_n; ++i){
            fread(&current_big, sizeof(int), 1, in);
            int current_little = reverse(current_big);
            sum += current_little;
        }
        int formated_sum = reverse(sum);
        fwrite(&formated_sum, sizeof(int), 1, out);
        return 0;
    }
    int sum = 0;
    int current_little;
    for (int i = 0; i < n; ++i){
        fread(&current_little, sizeof(int), 1, in);
        sum += current_little;
    }

    fwrite(&sum, sizeof(int), 1, out);
    return 0;
}