#include <stdio.h>
int is_number(unsigned char n){
    if (n >= '0' && n <= '9'){
        return 1;
    }
    return 0;
}

int main(){
    unsigned char a;
    int cur_number;
    int sum = 0;
    scanf("%c", &a);

    while (a != '.'){
        if (is_number(a)){
            cur_number = a - '0';
            scanf("%c", &a);
            while (a != '.' && is_number(a)){
                cur_number = cur_number * 10 + (a - '0');
                scanf("%c", &a);
            }
            sum += cur_number;
        }
        else{
            scanf("%c", &a);
        }
    }

    printf("%d", sum);

    return 0;

}