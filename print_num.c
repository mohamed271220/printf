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
	unsigned int n = 0, negative, negative2, i = _strlen(str);

	char padding = ' ';

	if (params->zero && !params->minus)
		padding = '0';
	negative = negative2 = (!params->no_flags && *str == '-');
	if (negative && i < params->width
	&& padding == '0' && !params->minus && *(str + 1) != '\0')
		str++;
	else
		negative = 0;
	if ((params->plus && !negative2)
	|| (!params->plus && params->space && !negative2))
		i++;
	if (negative && padding == '0')
		n += _putchar('-');
	if (params->plus && !negative2 && padding == '0' && !params->no_flags)
		n += _putchar('+');
	else if (!params->plus && params->space
	&& !negative2 && !params->no_flags && params->zero)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(padding);
	if (negative && padding == ' ')
		n += _putchar('-');
	if (params->plus && !negative2 && padding == ' ' && !params->no_flags)
		n += _putchar('+');
	else if (!params->plus && params->space && !negative2
	&& !params->no_flags && !params->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
* print_num_l - prints a number left-aligned
* @str: number to be printed
* @params: parameters
* Return: number of bytes printed
*/

int print_num_l(char *str, params_t *params)
{
	unsigned int n = 0, negative, negative2, i = _strlen(str);

	char padding = ' ';

	if (params->zero && !params->minus)
		padding = '0';
	negative = negative2 = (!params->no_flags && *str == '-');
	if (negative && i < params->width
	&& padding == '0' && !params->minus)
		str++;
	else
		negative = 0;
	if (params->plus && !negative2 && !params->no_flags)
	n += _putchar('+'), i++;
	else if (params->space && !negative2 && !params->no_flags)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(padding);
	return (n);
}
