#include <stdio.h>
#include <string.h>
#define N 50001

typedef struct DateTime_s {
    int year , month , day;
    int hours , minutes , seconds ;
} DateTime ;

DateTime min(const DateTime *arr , int cnt){
    DateTime min;
    min.year = 100000;
    min.month = 10000;
    min.day = 10000;
    min.hours = 10000;
    min.minutes = 1000;
    min.seconds = 1000;

    for (int i = 0; i < cnt; ++i){
        if (arr[i].year < min.year){
            min = arr[i];
        }
        else{
            if (arr[i].year == min.year && arr[i].month < min.month){
                min = arr[i];
            }
            else{
                if (arr[i].year == min.year && arr[i].month == min.month && arr[i].day < min.day){
                    min = arr[i];
                }
                else{
                    if (arr[i].year == min.year && arr[i].month == min.month && arr[i].day == min.day && arr[i].hours < min.hours){
                        min = arr[i];
                    }
                    else{
                        if (arr[i].year == min.year && arr[i].month == min.month && arr[i].day == min.day && arr[i].hours == min.hours && arr[i].minutes < min.minutes){
                            min = arr[i];
                        }
                        else{
                            if (arr[i].year == min.year && arr[i].month == min.month && arr[i].day == min.day && arr[i].hours == min.hours && arr[i].minutes == min.minutes && arr[i].seconds < min.seconds){
                                min = arr[i];
                            }
                        }
                    }
                }
            }
        }
    }

    return min;
}

DateTime datetimes[50001];

int main() {
    int n;
    scanf("%d", &n);
    DateTime cur_date;
    for (int i = 0; i < n; ++i){
        scanf("%d%d%d%d%d%d", &datetimes[i].year, &datetimes[i].month, &datetimes[i].day, &datetimes[i].hours, &datetimes[i].minutes, &datetimes[i].seconds);
    }

    cur_date = min(datetimes, n);
    printf("%d %d %d %d %d %d", cur_date.year, cur_date.month, cur_date.day, cur_date.hours, cur_date.minutes, cur_date.seconds);
    return 0;
}