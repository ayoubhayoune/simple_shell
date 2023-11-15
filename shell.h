#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* for convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/**
 * Builtin functions
 */
int is_builtin(char *command);
int execute_builtin(char **tokens);
void execute_env(char **tokens);
void execute_setenv(char **tokens);
void execute_unsetenv(char **tokens);
void execute_cd(char **tokens);
void execute_alias(char **tokens);

/**
 * Builtin helper functions
 */
void execute_commands_from_file(const char *filename);
void process_and_execute_command(char *command);
void execute_logical_operator(char *input, char *operator);
void handle_logical_operators(char *input);
void handle_separator(char *input);
void free_tokens(char **tokens);
void display_aliases(void);
void create_alias(char **tokens);

/**
 * Tokenizer
 */
char **tokenize_input(char *input);
char *handle_variables(char *input);
char *replace_string(char *str, const char *old_str, const char *new_str);
int get_exit_status(void);

/**
 * Executor
 */
void execute_command(char **tokens);

/**
 * Separator
 */
void process_command(char *command);

/**
 * Input
 */
char *remove_comments(char *input);
int handle_eof(char *input);
char *read_input(void);
void display_prompt(void);

#endif /* SHELL_H */
