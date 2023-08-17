#include "my_ft.h"

// Outputs a character
void my_putchar(char c)
{
    write(1, &c, 1);
}

// Calculates string length
int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    return len;
}

// Outputs a string
void my_putstr(char *str) 
{
    int i = 0;
    
    while (str[i] != '\0') 
    {
        my_putchar(str[i]);
        i++;
    }

    my_putchar('\n');
}

// Outputs an integer
void my_putnbr(int nb)
{
    long number = nb;

    if (number < 0) 
    {
        my_putchar('-'); 
        number = -number; 
    }
  
    if (number >= 0 && number <= 9)
    {
        my_putchar(number + '0');   
    }
    else
    {
        my_putnbr(number / 10);
        my_putchar((number % 10) + '0');
    }
}

// Copies one string to another
char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

//Verify if it's a space
int is_space(char c)
{
    if (c == ' ')
        return 1;
    else
        return 0;
}
