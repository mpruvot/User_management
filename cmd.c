#include "cmd.h"
#include "my_ft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//Fonction to get an input from std in
char *get_input() // 
{   
    char buff[256];
    char *result; // to stock the input
    int ret;

    ret = read(0, buff, sizeof(buff) - 1); // Nb of bytes read( -1 for the NULL char)
    if (ret <= 0)
        return (NULL);
    buff[ret] = '\0'; // NULL Char 
    result = malloc(ret + 1);
    if (!result)
        return (NULL);
    else
        my_strcpy(result, buff);
    
    return(result);
}

// Exit_check_command
int is_exit(char *input)
{
    char *exit;
    exit = "exit";

    if (my_strcmp(exit, input) == 0)
        return 1;
    else
        return 0;   
}

// Create_check_command
int is_create(char *input)
{
    char *create;
    create = "create";

    if (my_strcmp(create, input) == 0)
        return 1;
    else
        return 0;   
}

// List_check_command
int is_list(char *input)
{
    char *list;
    list = "list";

    if (my_strcmp(list, input) == 0)
        return 1;
    else
        return 0;   
}

// Delete_check_command
int is_delete(char *input)
{
    char *delete;
    delete = "delete";

    if (my_strcmp(delete, input) == 0)
        return 1;
    else
        return 0;   
}

// History_check_command
int is_history(char *input)
{
    char *history;
    history = "history";

    if (my_strcmp(history, input) == 0)
        return 1;
    else
        return 0;
}

/* 
void print_cmd_list(t_list *lst, char **input)
{
    t_list *current = NULL;

    if (!input[1])
    {
        // Add print the whole List
    }
    else if (my_strcmp(input[1], "user"))
    {
        
    }
    else if (my_strcmp(input[1], "admin"))
    {
        
    }
    else
        return;
    
} 
*/

// Add element to T_list Store_user
void add_to_store_user(t_list **store, char **input, t_users *infos)
{
    t_list *new_user_node;
    t_users *new_user;
  
    new_user_node = malloc(sizeof(t_list));
    if (!new_user_node)
        return;

    if (tab_count(input) != 3)
    {
        my_putstr("User_management: expected: create <admin>/<user> <name> ");
        return;
    }
    
    // Ici on crée une struct Et on copie argc 1 (role)
    new_user = malloc(sizeof(t_users));
    if (!new_user)
        return;
    if (my_strcmp(input[1], "admin") == 0)
        new_user->role = "admin";
    else if (my_strcmp(input[1], "user") == 0)
        new_user->role = "user";
    else
    {
        my_putstr("User_management: Invalid role: expected:<admin> or <user>");
        free(new_user);
        return;
    }
    // Ici on assigne le name mais vu qu'on ne sais pas ce quee l'utilisateur entre, on doit copier la str
    new_user->name = malloc(my_strlen(input[2])+ 1);
    if (!new_user->name)
        return;
    my_strcpy(new_user->name, input[2]);

    // On passe la struct a la t_list (en gros la t_list va pouvoir parcourir les structs.)
    new_user_node->content = new_user;
    new_user_node->next = NULL;

    ///// Maintenant, on doit ajouter ce nouveau Node qui contient la struct a la liste store pasée en param !
    // On l'ajoute au debut de la liste comme ca Qu'on on printera l'history on aura les plus recent en premier.
     lstadd_front(&store, new_user_node);
}

