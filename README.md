# Simple Shell

A simple Unix shell implementation in C.

## Overview

This project is a basic implementation of a Unix shell. It provides a lightweight and easy-to-understand example of how shells work, featuring command execution, built-in commands, command chaining, and more.

## Project Structure

- **main.c**: Entry point for the shell. Contains the main loop for user input and command execution.

- **shell.h**: Header file containing function prototypes, global constants, and includes necessary for the shell.

- **tokenizer.c**: Tokenization functions responsible for breaking user input into individual commands and arguments.

- **builtin.c**: Implementation of built-in commands such as `cd`, `env`, `setenv`, `unsetenv`, `exit`, and `alias`.

- **builtin_helpers.c**: Helper functions for the built-in command execution.

- **file_mode.c**: Handles file mode execution, allowing commands to be read and executed from a file.

- **input.c**: Functions for reading user input and handling the "end of file" condition.

- **execute.c**: Core execution functions, including executing external commands, handling logical operators, and input/output redirection.

## Features

- **Command Execution**: Execute external commands and display their output.
  
- **Built-in Commands**: Includes built-in commands such as `cd`, `env`, `setenv`, `unsetenv`, `exit`, and `alias`.

- **Command Chaining**: Support for command chaining using `;`, `&&`, and `||`.

- **Input/Output Redirection**: Basic input and output redirection for commands.

- **Variable Handling**: Replace variables like `$?` and `$$` in command strings.

- **File Mode Execution**: Execute commands from a file.
