#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100

int check_if_letter_or_space(char x){
    if (x < 'A' || x > 'Z'){
        if (x != ' '){
            return 0;
        }
    }
    return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char stop_words[MAX_LIMIT][MAX_LIMIT];


    char set_from_text[MAX_LIMIT][MAX_LIMIT];
    int corresponding_quantity[MAX_LIMIT]={0};
    int num_words = 0, num_stop_words = 0;

    char current_symbol;
    char cur_string[MAX_LIMIT];

    do {
        scanf("%s", cur_string);
        strupr(cur_string);
        strcpy(stop_words[num_stop_words], cur_string);
        num_stop_words += 1;
        scanf("%c", &current_symbol);

    }while (current_symbol != '\n');



    while (scanf("%s", cur_string) == 1){
        strupr(cur_string);

        // remove punctuation

        for (int i = 0; cur_string[i]; ++i){
            if (check_if_letter_or_space(cur_string[i]) != 1){
                strcpy(&cur_string[i], &cur_string[i + 1]);
                i -= 1;
            }

        }

        // check if in stop words
        int is_stop_word = 0;
        for (int i = 0; i < num_stop_words; ++i){
            if (strcmp(cur_string, stop_words[i]) == 0){
                is_stop_word = 1;
                break;
            }
        }
        if (is_stop_word == 1){
            continue;
        }


        int idx = 0;
        int has_pair = 0;
        // check if string is already in set
        for (idx = 0; idx < num_words; ++idx){
            if (strcmp(cur_string, set_from_text[idx]) == 0){
                corresponding_quantity[idx] += 1;
                has_pair = 1;
                break;
            }
        }
        //add string to set if there is no one
        if (has_pair == 1){
            continue;
        }

        num_words += 1;
        strcpy(set_from_text[idx], cur_string);
        corresponding_quantity[idx] = 1;


    }
    int max_count_idx = 0;
    int max_count = 0;
    for (int i = 0; i < num_words; ++i){
        if (corresponding_quantity[i] > max_count){
            max_count_idx = i;
            max_count = corresponding_quantity[i];
        }
        //printf("The word %s appears %d times\n", set_from_text[i], corresponding_quantity[i]);
    }
    printf("%s", set_from_text[max_count_idx]);



    return 0;
}