#include <stdio.h>
int main(){
    unsigned char cur;
    long long sum_of_characters = 0;
    int last;
    int current_number;
    scanf("%c", &cur);
    if (cur == '.'){
        printf("NO");
        return 0;
    }


    while (cur != '.'){

        //printf("%c", cur);
        current_number = cur - '0';
        sum_of_characters += current_number;
        last = current_number;

        scanf("%c", &cur);
    }
    if (((last == 0)||(last == 5)) && sum_of_characters % 3 == 0){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;

}