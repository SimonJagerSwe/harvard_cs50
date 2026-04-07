#include <stdio.h>
#include <cs50.h>


/*
int main(void) {
    int i = 3;
    while (i > 0) {
        printf("Meow\n");
        i --;
    }
}
*/
/*
int main(void) {
    int n = get_int("What's n? ");
    for (int i = 0; i < n; i++) {
        printf("Meow\n");
    }
}
*/
/*
int main(void) {
    int n;
    while (true) {
        n = get_int("What's n? ");
        if (n < 0) {
            continue;
        }

        else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Meow\n");
        
    }
}
*/
int main(void) {
    int n;
    do {
        n = get_int("What's n? ");
    }
    while (n < 0);

    for (int i = 0; i < n; i++) {
        printf("Meow\n");
    }
}