#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 100

double m[MAX_LIMIT][MAX_LIMIT] = {0};

void print_matrix(){
    for (int i = 0; i < MAX_LIMIT; ++i){
        for (int j = 0; j < MAX_LIMIT; ++j){
            printf("%0.1lg", m[i][j]);
        }
        printf("\n");
    }
}


void fill_C(){
    for (int i = 0; i < MAX_LIMIT; ++i){
        m[i][i] = 1;
        m[i][0] = 1;
    }
    for (int n = 2; n < MAX_LIMIT; ++n){
        for (int k = 1; k < n; ++k){
            m[n][k] = m[n - 1][k - 1] + m[n - 1][k];
        }
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    int matrix[MAX_LIMIT][MAX_LIMIT] = {0};


    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    int elem, cur_len;
    for (int row = 0; row < N; ++row){
        elem = 0;
        while (elem < M){
            cur_len = 0;
            while (matrix[row][elem] == 1 && elem < M){
                cur_len += 1;
                elem += 1;
            }
            if (cur_len){
                printf("%d ", cur_len);
            }
            elem += 1;
        }
        printf("\n");
    }
    for (int col = 0; col < M; ++col){
        elem = 0;
        while (elem < N){
            cur_len = 0;
            while (matrix[elem][col] == 1 && elem < N){
                cur_len += 1;
                elem += 1;
            }
            if (cur_len){
                printf("%d ", cur_len);
            }
            elem += 1;
        }
        printf("\n");
    }
    return 0;
}