#include <stdio.h>
#include <math.h>
int power_of_10(int n){
    int s = 1;
    for (int i = 0; i < n; i++){
        s *= 10;
    }
    return s;
}

int main() {
    int pos;
    scanf("%d", &pos);
    if (pos == 0){
        printf("0");
        return 0;
    }
    int len = 1;
    // 9 + 90 * 2 + 900 * 3 + ...
    while (pos - 9 * power_of_10(len - 1) * len > 0) {
        pos -= 9 * power_of_10(len - 1) * len;
        len += 1;
    }
    /*
    len - rank
    pos - position in string
    pos / len  - number in rank (count from 1)
    pos / (pos / len) - pos in number
    */

    pos = pos - 1;

    int pos_in_number = pos % len + 1;
    int rank = power_of_10(len - 1);
    int number = rank + pos / len;

    int RESULT = (number / power_of_10(len - pos_in_number)) % 10;
    printf("%d", RESULT);
    //printf("\n %d %d %d %d %d", len, pos, pos/(pos/len), rank, number);
    return 0;
}