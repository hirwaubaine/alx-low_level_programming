#include <stdio.h>
/**
 *main - a c program that prints the alphabet in lowercase
 *Return:0
 **/
int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
