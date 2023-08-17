#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_ft.h"
#include "mgmt.h"


int main()
{
    int i;
    char *user_input = NULL;
    char **split_input = NULL;

    i = 0;

    my_putstr("Welcome in user management system.\n");
    my_putstr("Please type a command.\n> ");

    user_input = get_input();

    split_input = my_split_str(user_input);
    if (!split_input[0]) // Si le premier élément est null, c'est que l'utilisateur n'a saisi que des espaces
    {
        printf("No valid input \"only space\"\n");
    }
    else
    {
        while (split_input[i])
        {
            printf("input %d = %s \n", i, split_input[i]);
            i++;
        }
    }

    free(user_input);

    return 0;
}