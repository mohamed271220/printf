#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unisrd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STR "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWER 1
#define CONVERT_UPPER 2


/**
* struct params - parameters struct
* @no_flags: no flags
* @minus: minus flag
* @plus: plus flag
* @space: space flag
* @hash: hash flag
* @zero: zero flag
* @width: width value
* @precision: precision value
* @h: h flag
* @l: l flag
*/

typedef struct params
{

	unsigned int no_flags: 1;

	unsigned int minus: 1;
	unsigned int plus: 1;
	unsigned int space: 1;
	unsigned int hash: 1;
	unsigned int zero: 1;

	unsigned int width;

	unsigned int precision;

	unsigned int h: 1;
	unsigned int l: 1;
} params_t;


/**
* struct specifier - struct for specifiers
* @specifier: specifier
* @f: function pointer
*/

typedef struct specifier
{
	char *specifier;

	int (*f)(va_list, params_t *);
} specifier_t;

int _putchar(char c);

int _puts(char *str);

int print_char(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);
int print_integer(va_list args, params_t *params);
int print_binary(va_list args, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_hex_upper(va_list args, params_t *params);
int print_pointer(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);
int print_rev(va_list args, params_t *params);
int print_big_s(va_list args, params_t *params);
int print_custom(va_list args, params_t *params);

char *convert(unsigned long int num, int base, int flags);

int print_unsigned(va_list args, params_t *params);
/* b */
int print_address(va_list args, params_t *params);


int _printf(const char *format, ...);

#endif
