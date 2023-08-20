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
    t_list *store_users = NULL;
    t_list *history = NULL;

    store_users = NULL;

    is_running = 1;

    my_putstr("Welcome in user management system.\n");

    while (is_running)
    {
        my_putstr("\nPlease type a command > ");
        user_input = my_split_str(get_input());

        if (tab_count(user_input) == 1)
        {
            if (is_exit(user_input[0]))
                is_running = 0;   
            else if (is_create(user_input[0]))  
                my_putstr("User_management: expected: create <admin>/<user> <name> \n");       
            else if (is_delete(user_input[0]))
            {
                /* code */
            }
            else if (is_list(user_input[0]))
                print_cmd_list(store_users);
            
            else if (is_history(user_input[0]))
            {
                print_cmd_history(history);
            }
            else
            { 
                my_putstr("User_management: Command not found: ");
                write(1, user_input[0], my_strlen(user_input[0]));
                my_putstr("\n");
            }
        }
        else if (tab_count(user_input) == 3)
        {
            if (is_create(user_input[0]))
                add_to_store_user(&store_users, user_input);
        }
        else
        {
            //my_putstr("User_management: Command not found: ");
        }

        add_to_history(&history, user_input);
        free_double_tab(user_input);
    }

    printf("\nbye! \n");
    return 0;
}
