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

#define PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWER 1
#define CONVERT_UPPER 2
#define CONVERT_UNSIGNED 4


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
	unsigned int h: 1;
	unsigned int l: 1;
	unsigned int width;
	unsigned int precision;
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
int print_int(va_list args, params_t *params);
int print_binary(va_list args, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_hex_upper(va_list args, params_t *params);
int print_pointer(va_list args, params_t *params);
int print_big_s(va_list args, params_t *params);
int print_custom(va_list args, params_t *params);

/* convertor.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_address(va_list args, params_t *params);


/* utils.c */
int (*get_spec(char s))(va_list, params_t *);
int get_print(char s, va_list args, params_t *params);
int get_flags(char s, params_t *params);
char *get_width(char s, params_t *params, va_list args);
int get_modifier(char s, params_t *params);

/* prints.c */
int print_fromto(char *start, char *end, int except);
int print_rev(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);


char *get_width_str(char *s, params_t *params);

/* strings_fields.c */
char *get_precision(char *p, params_t *params, va_list args);

/* print_num.c */
int _isdigit(int c);
int _strlen(char *c);
int print_num(char *str, params_t *params);
int print_num_r(char *str, params_t *params);
int print_num_l(char *str, params_t *params);

/* init_params.c */
void init_params(params_t *params, va_list args);


/* _printf.c */
int _printf(const char *format, ...);

#endif
