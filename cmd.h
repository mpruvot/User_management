#ifndef CMD_H
#define CMD_H

#include "my_ft.h"
#include <stdio.h>
#include <stdlib.h>
#include "list_ft.h"
#include "my_struct.h"


// print_list_name

void print_names(t_list *head);

// Print_list_role

void print_role(t_list *head);

//void Add Struct to list

void Add_to_list(t_list **head, t_users user)

// Count the occurences of a letter in a file.
char *get_input();

// CREATE
void create();


// LIST
void list();


// DELETE
void delete();

// HISTORY

void history();


// Print Name




#endif // CMD_H