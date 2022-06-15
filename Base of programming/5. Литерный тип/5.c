#include <stdio.h>
int main(){
    unsigned char cur, prev;
    int count = 0;

    scanf("%c%c", &prev, &cur);
    if (prev != '.'){
        ++count;
    }

    while (cur != '\n'){

        if (cur != '.' && prev == '.' ){
            ++count;
        }
        prev = cur;
        scanf("%c", &cur);
    }
    printf("%d", count);

    return 0;

}