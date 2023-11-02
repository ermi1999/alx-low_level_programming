#include "hash_tables.h"

/**
 * hash_node - initializes an entry.
 * @key: the key.
 * @value: the value that is going to be stored at that location.
 * Return: pointer to the entry.
 */
hash_node_t *hash_node(const char *key, const char *value)
{
	hash_node_t *entry;

	entry = malloc(sizeof(hash_node_t));
	entry->key = malloc(strlen(key) + 1);
	entry->value = malloc(strlen(value) + 1);

	strcpy(entry->key, key);
	strcpy(entry->value, value);

	entry->next = NULL;

	return (entry);
}


/**
 * hash_table_set - adds an element to the hash table.
 * @ht: the hash table that is going to be updated or added.
 * @key: the key.
 * @value: the value that is going to be stored at that location.
 * Returns: 1 if it succeded 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *entry;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	entry = ht->array[index];

	if (entry == NULL)
	{
		ht->array[index] = hash_node(key, value);
	}
	else
	{
		new_node = hash_node(key, value);
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}
	return (1);
}
