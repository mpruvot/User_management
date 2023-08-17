#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_ft.h"
#include "mgmt.h"
#include "my_struct.h"


int main()
{    
    int is_running;
    char **user_input = NULL;

    t_commands command = {
        .exit = "exit",
        .create = "create",
        .history = "history",
        .list = "list",
        .delete = "delete"
    };
    is_running = 1;

    my_putstr("Welcome in user management system.\n");


    while(is_running)
    {
        my_putstr("Please type a command> ");
        user_input = my_split_str(get_input());
        if (my_strcmp(user_input[0], command.exit)== 0)
            is_running = 0;
        else
        printf("input = %s\n", user_input[0]);
    }
    printf("bye! \n");
    free_double_tab(user_input);
    return 0;
}