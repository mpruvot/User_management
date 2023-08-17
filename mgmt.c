#include "mgmt.h"
#include "my_ft.h"
#include <unistd.h>
#include <stdlib.h>

//Fonction to get an input from std in
char *get_input() // 
{   
    char buff[256];
    char *result; // to stock the input
    int ret;

    ret = read(0, buff, sizeof(buff) - 1); // Nb of bytes read( -1 for the NULL char)
    if (ret <= 0)
        return (NULL);
    buff[ret] = '\0'; // NULL Char 
    result = malloc(ret + 1);
    if (!result)
        return (NULL);
    else
        my_strcpy(result, buff);
    
    return(result);
}

// Here we store the read string in a Str that we can compare later!