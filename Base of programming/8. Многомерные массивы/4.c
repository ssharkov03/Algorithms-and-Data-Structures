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
int change_out_of_boarders(int x, int y, int n, int m){
    if ((x < 0 || x >= n) || (y < 0 || y >= m)){
        return 1;
    }
    return 0;
}

int change_on_row(int x, char letter){
    if (letter == 'N'){
        return x - 1;
    }
    if (letter == 'S'){
        return x + 1;
    }
    return x;
}

int change_on_col(int y, char letter){
    if (letter == 'E'){
        return y + 1;
    }
    if (letter == 'W'){
        return y - 1;
    }
    return y;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    char map[MAX_LIMIT][MAX_LIMIT] = {0}; // [0] - Letter, [1] - was_here_before?, [2] - at what step was here
    int map_steps[MAX_LIMIT][MAX_LIMIT][2] = {0};


    int N, M, start;
    scanf("%d%d%d", &N, &M, &start);

    char temp;
    scanf("%c", &temp);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            scanf("%c", &map[i][j]);
            map_steps[i][j][0] = -1;
        }
        scanf("%c", &temp);
    }

    map_steps[0][start - 1][0] = 1;

    int x = 0;
    int y = start - 1;

    int exit = 0;
    int is_loop = 0, out_of_boarders = 0, steps = 0;
    char cur_letter;

    while (1){
        cur_letter = map[x][y];
        x = change_on_row(x, cur_letter);
        y = change_on_col(y, cur_letter);

        steps += 1;

        out_of_boarders = change_out_of_boarders(x, y, N, M);

        if (out_of_boarders){
            printf("%d step(s) to exit", steps);
            break;
        }

        if (map_steps[x][y][0] == 1){
            printf("%d step(s) before a loop of %d step(s)", map_steps[x][y][1], steps - map_steps[x][y][1]);
            break;
        }


        map_steps[x][y][0] = 1;
        map_steps[x][y][1] = steps;

    }

    return 0;
}