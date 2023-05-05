#include "../inc/onyx.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    // Print header and art
    printASCIIArt();
    printf("\n\033[31mONYX \033[33m- \033[31mVERSION \033[32m%.1f.0\n\n", VERSION);
    fflush(stdout);
    processCommands();
    
    return 0;
}