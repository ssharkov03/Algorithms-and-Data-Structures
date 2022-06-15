#include <stdio.h>
#define SIZE 100000

//  time limit error!

void print_arr(int a[SIZE], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

void ins_sort(int a[SIZE], int n){
    int t;
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (a[i] < a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main(){
    int N, a[SIZE];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i){
        scanf("%d", &a[i]);
    }
    ins_sort(a, N);
    print_arr(a, N);
    return 0;
}