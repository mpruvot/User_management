#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#include <unistd.h>

// struct User infos
typedef struct s_users {
  char *role;
  char *name;
} t_users;

//struct Command
typedef struct s_commands{
  char *exit;
  char *create;
  char *history;
  char *list;
  char *delete;
} t_commands;


#endif // MY_STRUCT_H
// End of the #ifndef directive. Everything between #ifndef and #endif
// will be ignored if MY_STRUCT_H is already defined, thus preventing multiple definitions.
