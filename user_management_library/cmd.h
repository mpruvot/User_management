#ifndef CMD_H
#define CMD_H

#include "my_ft.h"
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"

char *get_input();

int check_cmd(char **user_input, t_cmd cmd);

void print_cmd_list(t_mgmt *mgmt);

void print_user_by_role(t_list *current, char *role, int *found);

void user_mgmt_delete(t_mgmt *mgmt);

void delete_users_by_role(t_list **head_user, char *role);

void delete_users_by_name(t_list **head_user, char *role, char *name);

void confirm_and_delete_by_role(t_mgmt *mgmt, char *role, int role_nb);

int role_counter(t_mgmt *mgmt);

void print_cmd_history(t_mgmt *mgmt);

int add_to_store_user(t_mgmt *mgmt, char **input);

int name_counter(t_mgmt *mgmt);

int add_to_history(t_mgmt *mgmt, char **input);

int end_of_file(int fd);

int inputs_log(t_mgmt *mgmt);

void free_management(t_mgmt *mgmt);

void which_cmd(t_cmd cmd, int nb_cmd);


////////////////////////////////////////////////////////////////////

int inputs_log(t_mgmt *mgmt);

#endif 