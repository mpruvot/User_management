#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_ft.h"
#include "cmd.h"
#include "my_struct.h"


int main()
{    
    int is_running;
    char **user_input = NULL;
    t_list *
    //t_list *user = NULL;

    t_commands command = {
        .exit = "exit",
        .create = "create",
        .history = "history",
        .list = "list",
        .delete = "delete"
    };
    
    t_users user = {.role = NULL, .name = NULL};

    is_running = 1;

    my_putstr("Welcome in user management system.\n");

    
    printf("bye! \n");
    free_double_tab(user_input);
    return 0;
}