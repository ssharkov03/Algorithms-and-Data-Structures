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

    int R = 0, Y = 0, B = 0;

    char col[MAX_LIMIT];
    scanf("%s", col);
    char color = col[0]; // big letter

    char opt[MAX_LIMIT];
    scanf("%s", opt);

    for (int i = 0; MAX_LIMIT > i; ++i) {
        if (opt[i] == 'R' && R == 0) {
            R = i;
        }
        if (opt[i] == 'Y' && Y == 0) {
            Y = i;
        }
        if (opt[i] == 'B' && B == 0) {
            B = i;
        }
    }
    if (color == 'p'){
        print_seq(R, B);
    }
    if (color == 'o'){
        print_seq(R, Y);
    }
    if (color == 'g'){
        print_seq(Y, B);
    }


    return 0;
}