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