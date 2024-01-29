#include "main.h"

/**
* get_precision - gets the precision
* @p: string formate
* @params: parameters
* @args: arguments
* Return: is precision valid
*/

char *get_precision(char *p, params_t *params, va_list args)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(args, int);
		p++;
		if (d < 0)
			d = -1;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
