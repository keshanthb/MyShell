#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "variables.h"
#include "io_helpers.h"

struct Node {
    char *value;
    char *name;
    struct Node* next;
};

//char * variable_list[] = {};
//int variable_count = 0;
bool check_variable(const char *cmd) {
    return (strchr(cmd, '=') != NULL);
}

char *split(char *variableInput, char *delimiter) {
    char *pt = strstr(variableInput, delimiter);
    *pt = '\0';
    return pt + strlen(delimiter);
}

ssize_t variable_fn(char **tokens) {
    char *varName;
    char *varValue;
    varName = tokens[0];
    varValue = split(varName, "=");

    struct Node* curr = head;
    struct Node* node;
    node = (struct Node*)malloc(sizeof(struct Node));
    node->value = varValue;
    node->name = varName;
    if (head != NULL) {
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
        display_message("More Nodes inserted");
   } else {
        head = node;
        display_message("Node inserted");
    }
    free(node);
    
    /**
    if(variable_count == 1) {
        struct Node* node = NULL;

        node = (struct Node*)malloc(sizeof(struct Node));
        node->value = varValue;
        head = node;
        display_message("success1");

    } else {
        struct Node* node = NULL;
        struct Node* curr = head;
        node = (struct Node*)malloc(sizeof(struct Node));
        while (curr->next != NULL) {
            curr = curr->next;
        }
        node->value = varValue;
        curr->next = node;
        display_message("success2");
    }
    **/
    return 0;
}
