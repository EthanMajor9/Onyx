#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 1000

typedef void (*command_function)(void);

typedef struct {
    char* key;
    command_function value;
} command_entry;

typedef struct {
    int size;
    command_entry* entries[MAX_TABLE_SIZE];
} command_hash_table;

command_hash_table* create_table();
void insert_to_table(command_hash_table* table, char* key, command_function value);
command_function command_lookup(command_hash_table* table, char* key);
void free_table(command_hash_table* table);
int djb2(const char* str);

#endif