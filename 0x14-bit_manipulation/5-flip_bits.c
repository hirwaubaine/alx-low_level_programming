#include <stdio.h>
#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: unsigned long int 1
 * @m: unsigned long int 2
 * Return: the number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count;

	for (count = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((m & 1) != (n & 1))
			count++;
	}
	return (count);
}
