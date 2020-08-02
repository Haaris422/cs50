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
unsigned int num_word = 0;

// Hash table
node *hashtable[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int hashvalue = hash(word);
    node *cursor;
    cursor = hashtable[hashvalue];
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
    if (x >= 'a' && x <= 'z') //TO convert lowercase alphabets.
    {
        x = x - 97;
    }
    else if (x >= 'A' && x <= 'Z') //To convert uppercase alphabets.
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
    while (fscanf(file, "%s", w) != EOF) //checks if file is not at its end.
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        int index = hash(w); //index of words.(w = word)
        strcpy(new_node->word, w);
        if (hashtable[index] == NULL)
        {
            hashtable[index] = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = hashtable[index];
            hashtable[index] = new_node;
        }
        num_word++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (num_word > 0) 
    {
        return num_word;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}