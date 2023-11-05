#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	int ret;

	ret = shash_table_set(NULL, "Holberton", "is cool");
	printf("%d\n", ret);
	return (EXIT_SUCCESS);
}
