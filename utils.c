#include "main.h"

/**
* get_spec - finds formate mode
* @s: formate specifier
* Return: num of bytes
*/

int (*get_spec(char *s))(va_list args, params_t *params)
{
specifier_t specs[] = {
	{"c", print_char},
	{"d", print_int},
	{"i", print_int},
	{"%", print_percent},
	{"p", print_address},
	{"s", print_string},
	{"u", print_unsigned},
	{"o", print_octal},
	{"x", print_hex},
	{"b", print_binary},
	{"X", print_hex_upper},
	{"S", print_big_s},
	{"r", print_rev},
	{"R", print_rot13},
	{NULL, NULL}
};
int i = 0;
while (specs[i].specifier)
{
if (*s == specs[i].specifier[0])
{
return (specs[i].f);
}
i++;
}
return (NULL);
}

/**
* get_print - fotmat
* @s: the format
* @args: args pointer
* @params: parameters
*
* Return: the number of bytes
*/

int get_print(char *s, va_list args, params_t *params)
{
int (*f)(va_list, params_t *) = get_spec(s);
if (f)
return (f(args, params));
return (0);
}

/**
* get_flags - gets the flag
* @s: string formate
* @params: parameters
* Return: is flag valid
*/

int get_flags(char *s, params_t *params)
{
int i = 0;
switch (*s)
{
case '+':
i = params->plus = 1;
break;
case ' ':
i = params->space = 1;
break;
case '#':
i = params->hash = 1;
break;
case '-':
i = params->minus = 1;
break;
case '0':
i = params->zero = 1;
break;
}
return (i);
}

/**
* get_modifier - gets the modifier
* @s: string formate
* @params: parameters
* Return: is modifier valid
*/

int get_modifier(char *s, params_t *params)
{
int i = 0;
switch (*s)
{
case 'h':
i = params->h = 1;
break;
case 'l':
i = params->l = 1;
break;
}
return (i);
}

/**
* get_width - gets the width
* @s: string formate
* @args: args pointer
* @params: parameters
* Return: is width valid
*/

char *get_width(char *s, va_list args, params_t *params)
{
int d = 0;
if (*s == '*')
{
d = va_arg(args, int);
s++;
}
else
{
while (_isdigit(*s))
d = d * 10 + (*s++ - '0');
}
params->width = d;
return (s);
}
