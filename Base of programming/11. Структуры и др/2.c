#include <stdio.h>
#include <string.h>

typedef struct Label_s {
    char name [16]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
} Label ;

typedef struct NameStats_s {
    int cntTotal ; //сколько всего подписей
    int cntLong ; //сколько подписей с именами длиннее 10 букв
} NameStats ;

typedef struct AgeStats_s {
    int cntTotal ; //сколько всего подписей
    int cntAdults ; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids ; //сколько подписей детей (меньше 14 лет)
} AgeStats ;


void calcStats ( const Label * arr , int cnt , NameStats * oNames , AgeStats * oAges ){

    oNames->cntTotal = cnt;
    oNames->cntLong = 0;
    oAges->cntTotal = cnt;
    oAges->cntAdults = 0;
    oAges->cntKids = 0;

    for (int i = 0; i < cnt; ++i){
        if (strlen(arr[i].name) > 10) {
            oNames->cntLong += 1;
        }
        if (arr[i].age >= 18) {
            oAges->cntAdults += 1;
        }
        if (arr[i].age < 14) {
            oAges->cntKids += 1;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Label people[1001];
    char tmp[3];
    NameStats name_stats;
    int cnt = n;
    AgeStats age_stats;


    for (int i = 0; i < n; ++i) {
        scanf("%s%d%s", people[i].name, &people[i].age, tmp);
    }
    calcStats(people, cnt, &name_stats, &age_stats);
    printf("names: total = %d\nnames: long = %d\nages: total = %d\nages: adult = %d\nages: kid = %d",
           name_stats.cntTotal, name_stats.cntLong, age_stats.cntTotal, age_stats.cntAdults, age_stats.cntKids);

    return 0;
}
