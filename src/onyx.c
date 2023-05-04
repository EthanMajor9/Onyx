#include "../inc/onyx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void printPrompt() {
    char cwd[CWD_SIZE];
    char hostname[HOSTNAME_SIZE];

    // Get current working dir and hostname
    if(getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("GETCWD Error: ");
        return;
    }

    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("GETHOSTNAME Error: ");
        return;
    }

    // Print formatted output header
    printf("\033[31m%s\033[33m@\033[36m%s:\033[32m%s \033[33m> ", getlogin(), hostname, cwd);
    fflush(stdout);
}

void printASCIIArt() {
    system("clear");
    
    printf("\033[31m .----------------.  .-----------------. .----------------.  .----------------. \n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. |\n");
    printf("| |     ____     | || |  ____  _____  | || |  ____  ____  | || |  ____  ____  | |\n");
    printf("| |   .'    `.   | || | |_   \\|_   _| | || | |_  _||_  _| | || | |_  _||_  _| | |\n");
    printf("| |  /  .--.  \\  | || |   |   \\ | |   | || |   \\ \\  / /   | || |   \\ \\  / /   | |\n");
    printf("| |  | |    | |  | || |   | |\\ \\| |   | || |    \\ \\/ /    | || |    > `' <    | |\n");
    printf("| |  \\  `--'  /  | || |  _| |_\\   |_  | || |    _|  |_    | || |  _/ /'`\\ \\_  | |\n");
    printf("| |   `.____.'   | || | |_____|\\____| | || |   |______|   | || | |____||____| | |\n");
    printf("| |              | || |               | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------' \n");

    fflush(stdout);
}