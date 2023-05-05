#include "../inc/onyx.h"
#include "../inc/commands.h"

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

    printf("\033[31m%s\033[33m@\033[36m%s:\033[32m%s \033[33m> ", getlogin(), hostname, cwd);
    fflush(stdout);
}


void printASCIIArt(void) {
    system("clear");

    // Print out ASCII Logo
    for(int i = 0; i < 11; i++) {
        printf("%s", ASCIILogo[i]);
    }

    fflush(stdout);
}


void processCommands(void) {
    int running = 1;

    // Main processing loop
    while(running) {
        printPrompt();
        char* cmd = getcmd();
    }
}