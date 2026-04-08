// ########## Problemset 1 - Mario (less) ########## //
#include <cs50.h>
#include <stdio.h>


// Functions
int get_rows(void);
void print_rows(int rows);


// Main function
int main(void) {
    // Get number of rows
    int rows = get_rows();
    // Print rows
    print_rows(rows);
}


// Ask user for number of rows and save as variable
int get_rows(void) {
int rows;
// Check if number of rows is valid
do {
rows = get_int("Height: ");
}
while(rows < 0);
// Return valid number of rows
return rows;
}


// Print pyramid
void print_rows(int rows) {
    int space = (rows - 1);
    int block = 1;
    char hash = '#';
    char blank = ' ';
    // Print row
    for (int i = 0; i < rows; ++i) {
        // Print spaces for each row
        for (int i = 0; i < space; i++) {
            putchar(blank);
        }
        // Print hashes for each row
        for (int i = 0; i < block; i++) {
        putchar(hash);
        }
        // Break line, decrease blank spaces for each row, increase number of hashes for each row
        putchar('\n');
        --space;
        ++block;
    }
}
