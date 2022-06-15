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

    int n1, n2;
    long long res;
    fread(&n1, sizeof(int), 1, in);
    fread(&n2, sizeof(int), 1, in);

    res = floor((double)((long long) n1 + n2) / 2);
    int real_res = (int) res;
    fwrite(&real_res, sizeof(int), 1, out);
    return 0;
}