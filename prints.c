#include "main.h"

/**
* print_fromto - prints from start to end
* @start: start of the string
* @end: end of the string
* @except: except the last char
* Return: number of bytes printed
*/

int print_fromto(char *start, char *end, int except)
{
	int sum = 0;

	while (start < end)
	{
		if (*start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
* print_rev - prints a string in reverse
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/


int print_rev(va_list args, params_t *params)
{
int sum = 0;

int len;

char *str = va_arg(args, char *);

(void)params;
if (str)
{
for (len = 0; str[len]; len++)
;
for (len -= 1; len >= 0; len--)
sum += _putchar(str[len]);
}
return (sum);
}


/**
* print_rot13 - prints a string in rot13
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_rot13(va_list args, params_t *params)
{
	int i, j;

	int count = 0;

	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	char *str = va_arg(args, char *);

	(void)params;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			j = str[i] - 'A';
			count += _putchar(arr[j]);
		}
		else if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			j = str[i] - 'a' + 26;
			count += _putchar(arr[j]);
		}
		else
		{
			count += _putchar(str[i]);
		}
		i++;
	}
	return (count);
}
