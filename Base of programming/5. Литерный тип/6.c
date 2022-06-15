#include <stdio.h>
#define SIZE 100000


void reverse(int a[SIZE], int x, int y, int n){
    int temp;
    for (int i = x; i < (y - x) / 2 + x; ++i){
        temp = a[i];
        a[i] = a[x + y - (i + 1)];
        a[x + y - (i + 1)] = temp;
    }
}



void print_arr(int a[SIZE], int n){
    for (int i = 0; i < n; ++i) {
        printf("%c ", (char) a[i]);
    }
}

void next_permut(int a[SIZE], int n){
    int left = -1;
    for (int i = n - 2; i >= 0; --i){
        if (a[i] < a[i + 1]){
            left = i;
            break;
        }
    }
    if (left == -1){
        reverse(a, 0, n, n);
        return;
    }


    int min_good_el = a[left + 1];
    int right = left + 1;
    for (int j = left + 2; j < n; ++j){
        if (a[j] > a[left] && a[j] < min_good_el){
            right = j;
        }
    }
    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;

    reverse(a, left + 1, n, n);

}

int main() {
    int n, check, i = 0, a[27]; char temp;
    scanf("%d", &n);

    scanf("%c", &temp);
    scanf("%c", &temp);
    while (temp != '\n'){

        if (temp != ' '){
            a[i] = (int) temp;
            ++i;
        }

        scanf("%c", &temp);
    }
    next_permut(a, n);
    print_arr(a, n);

    return 0;
}
