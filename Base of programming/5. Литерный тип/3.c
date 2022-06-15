#include <stdio.h>
int main(){
    unsigned char cur;
    unsigned char prev;
    unsigned char before_prev;
    int len = 1;
    scanf("%c%c", &prev, &cur);

    while (cur != '.'){

        printf("%c", prev);
        before_prev = prev;
        prev = cur;
        scanf("%c", &cur);
        ++len;
    }
    if (before_prev == 'e' && prev == 'r'){
        printf("%c%c", 's', 't');
        return 0;
    }
    if (prev == 'e'){
        printf("%c%c",'e', 'r');
        return 0;
    }
    printf("%cer", prev);
    return 0;

}