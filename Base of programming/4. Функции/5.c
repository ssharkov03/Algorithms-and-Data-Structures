#include <stdio.h>
#include <math.h>
#define SIZE 100000

void print_arr(int a[SIZE], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

void shake_sort(int a[SIZE], int n){
    int t, count_of_swaps = 1;
    while (count_of_swaps != 0){
        count_of_swaps = 0;
        for (int i = 1; i < n; ++i){
            if (a[i] < a[i - 1]){
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                count_of_swaps += 1;
            }
        }
        if (count_of_swaps == 0){
            break;
        }
        count_of_swaps = 0;
        for (int i = n - 1; i >= 1; --i){
            if (a[i] < a[i - 1]){
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                count_of_swaps += 1;
            }
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int a[SIZE];
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    shake_sort(a, n);
    print_arr(a, n);
    return 0;
}