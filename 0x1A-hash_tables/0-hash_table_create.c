#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: the size of the array.
 * Return: pointer to the newly created hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
        unsigned long int i;
        hash_table_t *hashtable;

        hashtable = malloc(sizeof(hash_table_t));
        if (hashtable == NULL)
                return (NULL);
        hashtable->array = malloc(sizeof(hash_node_t *) * size);
        if (hashtable->array == NULL)
        {
                free(hashtable);
                return (NULL);
        }
        for (i = 0; i < size; ++i)
        {
                hashtable->array[i] = NULL;
        }

        hashtable->size = size;

        return (hashtable);
}
