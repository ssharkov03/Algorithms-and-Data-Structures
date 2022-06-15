#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 1000001

int to_int(char N){
    if (N <= '9' && N >= '0'){
        int s = N - '0';
        return N - '0';
    }
    else{
        return N - 'a' + 10;
    }
}

char str[MAX_LIMIT];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int b;
    scanf("%d", &b);
    scanf("%s", str);

    int sum = 0;
    int i;
    for (i = 0; str[i]; ++i){
        sum = sum * b + to_int(str[i]);
    }
    printf("%d", sum - b * str[i]);
    return 0;
}