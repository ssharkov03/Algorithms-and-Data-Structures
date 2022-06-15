#include <stdio.h>
int main(){
    unsigned char cur;
    int len = 1, second_is_A = 0;
    scanf("%c", &cur);

    int i = 0;
    while (cur != '.'){
        if (cur == 'A' && len == 2){
            second_is_A = 1;
        }
        scanf("%c", &cur);
        ++len;
    }
    if (len == 4 && second_is_A == 1){
        printf("FITS");
    }
    else{
        printf("DOES NOT FIT");
    }
    return 0;

}