#include <stdio.h>
#define SIZE 1000


void print_arr(int a[SIZE], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}


void permut_to_invtab(int a[SIZE], int b[SIZE], int n){

    int t;
    int count;

    int sorted[SIZE];
    for (int i = 0; i < n; ++i){
        sorted[i] = a[i];
    }

    for (int i = 1; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (sorted[i] < sorted[j]){
                t = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = t;
            }
        }
    }
    int number;
    for (int num = 0; num < n; ++num){
        number = sorted[num];
        count = 0;
        for (int i = 0; number != a[i]; ++i){
            if (a[i] > number){
                count += 1;
            }
        }
        b[num] = count;
    }


    print_arr(b, n);


}

int main(){
    int N, a[SIZE], b[SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i){
        scanf("%d", &a[i]);
    }
    permut_to_invtab(a, b, N);
    return 0;
}