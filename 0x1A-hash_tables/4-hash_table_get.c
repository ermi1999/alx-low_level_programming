#include "hash_tables.h"
/**
 * hash_table_get - gets the table assosiated with the key.
 * @ht: the hash table.
 * @key: The key.
 * Return: The value.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *entry;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	if (strlen(key) == 0)
		return (NULL);
	index = key_index((unsigned char *) key, ht->size);
	entry = ht->array[index];
	while (entry != NULL && strcmp(entry->key, key) != 0)
		entry = entry->next;
	if (entry == NULL)
		return (NULL);
	return (entry->value);
}
