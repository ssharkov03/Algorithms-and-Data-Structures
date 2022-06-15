#include <stdio.h>
#include <math.h>

int days_in_month_not_vis[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_in_month_vis[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int write_errors(int d, int m, int y){

    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        if (d > days_in_month_vis[m - 1]){
            return 1;
        }
    }
    else {
        if (d > days_in_month_not_vis[m - 1]) {
            return 1;
        }
    }

    if (y > 2050 || y < 1){
        return 1;
    }
    if (m > 12 || m < 1){
        return 1;
    }

    return 0;
}



int main() {

    int d1, m1, y1, total_days_1;
    int d2, m2, y2, total_days_2;

    // if y % 4 == 0 and y % 100 != 0 || y % 400 == 0

    scanf("%d%d%d%d%d%d", &d1, &m1, &y1, &d2, &m2, &y2);

    //error in date
    if (write_errors(d1, m1, y1) == 1 || write_errors(d2, m2, y2) == 1){
        printf("ERROR");
        return 0;
    }


    // days in y1 years
    total_days_1 = 365 * y1 + ((y1 - 1) / 4 - (y1 - 1) / 100 + (y1 - 1) / 400);
    total_days_1 += d1;
    if (y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0){
        for (int m = 0; m < m1 - 1; ++m){
            total_days_1 += days_in_month_vis[m];
        }
    }
    else{
        for (int m = 0; m < m1 - 1; ++m){
            total_days_1 += days_in_month_not_vis[m];
        }
    }

    // days in y2 years
    total_days_2 = 365 * y2 + ((y2 - 1) / 4 - (y2 - 1) / 100 + (y2 - 1) / 400);
    total_days_2 += d2;
    if (y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0){
        for (int m = 0; m < m2 - 1; ++m){
            total_days_2 += days_in_month_vis[m];
        }
    }
    else{
        for (int m = 0; m < m2 - 1; ++m){
            total_days_2 += days_in_month_not_vis[m];
        }
    }

    if (total_days_2 < total_days_1){
        printf("%d", total_days_1 - total_days_2);
    }
    else{
        printf("%d", total_days_2 - total_days_1);
    }


    return 0;
}