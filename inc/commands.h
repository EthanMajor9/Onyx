#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constant definitions
#define INPUT_CHAR_LIMIT 2048

// Function prototypes
char* getcmd(void);
void clearScreen(void);
void clearCR(char buffer[]);

#endif