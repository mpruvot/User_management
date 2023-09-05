#ifndef CMD_H
#define CMD_H

#include "my_ft.h"
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"

// Get input from User
char *get_input();

int check_cmd(char **user_input, t_cmd cmd);

// Print_cmd_list
void print_cmd_list(t_mgmt *mgmt);

void print_user_by_role(t_list *current, char *role, int *found);

void print_cmd_history(t_mgmt *mgmt);

// Add element to T_list Store_user
int add_to_store_user(t_mgmt *mgmt, char **input);

// Add user inputs to history
int add_to_history(t_mgmt *mgmt, char **input);
#endif // CMD_H