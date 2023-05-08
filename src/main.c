#include "../inc/onyx.h"

int main(int argc, char* argv[]) {
    // Print header and art
    clearScreen();
    printASCIIArt();
    printVersion();
    processCommands();
    
    return 0;
}