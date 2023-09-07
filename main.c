#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_ft.h"
#include "cmd.h"
#include "my_struct.h"
#include "const.h"

int main()
{    
    int is_running;
    int checkcmd;
    char *to_split = NULL;
    char **user_input = NULL;
    t_mgmt *mgmt = malloc(sizeof(t_mgmt));
    if (!mgmt)
        return (-1);
    mgmt->store_user = NULL;
    mgmt->history = NULL;

    checkcmd = -1;
    is_running = 1;
    t_cmd cmd = {"exit", "create", "list", "delete", "history"}; // Adpat check_cmd() if cmd added

    my_putstr(WELCOM_MSG);

    while (is_running)
    {
        my_putstr(ASK_FOR_CMD);
        // it was user_input = my_plit_str(get_input()); But had leaks with this method -> pass it to get iput
        to_split = get_input();
        user_input = my_split_str(to_split);
        checkcmd = check_cmd(user_input, cmd);
        mgmt->user_input = user_input;
        
        if (checkcmd == EXIT)
        {
            is_running = 0;
        }
        else if (checkcmd == CREATE)
            add_to_store_user(mgmt, user_input);
        else if (checkcmd == LIST)
            print_cmd_list(mgmt);
        else if (checkcmd == DELETE)
            user_mgmt_delete(mgmt);
        else if (checkcmd == HISTORY)
            print_cmd_history(mgmt);
        else
        {    
            my_putstr_err(CMD_NOT_FOUND);
            my_putstr_err(user_input[0]);
            my_putchar('\n');

        }

        add_to_history(mgmt, user_input);
        free(to_split);
        free_double_tab(user_input);
        
    }

    free_management(mgmt);
    printf("\nbye! \n");
    return 0;
}

//https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/