#include"main.h"

/**
 * _isalpha - check for alphabetic charcters
 * @c: the caractet to be checked
 * Return: 1 for alphabetic characters and 0 for anything else
 */

int _isalpha(int c)
{
if (c >= 65 && c <= 122)
{
return (1);
}
return (0);
}
