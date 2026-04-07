#include <stdio.h>
#include <cs50.h>

/*
int main(void) {
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");
    int z = x + y;

    printf("%i\n", z);
}
*/
int main(void) {
    long dollars = 1;
    while (true) {
        char c = get_char("Here's $%li. Double it and give it to the next person? ", dollars);
        if (c == 'y') {
            dollars *= 2;
        }
        else {
            break;
        }
    }
}