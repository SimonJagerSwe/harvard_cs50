// ########## Problemset 1 - Cash ########## //
#include<cs50.h>
#include<stdio.h>


// Functions
int get_change(void);


// Main function
int main(void)
{
    int change = get_change();
    printf("Change: %i\n", change);
}


// Function to get change
int get_change(void)
{
int change;
// Check if number of rows is valid
do {
change = get_int("Change: ");
}
while(change < 1);
// Return valid number of rows
return change;
}