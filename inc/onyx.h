#pragma once
#ifndef ONYX_H
#define ONYX_H

#include "command_hashtable.h"
#include "misc_commands.h"

// Constant definitions
#define VERSION 1.0f
#define ASCII_ARR_SIZE 11
#define CWD_SIZE 1024
#define HOSTNAME_SIZE 256

// Function declarations
void printPrompt(void);
void processCommands(void);
void initCommands(command_hash_table* table);
char* getcmd(void);
void clearCR(char buffer[]);

#endif /* ONYX_H */