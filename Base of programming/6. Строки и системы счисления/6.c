#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 1000001
#define STR_LIM 101


char*concat(char*pref, char*suff){

    int pref_len = strlen(pref);
    int suff_len = strlen(suff);


    for (int i = pref_len; i < pref_len + suff_len; ++i){
        pref[i] = suff[i - pref_len];
    }
    return pref + pref_len + suff_len;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char cur[STR_LIM], str[MAX_LIMIT] = {0};

    int n;
    scanf("%d", &n);

    char *resulting_string = str;
    for (int i = 0; i < n; ++i){
        //fgets(word, sizeof word, stdin);
        scanf("%s", cur);
        resulting_string = concat(resulting_string, cur);
    }
    printf("%s", str);
    return 0;
}