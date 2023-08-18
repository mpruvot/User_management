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
 
    is_running = 1;

    my_putstr("Welcome in user management system.\n");

    while (is_running)
    {
        my_putstr("Please type a command> ");
        user_input = my_split_str(get_input());
        if (tab_count(user_input) == 1)
        {
            if (is_exit(user_input[0]))
                is_running = 0;
            else if (is_list(user_input[0]))
            {
                /// add print list
            }
            else if (is_history(user_input[0]))
            {
                // Add history
            }
        
        }
        free_double_tab(user_input);
    }
    printf("\nbye! \n");
    return 0;
}