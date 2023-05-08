#include "../inc/onyx.h"

int main(int argc, char* argv[]) {
    // Print header and art
    clearScreen(NULL);
    printASCIIArt(NULL);
    printVersion(NULL);
    processCommands();
    
    return 0;
}