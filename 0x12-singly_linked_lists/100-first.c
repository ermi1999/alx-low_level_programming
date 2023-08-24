#include <stdio.h>
/**
 * first - will print a sentence before the main function
 */
void __attribute__((constructor)) first()
{
	char *message1 = "You're beat! and yet, you must allow,";
	char *message2 = "I bore my house upon my back!";

	puts(message1);
	puts(message2);
}
