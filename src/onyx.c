#include "../inc/onyx.h"

void printPrompt(void) {
    char cwd[CWD_SIZE];
    char hostname[HOSTNAME_SIZE];

    // Get current working dir and hostname
    if(getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("GETCWD Error: ");
        exit(EXIT_FAILURE);
    }

    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("GETHOSTNAME Error: ");
        exit(EXIT_FAILURE);
    }

    // Print prompt
    printf("\033[31m%s\033[33m@\033[36m%s:\033[32m%s \033[33m> ", getlogin(), hostname, cwd);
    fflush(stdout);
}

void processCommands(void) {
    int running = 1;
    command_hash_table* cmd_table = create_table();
    initCommands(cmd_table);
    
    // Main processing loop
    while(running) {
        printPrompt();
        char* cmd = getcmd();
        command_function cmd_to_exec = command_lookup(cmd_table, cmd);

        if(cmd_to_exec != NULL) {
            cmd_to_exec();
        } else {
            printf("Command not found: %s\n", cmd);
        }

        free(cmd);
    }

    free_table(cmd_table);
}

char* getcmd(void) {
    char *input = malloc(sizeof(char) * INPUT_CHAR_LIMIT);

    // Read command from stdin
    if (fgets(input, INPUT_CHAR_LIMIT, stdin) == NULL) {
        printf("Error: failed to read input.\n");
        free(input);
        return NULL;
    }

    clearCR(input);

    // Check if the input is greater than INPUT_CHAR_LIMIT
    if (strlen(input) == INPUT_CHAR_LIMIT - 1 && input[INPUT_CHAR_LIMIT - 2] != '\n') {
        printf("Error: input is too long.\n");
        free(input);
        return NULL;
    }

    return input;
}

void clearCR(char buffer[])
{
	// Newline character search and assignment to null terminator
	char* whereCR = strchr(buffer, '\n');
	if (whereCR != NULL)
	{
		*whereCR = '\0';
	}
}

void initCommands(command_hash_table* table) {
    insert_command_to_table(table, "clear", clearScreen);
    insert_command_to_table(table, "art", printASCIIArt);
    insert_command_to_table(table, "version", printVersion);
}