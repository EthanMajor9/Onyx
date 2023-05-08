#pragma once
#ifndef MISC_COMMANDS_H
#define MISC_COMMANDS_H

#include "command_hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constant definitions
#define INPUT_CHAR_LIMIT 2048

// Function prototypes
void clearScreen(void* param);
void printVersion(void* param);
void printASCIIArt(void* param);
void help(void* table);

#endif