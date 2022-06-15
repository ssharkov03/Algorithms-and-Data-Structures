#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

void quicksort(int number[SIZE],int first,int last){
    int i, j, pivot, temp;

    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }

        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);

    }
}

void print_arr(int a[SIZE], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int numbers[SIZE];
    int current_position = 0;
    int current_number;
    while (scanf("%d", &current_number) == 1){
        numbers[current_position] = current_number;
        current_position += 1;
    }

    quicksort(numbers, 0, current_position - 1);
    //print_arr(numbers, current_position);

    if (current_position == 1){
        printf("NO");
        return 0;
    }
    int difference = numbers[1] - numbers[0], next_difference;
    for (int i = 2; i < current_position; ++i){
        next_difference = numbers[i] - numbers[i - 1];
        if (next_difference != difference){
            printf("NO");
            return 0;
        }
    }
    printf("%d", difference);

    return 0;
}
