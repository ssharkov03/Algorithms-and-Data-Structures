#include <stdio.h>
#define MAX_LIMIT 100


int main()
{

    char first_word[MAX_LIMIT], cur_word[MAX_LIMIT];
    int print;

    scanf("%s", first_word);

    while (scanf("%s", cur_word) == 1){
        print = 1;
        for (int i = 0; cur_word[i]; ++i){
            for (int j = 0; first_word[j]; ++j){
                if (cur_word[i] == first_word[j]){
                    print = 0;
                    break;
                }
            }
            if (print == 0){
                break;
            }
        }

        if (print == 1){
            printf("%s\n", cur_word);
        }
    }

    return 0;
}