#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

#include "builtins.h"
#include "io_helpers.h"
#include "variables.h"
#include "linked_list.h"





int main(int argc, char* argv[]) {
    char *prompt = "mysh$ "; // TODO Step 1, Uncomment this.

    char input_buf[MAX_STR_LEN + 1];
    input_buf[MAX_STR_LEN] = '\0';
    char *token_arr[MAX_STR_LEN] = {NULL};

    head = NULL;

    while (1) {
        // Prompt and input tokenization

        // TODO Step 2:
        // Display the prompt via the display_message function.
        display_message(&*prompt);

        int ret = get_input(input_buf);
        size_t token_count = tokenize_input(input_buf, token_arr);
        
        // Clean exit
        if (ret != -1 && (token_count == 0 || (strncmp("exit", token_arr[0], 4) == 0))) {
            break;
        }

        // Command execution
        if (token_count >= 1) {
            bool isVariableCommand = check_variable(token_arr[0]);
            bn_ptr builtin_fn = check_builtin(token_arr[0]);
            if (builtin_fn != NULL) {
                ssize_t err = builtin_fn(token_arr);
                if (err == - 1) {
                    display_error("ERROR: Builtin failed: ", token_arr[0]);
                }
            } else if (isVariableCommand) {
                ssize_t err = variable_fn(token_arr);
                if (err == - 1) {
                    display_error("ERROR: Variable Delcaration failed: ", token_arr[0]);
                } 
            } else {
                display_error("ERROR: Unrecognized command: ", token_arr[0]);
            }
        }

    }

    return 0;
}
