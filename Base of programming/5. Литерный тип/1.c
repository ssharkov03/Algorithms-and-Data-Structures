#include <stdio.h>
int main(){
    unsigned char cur;
    scanf("%c", &cur);
    if (cur == 'M'){
        printf("1");
        return 0;
    }
    if (cur == 'W'){
        printf("3");
        return 0;
    }
    if (cur == 'F'){
        printf("5");
        return 0;
    }
    if (cur == 'T'){
        scanf("%c", &cur);
        if (cur == 'u'){
            printf("2");
            return 0;
        }
        else{
            printf("4");
            return 0;
        }
    }
    if (cur == 'S'){
        scanf("%c", &cur);
        if (cur == 'a'){
            printf("6");
            return 0;
        }
        else{
            printf("7");
            return 0;
        }
    }
    return 0;

}