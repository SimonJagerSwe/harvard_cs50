// ########## Problemset 1 - Cash ########## //
#include<cs50.h>
#include<stdio.h>


// Functions & variables
int get_change(void);
int quarter = 25;
int dime = 10;
int nickle = 5;
int penny = 1;
int coins = 0;


// Main function
int main(void){
    // Get change from user
    int change = get_change();
    if (change == 0)
    {
        printf("%i\n", coins);
    }
    else
    {
        do
        {
            if (change >= quarter)
            {
                do
                {
                    coins += 1;
                    change -= quarter;
                    // printf("Deducting a quarter from the change\n");
                    // printf("Current change: %i\n", change);
                    // printf("Number of coins used: %i\n", coins);
                } while ((change - quarter) >= 0);
            }
            else
            {
                // printf("Remaining change after quarters: %i\n", change);
            }

            if (change >= dime)
            {
                do
                {
                    coins += 1;
                    change -= dime;
                    // printf("Deducting a dime from the change\n");
                    // printf("Current change: %i\n", change);
                    // rintf("Number of coins used: %i\n", coins);
                }
                while ((change - dime) >= 0);
            }
            else
            {
                // printf("Remaining change after quarters and dimes: %i\n", change);
            }

            if (change >= nickle)
            {
                do
                {
                    coins += 1;
                    change -= nickle;
                    // printf("Deducting a nickle from the change\n");
                    // printf("Current change: %i\n", change);
                    // printf("Number of coins used: %i\n", coins);
                }
                while ((change - nickle) >= 0);
            }
            else
            {
                // printf("Remaining change after quarters, dimes and nickles: %i\n", change);
            }

            if (change >= penny)
            {
                do
                {
                    coins += 1;
                    change -= penny;
                    // printf("Deducting a penny from the change\n");
                    // printf("Current change: %i\n", change);
                    // printf("Number of coins used: %i\n", coins);
                }
                while ((change - penny) >= 0);
            }
        }
        while (change > 0);
        printf("%i\n", coins);
    }
}


// Function to get change
int get_change(void)
{
int change;
do {
change = get_int("Change: ");
}
while(change < 0);
return change;
}
