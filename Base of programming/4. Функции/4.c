#include <stdio.h>
#include <math.h>
#define SIZE 100000

void print_arr(int a[SIZE], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

void select_sort(int a[SIZE], int n){
    int t;
    int minim, minim_idx;

    for (int i = 0; i < n; ++i){
        minim = a[i];
        minim_idx = i;
        for (int j = i + 1; j < n; ++j){
            if (minim > a[j]){
                minim = a[j];
                minim_idx = j;
            }
        }
        t = a[i];
        a[i] = minim;
        a[minim_idx] = t;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int a[SIZE];
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    select_sort(a, n);
    print_arr(a, n);
    return 0;
}