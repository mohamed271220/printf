#include "main.h"

/**
* convert - converts unsigned int to string
* @num: number to be converted
* @base: base to convert to
* @flags: flags
* @params: parameters
* Return: pointer to the converted string
*/


char *convert(long int num, int base, int flags, params_t *params)
{
static char *array;

static char buffer[50];

char sign = 0;

char *ptr;

unsigned long n = num;

(void)params;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}


/**
* print_unsigned - prints unsigned int
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/
int print_unsigned(va_list args, params_t *params)
{
unsigned long l;

if (params->l)
l = va_arg(args, unsigned long);

else if (params->h)
l = (unsigned short int)va_arg(args, unsigned int);

else
l = va_arg(args, unsigned int);

params->no_flags = 1;
return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}


/**
* print_address - prints address
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_address(va_list args, params_t *params)
{
unsigned long int n = va_arg(args, unsigned long int);

char *str;

if (!n)
return (_puts("(nil)"));
str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWER, params);
*--str = 'x';
*--str = '0';
return (print_number(str, params));
}

/**
* print_hex - prints hexadecimal in lowercase
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/

int print_hex(va_list args, params_t *params)
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

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWER, params);
if (params->hash && l)
{
*--str = 'x';
*--str = '0';
}
params->no_flags = 1;
return (c += print_number(str, params));
}

/**
* print_hex_upper - prints hexadecimal in uppercase
* @args: arguments
* @params: parameters
* Return: number of bytes printed
*/


int print_hex_upper(va_list args, params_t *params)
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

str = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hash && l)
{
*--str = 'X';
*--str = '0';
}
params->no_flags = 1;
return (c += print_number(str, params));
}

