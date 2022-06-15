#include <stdio.h>
#define SIZE 100000
#define N 301
#define M 90601


int a[M][2];

int is_function(int m){



    int not_free_x[N] = {0};
    for (int pair = 0; pair < m; ++pair){
        if (not_free_x[a[pair][0]] != 0){
            return 0;
        }
        else{
            not_free_x[a[pair][0]] += 1;
        }
    }
    return 1;
}

int is_defined(int n, int m, int is_func){

    if (is_func == 0){
        return 0;
    }

    int no_such_y;
    for (int x = 1; x <= n; ++x){
        no_such_y = 1;
        for (int pair = 0; pair < m; ++pair){
            if (a[pair][0] == x){
                no_such_y = 0;
                break;
            }
        }
        if (no_such_y == 1){
            return 0;
        }
    }
    return 1;
}


int is_injection(int m, int is_func){

    if (is_func == 0){
        return 0;
    }

    int different_y[N] = {0};
    for (int pair = 0; pair < m; ++pair){
        if (different_y[a[pair][1]] != 0){
            return 0;
        }
        else{
            different_y[a[pair][1]] += 1;
        }
    }
    return 1;
}


int is_surjection(int n, int m, int is_func){

    if (is_func == 0){
        return 0;
    }

    int no_such_x;
    for (int y = 1; y <= n; ++y){
        no_such_x = 1;
        for (int pair = 0; pair < m; ++pair){
            if (a[pair][1] == y){
                no_such_x = 0;
                break;
            }
        }
        if (no_such_x == 1){
            return 0;
        }
    }
    return 1;
}


int is_bijection(int is_inj, int is_surj){
    if (is_inj * is_surj == 1){
        return 1;
    }
    return 0;
}



int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i){
        scanf("%d%d", &a[i][0], &a[i][1]);
        if (a[i][0] > n || a[i][1] > n || a[i][0] < 1|| a[i][1] < 1){
            printf("0");
            return 0;
        }


    }

    int features[5] = {0};
    features[0] = is_function(m);
    features[1] = is_defined(n, m, features[0]);
    features[2] = is_injection(m, features[0]);
    features[3] = is_surjection(n, m, features[0]);
    features[4] = is_bijection(features[2], features[3]);

    int is_zero = 1;
    for (int i = 0; i < 5; ++i){
        if (features[i] != 0){
            printf("%d ", i + 1);
            is_zero = 0;
        }
    }
    if (is_zero){
        printf("0");
    }

    return 0;
}