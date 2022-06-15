#include <stdio.h>
#define MAX_LIMIT 21
int main()
{

    int cur_letter_idx = 0;
    int winner = 1;
    char str[MAX_LIMIT];
    int passed;
    while (scanf("%s", str) == 1){
        passed = 0;
        for (int i = 0; i < MAX_LIMIT; ++i){
            if (str[i] - 'a' == cur_letter_idx){
                winner = cur_letter_idx;
                cur_letter_idx += 1;
                passed = 1;
                break;
            }
        }
        if (passed == 0){
            break;
        }
    }
    if (passed == 1){
        printf("NO WINNER");
    }
    else{
        printf("PLAYER %d", winner % 2 + 1);
    }

    return 0;
}