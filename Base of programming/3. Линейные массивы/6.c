#include <stdio.h>
#include <math.h>
int a[5000];
int pref[5000] = {0};
int main() {
    int n;
    scanf("%d", &n);

    scanf("%d", &a[0]);
    pref[0] = a[0];

    for (int i = 1; i < n; ++i){
        scanf("%d", &a[i]);
        pref[i] = pref[i - 1] + a[i];
    }

    int maximum = a[0];
    int L = 0;
    int R = 0;
    for (int l = 0; l < n - 1; l++){
        for (int r = l + 1; r < n; r++){
            int s = pref[r] - pref[l];
            if (s > maximum){
                maximum = s;
                L = l + 1;
                R = r;
            }
        }
    }
    for (int el = 0; el < n; ++el){
        if (pref[el] > maximum){
            maximum = pref[el];
            L = 0;
            R = el;
        }
    }

    printf("%d %d %d", L, R, maximum);

    return 0;
}