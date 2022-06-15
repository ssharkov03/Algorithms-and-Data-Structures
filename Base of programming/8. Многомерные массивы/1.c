#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 1001

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


    fill_C();

    int N;
    scanf("%d", &N);

    int n, k;
    for (int i = 0; i < N; ++i){
        scanf("%d%d", &n, &k);
        double C_n_k = m[n][k];
        printf("%0.10g\n", C_n_k);
    }
    return 0;
}