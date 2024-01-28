#include "main.h"

/**
* _printf - prints something
* @format: format of the sent string
*
* Return: number of bytes printed by the function
*/

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list args;
	char *ptr, *start;
	params_t params = PARAMS;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}

	for (ptr = (char *)format; *ptr ; ptr++)
	{
		init_params(&params, args);
		if (*ptr != '%')
		{
			sum += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (get_flags(ptr, &params))
			ptr++;
		ptr = get_width(ptr, &params, args);
		ptr = get_precision(ptr, &params, args);
		if (get_modifier(ptr, &params))
			ptr++;
		if (!get_spec(ptr))
			sum += print_fromto(start, ptr, params.l || params.h ? ptr - 1 : 0);
		else
			sum += get_print(ptr, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (sum);
}
