#include "hash_tables.h"
/**
 * shash_table_create - creates a hash table.
 * @size: the size of the hashtable.
 * Return: The ahshtalble.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hashtable;
	unsigned long int i;

	hashtable = malloc(sizeof(shash_table_t));
	if (hashtable == NULL)
		return (NULL);
	hashtable->size = size;
	hashtable->array = malloc(sizeof(shash_node_t *) * size);
	if (hashtable->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hashtable->array[i] = NULL;
	hashtable->shead = NULL;
	hashtable->stail = NULL;

	return (hashtable);
}

/**
 * initialize_node - initializes an entry.
 * @key: the key.
 * @value: the value that is going to be stored at that location.
 * Return: pointer to the entry.
 */
shash_node_t *initialize_node(const char *key, const char *value)
{
	shash_node_t *entry;

	entry = malloc(sizeof(shash_node_t));
	entry->key = strdup(key);
	entry->value = strdup(value);
	entry->next = NULL;
	entry->snext = NULL;
	entry->sprev = NULL;

	return (entry);
}

/**
 * shash_table_set - adds an element to the hash table.
 * @ht: the hashtable.
 * @key: The key.
 * @value: The value.
 * Return: 1 if it succeded 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *entry;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	entry = initialize_node(key, value);
	if (ht->array[index] == NULL)
		ht->array[index] = entry;
	else
	{
		entry->next = ht->array[index];
		ht->array[index] = entry;
	}
	if (ht->shead == NULL)
	{
		ht->shead = entry;
		ht->stail = entry;
		return (1);
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		entry->sprev = NULL;
		entry->snext = ht->shead;
		ht->shead->sprev = entry;
		ht->shead = entry;
		return (1);
	}
	current = ht->shead;
	while (current->snext != NULL && strcmp(current->snext->key, key) < 0)
		current = current->snext;
	entry->sprev = current;
	entry->snext = current->snext;
	if (current->snext == NULL)
		ht->stail = entry;
	else
		current->snext->sprev = entry;
	current->snext = entry;
	return (1);
}


/**
 * shash_table_get - gets an element from sorted hashtable.
 * @ht: the hashtable.
 * @key: the key at which the element is.
 * Return: The value associated with that key.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *entry;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	if (strlen(key) == 0)
		return (NULL);
	index = key_index((unsigned char *) key, ht->size);
	entry = ht->array[index];

	if (entry == NULL)
		return (NULL);
	return (entry->value);
}


/**
 * shash_table_print - prints sorted hash table.
 * @ht: The hashtable.
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;
	current = ht->shead;
	printf("{");
	while (current != NULL)
	{
		if (current == ht->stail)
		{
			printf("'%s': '%s'", current->key, current->value);
			current = current->snext;
			continue;
		}
		else
		{
			printf("'%s': '%s', ", current->key, current->value);
			current = current->snext;
		}
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse.
 * @ht: The hashtable.
 * Return: Nothing.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tail;

	if (ht == NULL)
		return;
	tail = ht->stail;
	printf("{");
	while (tail != NULL)
	{
		if (tail == ht->shead)
		{
			printf("'%s': '%s'", tail->key, tail->value);
			tail = tail->sprev;
			continue;
		}
		else
		{
			printf("'%s': '%s', ", tail->key, tail->value);
			tail = tail->sprev;
		}
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hashtable.
 * @ht: The hashtable to be deleted.
 * Return: Nothing.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *entry, *next;

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
