#include <stdio.h>

int main()

{
    int k, x;
    scanf("%d%d", &k, &x);
    char option[20];
    if (x < k && x >= 0)
        printf("legal");
    else
        printf("out of bounds");
    
    return 0;
}
