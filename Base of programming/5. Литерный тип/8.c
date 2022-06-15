#include <stdio.h>

int is_number(unsigned char n) {
    if (n >= '0' && n <= '9') {
        return 1;
    }
    return 0;
}

int main() {
    unsigned char cur, next;
    int ready_to_exit = 0;

    while (scanf("%c", &cur) == 1) {

        if (cur == '/') {
            if (scanf("%c", &next) == 1 && next == '/') {
                while (scanf("%c", &cur) == 1 && cur != '\n') {
                    continue;
                }
                printf("\n");
                continue;

            } else {
                if (next == '*') {
                    ready_to_exit = 0;
                    while (scanf("%c", &cur) == 1 && (cur != '/' || ready_to_exit == 0)) {
                        if (cur == '\n') {
                            printf("\n");
                        }
                        if (cur == '*') {
                            ready_to_exit = 1;
                        } else {
                            ready_to_exit = 0;
                        }
                    }
                    continue;

                } else {
                    printf("%c%c", cur, next);
                    continue;
                }
            }
        }
        printf("%c", cur);
    }

    return 0;
}