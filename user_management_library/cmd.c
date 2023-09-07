#include "cmd.h"
#include "my_ft.h"
#include "const.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>



char *get_input() 
{   
    char buff[BUFF_LEN];
    char *result; // to stock the input
    int ret;

    ret = read(0, buff, BUFF_LEN - 1); // Nb of bytes read( -1 for the NULL char)
    if (ret <= 0)
        return (NULL);
    buff[ret] = '\0'; // NULL Char 
    result = malloc(ret + 1);
    if (!result)
        return (NULL);
    else
        my_strcpy(result, buff);
    
    return(result);
}// tester le RETURN BUFF *** 

int check_cmd(char **user_input, t_cmd cmd) // penser a adapater la len si  j'ajoute une cmd
{
    int struct_len;
    char *user_cmd[] = {cmd.exit, cmd.create, cmd.list, cmd.delete, cmd.history};
    int i;

    struct_len = 5;
    i = 0;
    while (i < struct_len)
    {
        if (my_strcmp(user_input[0], user_cmd[i]) == 0)
            return i;
        i++;
    }
    return(-1);
}

void print_user_by_role(t_list *current, char *role, int *found)
{
    t_users *temp = NULL;
    while (current)
    {
        temp = current->content;
        if(my_strcmp(temp->role, role) == 0)
        {
            printf("%s %s \n", temp->role, temp->name);
            (*found)++;
        }
        current = current->next;
    }
    
} 

void print_cmd_list(t_mgmt *mgmt)
{
    int argc;
    int found;
    char *role;

    argc = tab_count(mgmt->user_input);
    found = 0;
    role = mgmt->user_input[1];

    if (!mgmt)
        return;
    if (!mgmt->store_user)
    {
        my_putstr_err("List is empty !\n");
        return;
    }

    ///------------
    t_list *current = NULL;
    current = mgmt->store_user;

    if (argc == 1) // If the arg is "list" alone
    {
        // ils seront classées
        print_user_by_role(current, "admin", &found);
        print_user_by_role(current, "user", &found);
    }
    else if (argc == 2)
    {
        if (my_strcmp(role, "admin") == 0 || my_strcmp(role, "user") == 0)
        {
            print_user_by_role(current, role, &found);
            if (found == 0)
                printf("list of %s is empty !\n", mgmt->user_input[1]);
        }
        else
        {   
            my_putstr_err("User_management: ");
            my_putstr_err(role);
            my_putstr_err(" is not a valid role !\n");
        }
    }
    else
        my_putstr_err("User_management: Invalid cmd: expected: list <user> or <name>\n");
}
    
void print_cmd_history(t_mgmt *mgmt)
{
    if (!mgmt)
        return;
    if (!mgmt->history)
    {
        my_putstr_err("history is empty\n");
        return;
    }
    
    t_list *current = NULL;
    current = mgmt->history;

    t_history *temp = NULL;

    while (current)
    {
        temp = current->content;
        write(1, temp->inputs, my_strlen(temp->inputs));
        my_putchar('\n');
        current = current->next;
    }
} 

int add_to_store_user(t_mgmt *mgmt, char **input)
{
    if (tab_count(input) != 3)
    {
        my_putstr_err("User_management: Invalid cmd: expected: create <admin> or <user> + <name>\n");
        return(-1);
    }

    t_list *new_user_node;
    t_users *new_user;

    new_user_node = malloc(sizeof(t_list));
    if (!new_user_node)
        return -1;
    // check if inputs are correct ( added because seagfault )

    // Ici on crée une struct Et on copie argc 1 (role)
    new_user = malloc(sizeof(t_users));
    if (!new_user)
    {
        free(new_user_node);
        return -1;
    }
    if (my_strcmp(input[1], "admin") == 0)
        new_user->role = "admin";
    else if (my_strcmp(input[1], "user") == 0)
        new_user->role = "user";
    else
    { 
        my_putstr_err("User_management: Invalid role: expected: <admin> or <user> + <name>\n");
        free(new_user_node);
        free(new_user);
        return -1;
    }
    // Ici on assigne le name mais vu qu'on ne sais pas ce quee l'utilisateur entre, on doit copier la str
    new_user->name = my_strdup(input[2]);
    // On passe la struct a la t_list (en gros la t_list va pouvoir parcourir les structs.)
    new_user_node->content = new_user;
    new_user_node->next = NULL;
    // Maintenant, on doit ajouter ce nouveau Node qui contient la struct a la liste store pasée en param !

    // On l'ajoute au debut de la liste comme ca Qu'on on printera l'history on aura les plus recent en premier.
    lstadd_front(&(mgmt->store_user), new_user_node);


    // Print success
    write(1, new_user->role, my_strlen(new_user->role));
    my_putchar(' ');
    write(1, input[2], my_strlen(input[2]));
    my_putstr(" succefully created! \n");
    return 1;
}

int add_to_history(t_mgmt *mgmt, char **input)
{
    t_list *history_node;
    t_history *history;
  
    history_node = malloc(sizeof(t_list));
    if (!history_node)
        return -1;

    // Ici on crée une struct Et on copie argc 1 (role)
    history = malloc(sizeof(t_history));
    if (!history)
    {   
        free(history_node);
        return -1;
    }
    // on copie les iputs concat dans history->inputs
    history->inputs = double_tab_to_str(input);
    if (!history->inputs)
        return -1;
   
    // On passe la struct a la t_list (en gros la t_list va pouvoir parcourir les structs.)
    history_node->content = history;
    history_node->next = NULL;

    ///// Maintenant, on doit ajouter ce nouveau Node qui contient la struct a la liste store pasée en param !
    // On l'ajoute au debut de la liste comme ca Qu'on on printera l'history on aura les plus recent en premier.
     lstadd_front(&(mgmt->history), history_node);
    // test 
    //printf("added to history\n");
    return 1;
}

void user_mgmt_delete(t_mgmt *mgmt)
{
    if (!mgmt || !mgmt->store_user)
    {
        my_putstr_err("Nothing to delete here, list is already empty!\n");
        return;
    }
    int role_nb = role_counter(mgmt);
    int find_name = name_counter(mgmt);
    int argc = tab_count(mgmt->user_input);
    char *role = mgmt->user_input[1];
    char *name = NULL;
    char *to_split = NULL;
    char **yes_no = NULL;

    if (argc > 1 && argc < 4)
    {
        name = mgmt->user_input[2];
        if (argc == 2 && (my_strcmp(role, "user") == 0 || my_strcmp(role, "admin") == 0))
        {
            if (role_nb == 0)
            {
                my_putstr_err("Nothing to delete here, list is already empty!\n");
                return;
            }

            while (1)
            {
                printf("are you sure you want to delete %d %s? y/n : \n", role_nb, role);
                to_split = get_input();
                yes_no = my_split_str(to_split);
            
                if (my_strcmp(yes_no[0], "y") == 0)
                {
                    delete_users_by_role(&mgmt->store_user, role);
                    free(to_split);
                    free_double_tab(yes_no);
                    return;
                }
                else if (my_strcmp(yes_no[0], "n") == 0)
                {
                    my_putstr("Deletion cancelled !\n\n");
                    free(to_split);
                    free_double_tab(yes_no);                    
                    return;
                }
                else
                    my_putstr("Please enter a valid command. \n\n");
                    free(to_split);
                    free_double_tab(yes_no);
            }  
           
        }
        else if (argc == 3 && (my_strcmp(role, "user") == 0 || my_strcmp(role, "admin") == 0))
        {
            if (find_name == 0)
            {
                my_putstr_err("Nobody found under this name !\n");
                return;
            }
            else
                delete_users_by_name(&mgmt->store_user, role, name);
                return;
        }
    }
    else
       my_putstr_err("User_management: Invalid cmd: expected: <delete> <role> or <delete> <role> + <name>\n"); 
    
}

void delete_users_by_role(t_list **head_user, char *role) 
{
    t_list *current = *head_user; // Pointeur vers l'élément courant de la liste
    t_list *previous = NULL;      // Pointeur vers l'élément précédent de la liste
    t_users *temp = NULL;        // Pointeur temporaire pour stocker les données utilisateur
    t_list *temp_current = NULL;

    // Boucle à travers la liste chaînée
    while (current) 
    {
        temp = current->content; // Récupère les données utilisateur de l'élément courant

        if (my_strcmp(temp->role, role) == 0) 
        {
            temp_current = current; // garde une trace de current pour le liberer plus tard

            // Si un élément précédent existe, ajuste son pointeur 'next' pour sauter l'élément courant
            if (previous) 
            {
                previous->next = current->next;
                current = previous->next; // Ajuste le pointeur 'current' pour le prochain tour de boucle
            } 
            else 
            {
                // Si aucun élément précédent n'existe, change la tête de la liste
                *head_user = current->next;
                current = *head_user; // Ajuste le pointeur 'current' pour le prochain tour de boucle
            }

            // Libère l'élément courant de la mémoire
            free(temp->name);
            free(temp);
            free(temp_current);

        } 
        else 
        {
            // Met à jour le pointeur 'previous' et avance dans la liste
            previous = current;
            current = current->next;
            //
        }
    }
   printf("All the %s have been succesfully deleted.\n", role);
}

void delete_users_by_name(t_list **head_user, char *role, char *name)
{
    t_list *current = *head_user; // Pointeur vers l'élément courant de la liste
    t_list *previous = NULL;      // Pointeur vers l'élément précédent de la liste
    t_list *temp_current = NULL;

    t_users *temp_user = NULL;        // Pointeur temporaire pour stocker les données utilisateur
  

    // Boucle à travers la liste chaînée
    while (current) 
    {
        temp_user = current->content;

        if (my_strcmp(temp_user->name, name) == 0 && my_strcmp(temp_user->role, role) == 0) 
        {
            

            temp_current = current; // garde une trace de current pour le liberer plus tard

            // Si un élément précédent existe, ajuste son pointeur 'next' pour sauter l'élément courant
            if (previous) 
            {
                previous->next = current->next;
                current = previous->next; // Ajuste le pointeur 'current' pour le prochain tour de boucle
            } 
            else 
            {
                // Si aucun élément précédent n'existe, change la tête de la liste
                *head_user = current->next;
                current = *head_user; // Ajuste le pointeur 'current' pour le prochain tour de boucle
            }

            // Libère l'élément courant de la mémoire

            free(temp_user->name);
            free(temp_user);
            // Les deux lignes si dessus.... 2 heure pour trouver la leak
            free(temp_current);

        } 
        else 
        {
            // Met à jour le pointeur 'previous' et avance dans la liste (si on entre pas dans le if)
            previous = current;
            current = current->next;
            //
        }
    }

    printf("%s %s have been succesfully deleted.\n", role, name);
}

int role_counter(t_mgmt *mgmt)
{
    t_list *current = NULL;
    t_users *temp = NULL;
    int nb;
    char *role;

    nb = 0;
    current = mgmt->store_user;
    role = mgmt->user_input[1];
    while(current)
    {
        temp = current->content;
        if (my_strcmp(temp->role, role) == 0)
            nb++;
        current = current->next;
    }
    return nb;
}

int name_counter(t_mgmt *mgmt)
{
    t_list *current = NULL;
    t_users *temp = NULL;
    int nb;
    char *name;

    nb = 0;
    current = mgmt->store_user;
    name = mgmt->user_input[2];
    while(current)
    {
        temp = current->content;
        if (my_strcmp(temp->name, name) == 0)
            nb++;
        current = current->next;
    }
    return nb;
}

void free_management(t_mgmt *mgmt)
{
    t_list *temp = NULL;
    t_users *temp_user = NULL;
    t_history *temp_hist = NULL;
  
    while (mgmt->store_user)
    {
        temp = mgmt->store_user;
        temp_user = temp->content;
        free(temp_user->name);
        free(temp_user->role);
        free(temp->content);
        mgmt->store_user = mgmt->store_user->next;
        free(temp);
        temp = NULL;
    }
    while (mgmt->history)
    {
        temp = mgmt->history;
        temp_hist = temp->content;
        free(temp_hist->inputs);
        free(temp->content);
        mgmt->history = mgmt->history->next;
        free(temp);
        temp = NULL;
    }
    free_double_tab(mgmt->user_input);
    mgmt->user_input = NULL;
}

