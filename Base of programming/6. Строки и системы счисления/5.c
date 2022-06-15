#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100



void reverse(char *start, int len){
    char temp;
    int corresponding_index = len - 1;
    for (int i = 0; i < len / 2; ++i){
        temp = start[i];
        start[i] = start[corresponding_index];
        start[corresponding_index] = temp;

        corresponding_index -= 1;

    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char word[MAX_LIMIT];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i){
        //fgets(word, sizeof word, stdin);
        scanf("%s", word);
        reverse(word, strlen(word));
        printf("%s\n", word);
    }
    return 0;
}