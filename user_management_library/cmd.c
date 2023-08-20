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


void print_cmd_list(t_list *lst)
{
    if (!lst)
    {
        printf("List is empty.\n");
        return;
    }

    t_list *current = NULL;
    current = lst;

    t_users *temp = NULL;

    while (current)
    {
        temp = current->content;
        printf("%s %s \n", temp->role, temp->name);
        current = current->next;
    }
} 

void print_cmd_history(t_list *history)
{
    if (!history)
    {
        printf("History is empty.\n");
        return;
    }

    t_list *current = NULL;
    current = history;

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
int add_to_store_user(t_list **store, char **input)
{
    t_list *new_user_node;
    t_users *new_user;
  
    new_user_node = malloc(sizeof(t_list));
    if (!new_user_node)
        return -1;

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
        my_putstr("User_management: Invalid role: expected:<admin> or <user>");
        free(new_user);
        return -1;
    }
    // Ici on assigne le name mais vu qu'on ne sais pas ce quee l'utilisateur entre, on doit copier la str
    new_user->name = my_strdup(input[2]);
    // On passe la struct a la t_list (en gros la t_list va pouvoir parcourir les structs.)
    new_user_node->content = new_user;
    new_user_node->next = NULL;

    ///// Maintenant, on doit ajouter ce nouveau Node qui contient la struct a la liste store pasée en param !
    // On l'ajoute au debut de la liste comme ca Qu'on on printera l'history on aura les plus recent en premier.
     lstadd_front(store, new_user_node);
    // test 
    // printf("User added!\n");

    // Print success
    write(1, new_user->role, my_strlen(new_user->role));
    my_putchar(' ');
    write(1, input[2], my_strlen(input[2]));
    my_putstr(" succefully created! \n");
    return 1;
}

// Add user inputs to history
int add_to_history(t_list **store, char **input)
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
     lstadd_front(store, history_node);

    // test 
    //printf("added to history\n");
    return 1;
}