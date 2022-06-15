#include <stdio.h>
#include <math.h>
#define SIZE 100000

void print_arr(int a[SIZE], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

void invtab_to_permut(int b[SIZE], int a[SIZE], int n) {
    int t;
    for (int num = 1; num <= n; ++num) {
        if (b[num - 1] < 0 || b[num - 1] > n - num) {
            printf("NO");
            return;
        }
    }
    int to_pass, place_to_put_in, j;
    for (int num = 0; num < n; ++num) {
        place_to_put_in = 0;
        to_pass = b[num];
        if (to_pass == 0){
            for (int i = 0; i < n; ++i){
                if (a[i] == 0){
                    place_to_put_in = i;
                    break;
                }
            }
        }
        else{
            for (j = 0; to_pass != -1; ++j){
                if (a[j] == 0){
                    to_pass -= 1;
                }
                place_to_put_in = j;
            }

        }
        a[place_to_put_in] = num + 1;
    }

    print_arr(a, n);
}


int main(){
    int N, a[SIZE] = {0}, b[SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i){
        scanf("%d", &b[i]);
    }
    invtab_to_permut(b, a, N);
    return 0;
}