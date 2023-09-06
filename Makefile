# **************************************************************************** #
# VARIABLES

# Define the output binary name
NAME	:= user_management

# Define the flags for the compiler
CFLAGS := -g -Wall -Wextra -Werror -Igeneral_library -Istructures_library -Iuser_management_library


# Define the C compiler to use
CC	:= gcc


# **************************************************************************** #
# SOURCES

# List the source files without extension
SRC_FILES := main.c \
             general_library/my_ft.c \
             structures_library/my_struct.c \
             user_management_library/cmd.c
# Use addsuffix to generate object file names from source files
OBJ_FILES := ${SRC_FILES:.c=.o}

# List of header files
HEADERS := my_ft.h my_struct.h cmd.h 
	
# **************************************************************************** #
# RULES

# Default rule executed
all: $(NAME)

# Rule for making the binary and indirectly the object files
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(NAME)

# Rule for converting .c files to .o files
# The compiler flags are applied here
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for removing object files
clean:
	rm -f $(OBJ_FILES)

# Rule for removing object files and the binary file
fclean: clean
	rm -f $(NAME)

# Rule for re-making everything
re: fclean all

# **************************************************************************** #
# PHONY

# .PHONY tells make that these rules do not represent files
.PHONY: all clean fclean re
