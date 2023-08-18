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

#endif // CMD_H