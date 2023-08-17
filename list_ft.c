#include "my_ft.h"
#include <stdio.h>
#include <stdlib.h>
#include "list_ft.h"

// Print a list
void print_list(t_list *lst)
{
    t_list * current;
    int i;

    current = lst;
    i = 0;
    while (current)
    {
        printf("Node %d = %d\n", i, (*(int *)current->content)); // Vu que c'est un void* on donne le type
        current = current->next;
        i++;
    }
}

// Create a New element in a list
t_list *new_element(void *content, size_t size)
{
    t_list *new_element;
    int *content_ptr;

    content_ptr = malloc(size);
    if (!content_ptr)
        return (NULL);
    *content_ptr = content;

    new_element = malloc(sizeof(t_list));
    if (!new_element)
    {
        free(content_ptr);
        return (NULL);
    }
    new_element->content = content_ptr;
    new_element->next = NULL;
    return (new_element);
}

// Add A new node at frnt
void lstadd_front(t_list **lst, t_list *new)
{
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    new->next = *lst;
    *lst = new;
}

//count list size
int lst_count(t_list *lst)
{
    t_list *current;
    int i;

    current = lst;
    i = 0;
    while (current)
    {
        current = current->next;
        i++;
    }
    return (i);
}

// Add a node at the end
void lstadd_back(t_list **lst, t_list *new)
{
    t_list *current;

    current = *lst;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    while (current->next)
    {
        current = current->next;
    }
    current->next = new;
}

void del(void *content)
{
    free(content);
}

// clear a list
void lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
  
    while (*lst)
    {
        temp = *lst;
        del(temp->content);
        *lst = (*lst)->next;
        del(temp);
    }
} 

// return a node at index
t_list *lst_get_index(t_list *lst, int index)
{
    t_list *current;
    int i;

    current = lst;
    i = 0;
    while (i < index)
    {
        current = current->next;
        if (current == NULL && i < index)
            return(NULL);
        i++;
    }
    return(current);
}
