#include "my_ft.h"
#include <stdio.h>
#include <stdlib.h>

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

// Copies one string to another
char *my_wordcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] && !is_space(src[i]))
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
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
        return 1;
    else
        return 0;
}

// count words in a string
int count_words(char *str)
{
    if (!str)
        return(0);
    
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (is_space(str[i]) && str[i])
            i++;
        
        if (!is_space(str[i]))
        {
            count++;
            while (!is_space(str[i]) && str[i])
                i++;
        }
    }
    return count;
}

// Split a String into multiple strings
char **my_split_str(char *str)
{
    int i;
    int index_newstr;
    int start;
    int end;
    char **str_split = NULL;

    i = 0;
    index_newstr = 0;
    start = 0;
    end = 0;
    str_split = malloc(sizeof(char*) * count_words(str) + 1);
    if (!str_split)
        return(NULL);
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        start = i;
        while (!is_space(str[i]) && str[i])
            i++;
        end = i;

        if (str[i]) // on verifie Que la chaine n'est pas NULL ! (car sinon ca alloue quand meme un espace !!!)
        {
        str_split[index_newstr] = malloc(sizeof(char) * (end - start) + 1);
        if (!str_split[index_newstr])
            return NULL;
        my_wordcpy(str_split[index_newstr], str + start);
        index_newstr++;
        }
        
    }
    str_split[index_newstr] = NULL;
    return str_split;
}

// Compares 2 strings
int my_strcmp(char *str1, char *str2)
{
    if (!str1 || !str2)
        return -1;
    int i;

    i = 0;
    while (str1[i] && str1[i] == str2[i])
        i++;
    return(str1[i] - str2[i]);
}

// Free char **
void free_double_tab(char **tab)
{
    int i = 0;

    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

// Count Tab in tab
int tab_count(char **tab)
{
    int count = 0;
    while (tab && tab[count]) 
    {
        count++;
    }
    return count;
}

// duplicate a str
char *my_strdup(char *str)
{
    char *dup_str;
    dup_str = malloc(my_strlen(str) + 1);
    if (!dup_str)
        return NULL;
    
    my_strcpy(dup_str, str);
    return dup_str;
}

// concat double_tab into str
char *double_tab_to_str(char **tab)
{
    int i;
    int j;
    int k;
    int len;

    char *new_str = NULL;

    len = 0;
    i = 0;
    j = 0;
    k = 0;

    while (tab[i])
    {
        len += my_strlen(tab[i]);
        if (tab[i + 1])
            len++; // Pour allouer la mmemoire pour les espaces
        
        i++;
    }
    new_str = malloc(len + 1);
    if (!new_str)
        return NULL;
    

    while (tab[j])
    {
        i = 0;
        while (tab[j][i])
        {
            new_str[k] = tab[j][i];
            i++;
            k++;
        }
        if (tab[j + 1])
        {
            new_str[k] = ' '; 
            k++;
        }
        j++;
    }
    new_str[k] = '\0';

    return new_str;
    
}