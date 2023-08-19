#ifndef CMD_H
#define CMD_H

#include "my_ft.h"
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"

// Get input from User
char *get_input();

// Exit_check_command
int is_exit(char *input);

// List_check_input
int is_list(char *input);

// Create_check_command
int is_create(char *input);

// Delete_check_command
int is_delete(char *input);

// History_check_command
int is_history(char *input);

// Print_cmd_list
void print_cmd_list(t_list *lst);

// Add element to T_list Store_user
int add_to_store_user(t_list **store, char **input);
#endif // CMD_H