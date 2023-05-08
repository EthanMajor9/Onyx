#include "../inc/misc_commands.h"
#include "../inc/onyx.h"

const char *ASCIILogo[ASCII_ARR_SIZE] = { 
    "\033[31m .----------------.  .-----------------. .----------------.  .----------------. \n",
    "| .--------------. || .--------------. || .--------------. || .--------------. |\n",
    "| |     ____     | || |  ____  _____  | || |  ____  ____  | || |  ____  ____  | |\n",
    "| |   .'    `.   | || | |_   \\|_   _| | || | |_  _||_  _| | || | |_  _||_  _| | |\n",
    "| |  /  .--.  \\  | || |   |   \\ | |   | || |   \\ \\  / /   | || |   \\ \\  / /   | |\n",
    "| |  | |    | |  | || |   | |\\ \\| |   | || |    \\ \\/ /    | || |    > `' <    | |\n",
    "| |  \\  `--'  /  | || |  _| |_\\   |_  | || |    _|  |_    | || |  _/ /'`\\ \\_  | |\n",
    "| |   `.____.'   | || | |_____|\\____| | || |   |______|   | || | |____||____| | |\n",
    "| |              | || |               | || |              | || |              | |\n",
    "| '--------------' || '--------------' || '--------------' || '--------------' |\n",
    " '----------------'  '----------------'  '----------------'  '----------------' \n"
};

void clearScreen(void* param) {
    printf("\033[2J\033[H");
}

void printASCIIArt(void* param) {
    // Print out ASCII Logo
    for(int i = 0; i < 11; i++) {
        printf("%s", ASCIILogo[i]);
    }

    fflush(stdout);
}

void printVersion(void* param) {
    printf("\n\033[31mONYX \033[33m- \033[31mVERSION \033[32m%.1f.0\n\n", VERSION);
    fflush(stdout);
}


void help(void* table) {
    command_hash_table* cmd_table = (command_hash_table*)table;

    printf("\nCommand\t|\tDescription\n \
                      -------------------\n");

    for(int i = 0; i < MAX_TABLE_SIZE; i++) {
        if(cmd_table->entries[i] == NULL) {
            continue;
        } else {
            printf("%-8s - %s\n", cmd_table->entries[i]->key, cmd_table->entries[i]->desc);
        }
    }

    printf("\n");
    fflush(stdout);
}