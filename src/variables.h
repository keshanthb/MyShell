#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include <unistd.h>
#include <stdbool.h>

struct Node;

//typedef ssize_t (*v_ptr)(char **);

struct Node* head;

ssize_t variable_fn(char **tokens);
bool check_variable(const char *cmd);
void print_variables(struct Node* n);
#endif