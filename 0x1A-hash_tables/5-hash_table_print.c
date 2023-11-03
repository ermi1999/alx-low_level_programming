#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table.
 * @ht: The hashtable.
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *entry;
	int comma = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		entry = ht->array[i];

		if (entry == NULL)
			continue;
		while (entry != NULL)
		{
			if (comma)
				printf(", ");
			printf("'%s': '%s'", entry->key, entry->value);

			comma = 1;

			entry = entry->next;
		}
	}
	printf("}\n");
}
