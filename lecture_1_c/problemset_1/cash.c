// ########## Problemset 1 - Cash ########## //
#include<cs50.h>
#include<stdio.h>


// Functions & variables
int get_change(void);
void check_change(int change);
// int deduct_quarter(int change);
// int deduct_dime(int change);
int quarter = 25;
int dime = 10;
int nickle = 5;
int penny = 1;
int coins = 0;


// Main function
int main(void)
{
    int change = get_change();
    // printf("Change: %i\n", change);
    check_change(change);
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

void check_change(int change)
{
    printf("Current change: %i\n", change);
}
    
/*
// Check change
void check_coin(int change) 
{   // Check if it's possible to give quarter(s) as change
    do
    {
        do
        {
            printf("%i\n", change);        
            change = deduct_quarter(change);
            coins += 1;
            printf("Change after dime deduction: %i\n", change); 
        } 
        while (change >= quarter);

        // Check if it's possible to give dime(s) as change
        do
        {
            printf("%i\n", change);        
            change = deduct_dime(change);
            printf("%i\n", change);
            coins += 1;
        }
        while ((change - dime) >= 0);
        printf("Total number of coins used: %i\n", coins);
    }
    while (change > 0);
}

int deduct_quarter(int change)
{
    printf("Current change: %i\n", change);
    printf("Deducting %i cents from change\n", quarter);
    change -= quarter;
    printf("Change after deduction: %i\n", change);
    return change;
}

int deduct_dime(int change)
{
    printf("Current change: %i\n", change);
    printf("Deducting %i cents from change\n", dime);
    change -= dime;
    printf("Change after deduction: %i\n", change);
    return change;
}
*/
