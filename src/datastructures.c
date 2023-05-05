#include "../inc/datastructures.h"
#include "../inc/commands.h"

/*
* TITLE: djb2
* AUTHOR: Dan Bernstein
* DATE: 2023-05-05
* AVAILABILITY: http://www.cse.yorku.ca/~oz/hash.html
*/
int djb2(const char* str)
{
	unsigned long hash = 5381;
	int c = 0;

	while ((c = *str++) != '\0')
	{
		hash = ((hash << 5) + hash) + c;
	}

	return hash % MAX_TABLE_SIZE;
}

command_hash_table* create_table() {
    // Allocate memory for the table and init the size to 0
    command_hash_table* table = malloc(sizeof(command_hash_table));
    table->size = 0;

    // Initialize all entries of the table to NULL
    for(int i =0; i < MAX_TABLE_SIZE;i++) {
        table->entries[i] = NULL;
    }

    return table;
}

void insert_to_table(command_hash_table* table, char* key, command_function value) {
    int index = djb2(key);

    // Allocate and create command with given parameters
    command_entry* command = malloc(sizeof(command_entry));
    command->key = key;
    command->value = value;

    // Insert into the hash table at the hashed index
    table->entries[index] = command;
    table->size++;
}

command_function command_lookup(command_hash_table* table, char* key) {
    int index = djb2(key);

    command_entry* command = table->entries[index];

    if(command == NULL) {
        return NULL;
    }
    
    if(strcmp(command->key, key) == 0) {
        return command->value;
    } else {
        return NULL;
    }
}


void free_table(command_hash_table* table) {
    for(int i = 0; i < table->size; i++) {
        free(table->entries[i]->key);
        free(table->entries[i]);
    }

    free(table);
}