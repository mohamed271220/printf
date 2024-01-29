#include "main.h"

/**
* print_binary - prints binary
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_binary(va_list args, params_t *params)
{
	unsigned int n = va_arg(args, unsigned int);

	char *str = convert(n, 2, CONVERT_UNSIGNED, params);

	int c = 0;

	if (params->hash && n)
	*--str = '0';
	params->no_flags = 1;
	return (c += print_number(str, params));
}

/**
* print_octal - prints octal
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_octal(va_list args, params_t *params)
{
	unsigned long l;

	int c = 0;

	char *str;

	if (params->l)
	l = (unsigned long)va_arg(args, unsigned long);

	else if (params->h)
	l = (unsigned short int)va_arg(args, unsigned int);

	else
	l = (unsigned int)va_arg(args, unsigned int);

	str = convert(l, 8, CONVERT_UNSIGNED, params);
	if (params->hash && l)
	*--str = '0';
	params->no_flags = 1;
	return (c += print_number(str, params));
}
