#include <stdio.h>
#include <math.h>
int surface_area(int a, int b, int c){
    return 2*(a*b + a*c + b*c);
}


int main()

{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x <= 0)
        printf("%d", -1);
    else
        if (y <= 0)
            printf("%d", -2);
        else
            if (z <= 0)
                printf("%d", -3);
            else    
                printf("%d", surface_area(x, y, z));
    
    return 0;
}