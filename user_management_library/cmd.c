#include "cmd.h"
#include "my_ft.h"
#include "const.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


//Fonction to get an input from std in
char *get_input() // 
{   
    char buff[BUFF_LEN];
    char *result; // to stock the input
    int ret;

    ret = read(0, buff, BUFF_LEN - 1); // Nb of bytes read( -1 for the NULL char)
    if (ret <= 0)
        return (NULL);
    buff[ret] = '\0'; // NULL Char 
    result = malloc(ret + 1);
    if (!result)
        return (NULL);
    else
        my_strcpy(result, buff);
    
    return(result);
}// tester le RETURN BUFF ***

int check_cmd(char **user_input, t_cmd cmd) // penser a adapater la len si  j'ajoute une cmd
{
    int struct_len;
    char *user_cmd[] = {cmd.exit, cmd.create, cmd.list, cmd.delete, cmd.history};
    int i;

    struct_len = 5;
    i = 0;
    while (i < struct_len)
    {
        if (my_strcmp(user_input[0], user_cmd[i]) == 0)
            return i;
        i++;
    }
    return(-1);
}

void print_user_by_role(t_list *current, char *role, int *found)
{
    t_users *temp = NULL;
    while (current)
    {
        temp = current->content;
        if(my_strcmp(temp->role, role) == 0)
        {
            printf("%s %s \n", temp->role, temp->name);
            (*found)++;
        }
        current = current->next;
    }
    
} 

void print_cmd_list(t_mgmt *mgmt)
{
    int argc;
    int found;
    char *role;

    argc = tab_count(mgmt->user_input);
    found = 0;
    role = mgmt->user_input[1];

    if (!mgmt)
        return;
    if (!mgmt->store_user)
    {
        my_putstr_err("List is empty \n");
        return;
    }

    ///------------
    t_list *current = NULL;
    current = mgmt->store_user;

    if (argc == 1) // If the arg is "list" alone
    {
        // ils seront classées
        print_user_by_role(current, "admin", &found);
        print_user_by_role(current, "user", &found);
    }
    else if (argc == 2)
    {
        if (my_strcmp(role, "admin") == 0 || my_strcmp(role, "user") == 0)
        {
            print_user_by_role(current, role, &found);
            if (found == 0)
                printf("list of %s is empty\n", mgmt->user_input[1]);
        }
        else
        {   
            my_putstr_err("User_management: ");
            my_putstr_err(role);
            my_putstr_err(" is not a valid role\n");
        }
    }
}
    
void print_cmd_history(t_mgmt *mgmt)
{
    if (!mgmt)
        return;
    if (!mgmt->history)
    {
        my_putstr_err("history is empty\n");
        return;
    }
    
    t_list *current = NULL;
    current = mgmt->history;

    t_history *temp = NULL;

    while (current)
    {
        temp = current->content;
        write(1, temp->inputs, my_strlen(temp->inputs));
        my_putchar('\n');
        current = current->next;
    }
} 

// Add element to T_list Store_user
int add_to_store_user(t_mgmt *mgmt, char **input)
{
    t_list *new_user_node;
    t_users *new_user;

    new_user_node = malloc(sizeof(t_list));
    if (!new_user_node)
        return -1;
    // check if inputs are correct ( added because seagfault )
    if (tab_count(input) != 3)
    {
        my_putstr_err("User_management: Invalid cmd: expected: create <admin> or <user> + <name>\n");
        return(-1);
    }
    // Ici on crée une struct Et on copie argc 1 (role)
    new_user = malloc(sizeof(t_users));
    if (!new_user)
        return -1;
    if (my_strcmp(input[1], "admin") == 0)
        new_user->role = "admin";
    else if (my_strcmp(input[1], "user") == 0)
        new_user->role = "user";
    else
    { 
        my_putstr_err("User_management: Invalid role: expected: <admin> or <user> + <name>\n");
        free(new_user);
        return -1;
    }
    // Ici on assigne le name mais vu qu'on ne sais pas ce quee l'utilisateur entre, on doit copier la str
    new_user->name = my_strdup(input[2]);
    // On passe la struct a la t_list (en gros la t_list va pouvoir parcourir les structs.)
    new_user_node->content = new_user;
    new_user_node->next = NULL;
    // Maintenant, on doit ajouter ce nouveau Node qui contient la struct a la liste store pasée en param !

    // On l'ajoute au debut de la liste comme ca Qu'on on printera l'history on aura les plus recent en premier.
    lstadd_front(&(mgmt->store_user), new_user_node);

    // Print success
    write(1, new_user->role, my_strlen(new_user->role));
    my_putchar(' ');
    write(1, input[2], my_strlen(input[2]));
    my_putstr(" succefully created! \n");
    return 1;
}

// Add user inputs to history
int add_to_history(t_mgmt *mgmt, char **input)
{
    t_list *history_node;
    t_history *history;
  
    history_node = malloc(sizeof(t_list));
    if (!history_node)
        return -1;

    // Ici on crée une struct Et on copie argc 1 (role)
    history = malloc(sizeof(t_history));
    if (!history)
    {   
        free(history_node);
        return -1;
    }
    // on copie les iputs concat dans history->inputs
    history->inputs = double_tab_to_str(input);
    if (!history->inputs)
        return -1;
   
    // On passe la struct a la t_list (en gros la t_list va pouvoir parcourir les structs.)
    history_node->content = history;
    history_node->next = NULL;

    ///// Maintenant, on doit ajouter ce nouveau Node qui contient la struct a la liste store pasée en param !
    // On l'ajoute au debut de la liste comme ca Qu'on on printera l'history on aura les plus recent en premier.
     lstadd_front(&(mgmt->history), history_node);
    // test 
    //printf("added to history\n");
    return 1;
}

