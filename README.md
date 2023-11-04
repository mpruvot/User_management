
# User Management System

This repository hosts a C language project designed for managing user data and interactions. It provides a modular approach to user management with a focus on maintainability and scalability.

## Table of Contents

- [Project Structure](#project-structure)
  - [Development Checklist](#development-checklist)
  - [Error Checking](#error-checking)
  - [General Library](#general-library)
  - [Main Application](#main-application)
  - [Structures Library](#structures-library)
  - [User Management Library](#user-management-library)


## Project Structure

The project is organized into several directories and files, each serving a specific purpose in the user management system.

### Development Checklist

- `dev_checklist/checklist.md`: A Markdown document that outlines the steps and checks to be performed during the development process.

### Error Checking

- `error_check/leaks_data.txt`: Contains output from memory leak detection tools, providing insights into potential memory management issues.
- `error_check/valgrind_check.txt`: Includes Valgrind output used for detecting memory leaks and errors, crucial for maintaining robustness in the code.

### General Library

- `general_library/my_ft.c`: Implements a set of general-purpose functions that can be used throughout the project for various tasks.
- `general_library/my_ft.h`: The header file for the general-purpose functions, declaring function prototypes and necessary includes.

### Main Application

- `main.c`: The core source file containing the `main()` function. It orchestrates the flow of the program and is the starting point of the application.

### Structures Library

- `structures_library/my_struct.c`: Defines the data structures that are central to the user management logic, such as user profiles and data nodes.
- `structures_library/my_struct.h`: Declares the data structures and interfaces for the structures library, ensuring type safety and encapsulation.

### User Management Library

- `user_management_library/cmd.c`: Contains the implementation of commands that the system recognizes and processes in the context of user management.
- `user_management_library/cmd.h`: Provides the declarations for the user management commands, including function prototypes and documentation for each command.
- `user_management_library/const.h`: A header file that contains constant definitions specific to the user management module, such as error codes and system limits.

## Compilation and Execution

To compile the project, navigate to the root directory of the project and run the following command:

```bash
make all
