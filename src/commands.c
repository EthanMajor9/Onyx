#include "../inc/commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getcmd(void) {
    char *input = malloc(sizeof(char) * INPUT_CHAR_LIMIT);

    // Read command from stdin
    if (fgets(input, INPUT_CHAR_LIMIT, stdin) == NULL) {
        printf("Error: failed to read input.\n");
        free(input);
        return NULL;
    }

    // Check if the input is greater than INPUT_CHAR_LIMIT
    if (strlen(input) == INPUT_CHAR_LIMIT - 1 && input[INPUT_CHAR_LIMIT - 2] != '\n') {
        printf("Error: input is too long.\n");
        free(input);
        return NULL;
    }

    return input;
}
