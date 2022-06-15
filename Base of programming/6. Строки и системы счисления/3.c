#include <stdio.h>
#define MAX_LIMIT 30

void print_seq(int a, int b){
    if (a <= b){
        printf("%d %d", a + 1, b + 1);
    }
    else{
        printf("%d %d", b + 1, a + 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char A_str[MAX_LIMIT], B_str[MAX_LIMIT];
    int arr[MAX_LIMIT] = {0};

    scanf("%s%s", A_str, B_str);
    for (int i = 0; A_str[i]; ++i){
        arr[A_str[i] - 'A'] = 1;
    }
    for (int i = 0; B_str[i]; ++i){
        arr[B_str[i] - 'A'] -= 1;
    }
    int empty = 1;
    for (int i = 0; i < MAX_LIMIT; ++i){
        if (arr[i] == 1){
            printf("%c", i + 'A');
            empty = 0;
        }
    }
    if (empty == 1){
        printf("Empty Set");
    }
    return 0;
}