#include <stdio.h>
/*
int main(void) {
    printf("????\n");
}
*/
/*
int main(void) {
    for (int i = 0; i < 4; i++) {
        printf("?");
    }
    printf("\n");
}
*/
int main(void) {
    // for each row
    for (int i = 0; i < 3; i++) {
        // for each column
        for (int i = 0; i < 3; i++) {
            printf("#");
        }
        printf("\n");
    }
}