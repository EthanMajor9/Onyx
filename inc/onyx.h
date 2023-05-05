#ifndef ONYX_H
#define ONYX_H

#include "datastructures.h"
#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constant definitions
#define VERSION 1.0f
#define ASCII_ARR_SIZE 11
#define CWD_SIZE 1024
#define HOSTNAME_SIZE 256

// Function declarations
void printPrompt(void);
void printASCIIArt(void);
void processCommands(void);
void initCommands(command_hash_table* table);

#endif /* ONYX_H */