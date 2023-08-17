#ifndef LIST_FT_H
#define LIST_FT_H

#include <unistd.h>
// Single linked list
typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;

// Print elements of a list
void print_list(t_list *lst);

// Create a New Element
t_list *new_element(void *content, size_t size);

// Add A new node at frnt
void lstadd_front(t_list **lst, t_list *new);

//count list size
int lst_count(t_list *lst);

// Add a node at the end
void lstadd_back(t_list **lst, t_list *new);

void del(void *content);

// clear a list
void lstclear(t_list **lst, void (*del)(void *));

// return a node at index
t_list *lst_get_index(t_list *lst, int index);

#endif // LIST_FT_H
// End of the #ifndef directive. Everything between #ifndef and #endif
// will be ignored if LIST_FT_H is already defined, thus preventing multiple definitions.
