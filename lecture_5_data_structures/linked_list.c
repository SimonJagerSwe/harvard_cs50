// ########## LINKED LIST ########## //
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
    {
        int number;
        struct node *next;
    } node;


int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        (*n).number = get_int("Number: ");                      // Classic way
        n->next = NULL;                                         // Snazzy, modern way

        // Prepend node to list
        n->next = list;
        list = n;
    }

    // Print numbers
    /*node *ptr = list;                                         // More clear in step-by-step
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }*/

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)        // More succinct
    {
        printf("%i\n", ptr->number);
    }


    return 0;
}
