#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_ft.h"
#include "mgmt.h"


int main()
{
    char *user_input = NULL;

    my_putstr("Welcome in user management system.\n");
    my_putstr("Please type a command.\n> ");

    user_input = get_input();

    printf("%s", user_input);
    free(user_input);

    return 0;
}
