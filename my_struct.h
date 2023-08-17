#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#include <unistd.h>

// General Single Linked List
typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;


// Linked list to Store User infos
typedef struct s_user {
  char *type;
  char *name;
  struct s_list *next;
} t_user;

// List to Store Input history
typedef struct s_history {
  char *type;
  char *name;
  struct s_list *next;
} t_history;

// Fonction to print a list
void print_list(t_user *lst);

#endif // MY_STRUCT_H
// End of the #ifndef directive. Everything between #ifndef and #endif
// will be ignored if MY_STRUCT_H is already defined, thus preventing multiple definitions.
