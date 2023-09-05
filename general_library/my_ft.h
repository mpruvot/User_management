
#ifndef MY_FT_H
#define MY_FT_H
// The #ifndef, #define and #endif directives are used to prevent
// the content of this header file from being included multiple times
// in the same program.

#include <unistd.h>

// Outputs a character
void my_putchar(char c);

// Calculates string length
int my_strlen(char *str);

// Outputs a string
void my_putstr(char *str);

// Same but on Err_output
void my_putstr_err(char *str);

// Outputs an integer
void my_putnbr(int nb);

// Copies one string to another
char *my_strcpy(char *dest, char *src);

//Verify if it's a space
int is_space(char c);

// count words in a string
int count_words(char *str);

// Compare Two strings
int my_strcmp(char *str1, char *str2);

// Split a String into multiple strings
char **my_split_str(char *str);

// concat double_tab into str
char *double_tab_to_str(char **tab);

// Free char **
void free_double_tab(char **tab);

// compte le nombre de sous tab
int tab_count(char **tab);

// duplicate a str
char *my_strdup(char *str);

#endif // MY_FT_H
// End of the #ifndef directive. Everything between #ifndef and #endif
// will be ignored if MY_FT_H is already defined, thus preventing multiple definitions.
