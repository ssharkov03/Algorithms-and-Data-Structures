#include <stdio.h>
#include <stdlib.h>
int arr[1000000];


void quick_sort(int left, int right){

    int i = left, j = right, x = arr[(left + right) / 2];

    do {
        while (arr[i] < x)
            i++;
        while (arr[j] > x)
            j--;

        if(i <= j) {
            if (arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < right)
        quick_sort(i, right);
    if (left < j)
        quick_sort(left, j);

}



int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n;++i){
        scanf("%d", &arr[i]);
    }
    quick_sort(0, n-1);
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }

    return 0;
}


