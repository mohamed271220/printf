#include "main.h"

/**
* _isdigit - checks if a character is a digit
* @c: character to be checked
* Return: 1 if c is a digit, 0 otherwise
*/

int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}

/**
* _strlen - returns the length of a string
* @s: string to be checked
* Return: length of string
*/

int _strlen(char *s)
{
int i = 0;

while (*s++)
i++;
return (i);
}

/**
* print_number - prints a number
* @str: number to be printed
* @params: parameters
* Return: number of bytes printed
*/

int print_number(char *str, params_t *params)
{
unsigned int i = _strlen(str);

int negative = (!params->no_flags && *str == '-');

if (!params->precision && *str == '0' && !str[1])
str = "";
if (negative)
{
str++;
i--;
}
if (params->precision != UINT_MAX)
while (i++ < params->precision)
*--str = '0';
if (negative)
*--str = '-';
if (!params->minus)
return (print_num_r(str, params));
else
return (print_num_l(str, params));
}

/**
* print_num_r - prints a number right-aligned
* @str: number to be printed
* @params: parameters
* Return: number of bytes printed
*/

int print_num_r(char *str, params_t *params)
{

}
