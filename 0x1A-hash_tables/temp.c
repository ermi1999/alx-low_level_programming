#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table.
 * @ht: the hashtable.
 * Return: Nothing.
 */
void hash_table_delete(hash_table_t *ht)
{
        unsigned long int i;
        hash_node_t *entry, *next;

        if (ht == NULL)
                return;
        for (i = 0; i < ht->size; i++)
        {
                if (ht->array[i] != NULL)
                {
                        entry = ht->array[i];
                        while (entry != NULL)
                        {
                                next = entry->next;
                                free(entry->key);
                                free(entry->value);
                                free(entry);
                                entry = next;
                        }
                }
                ht->array[i] = NULL;
        }
        free(ht->array);
        free(ht);
}
