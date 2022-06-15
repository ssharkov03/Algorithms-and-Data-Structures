#include <stdio.h>
#include <stdlib.h>

int arr[10000001];

void shell_sort(int n) {
    for (int step = n / 2; step > 0; step /= 2) {
        for (int i = step; i < n; ++i) {
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
                // swap arr[j], arr[j + step]
                int tmp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = tmp;
            }
        }
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n;++i){
        scanf("%d", &arr[i]);
    }
    shell_sort(n);
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }

    return 0;
}
