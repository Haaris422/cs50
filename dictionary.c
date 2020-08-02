#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
unsigned int key;
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int hashvalue = hash(word);
    node *cursor;
    cursor = table[hashvalue];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
          cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
   unsigned int x = (unsigned int) word[0];
    if (x >= 'a' && x <= 'z')
    {
        x = x - 97;
    }
    else if(x >= 'A' && x <= 'Z')
    {
        x = x - 65;
    }
    return x;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char w[LENGTH + 1];
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", w) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        int index = hash(w);
        strcpy(new_node->word, w);
        if (table[index] == NULL)
        {
            table[index] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
         return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}