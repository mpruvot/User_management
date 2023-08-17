#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_ft.h"
#include "get_input.h"

int main()
{
    my_putstr("Welcome in user management system.\n");
    my_putstr("Please type a command.\n> ");

    get_input();
    
    return 0;
}