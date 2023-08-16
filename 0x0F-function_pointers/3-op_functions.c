#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - will Return the sum of two numbers.
 * @a: first number.
 * @b: second number.
 *
 * Return: The sum
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - will Return the difference of two numbers.
 * @a: first number.
 * @b: second number.
 *
 * Return: The difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - will Return the product of two numbers.
 * @a: first number.
 * @b: second number.
 *
 * Return: The product
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - will Return the division of two numbers.
 * @a: first number.
 * @b: second number.
 *
 * Return: The quotient
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - Returns the remainder of the division of two numbers
 * @a: first number.
 * @b: second number.
 *
 * Return: The remainder of the division
 */
int op_mod(int a, int b)
{
	return (a % b);
}
