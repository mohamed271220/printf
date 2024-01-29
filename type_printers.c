#include "main.h"


/**
* print_char - prints a character
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/


int print_char(va_list args, params_t *params)
{
char padding = ' ';

unsigned int pad = 1, sum = 0, ch = va_arg(args, int);

if (params->minus)
sum += _putchar(ch);
while (pad++ < params->width)
sum += _putchar(padding);
if (!params->minus)
sum += _putchar(ch);
return (sum);
}

/**
* print_int - prints a int
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_int(va_list args, params_t *params)
{
	long l;

	if (params->l)
		l = va_arg(args, long);
	else if (params->h)
		l = (short int)va_arg(args, int);

	else
		l = (int)va_arg(args, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
* print_string - prints a string
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_string(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);

	char padding = ' ';

	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STR;
		j = pad = _strlen(str);
		if (params->precision < pad)
			j =  pad = params->precision;
		if (params->minus)
		{
			if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		while (j++ < params->width)
			sum += _putchar(padding);
		if (!params->minus)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		return (sum);
}


/**
* print_percent - prints a percent
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_percent(va_list args, params_t *params)
{
	(void)args;
	(void)params;
	return (_putchar('%'));
}

/**
* print_S - prints a string
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_S(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);

	char *hex;

	unsigned int i, sum = 0;

	(void)params;
	if ((int)(!str))
		return (_puts(NULL_STR));
	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(str[i], 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
			sum += _putchar(str[i]);
	}
	return (sum);
}
