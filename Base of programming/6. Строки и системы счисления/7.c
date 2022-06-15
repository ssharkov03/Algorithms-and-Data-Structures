#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 1000001

void print_letter(int N){
    if (N <= 9 && N >= 0){
        printf("%c", '0' + N);
        return;
    }
    printf("%c", 'a' + N - 10);
}

int str[MAX_LIMIT] = {0};
int main()
{



    int b, n;
    scanf("%d%d", &b, &n);


    if (n == 0){
        printf("0");
        return 0;
    }

    int iteration = -1;
    while (n > 0) {
        str[iteration] = n % b;
        n = n / b;
        iteration -= 1;
    }

    for (int i = iteration + 1; i < 0; ++i){
        print_letter(str[i]);
    }
    //for (int i = iteration + 1; i < MAX_LIMIT; ++i){
    //
    //}
    return 0;
}
