#include "main.h"

/**
* init_params - sets struct and cleans the BUF
* @params: the params
* @args: arguments
*
* Return: void
*/

void init_params(params_t *params, va_list args)
{

params->no_flags = 0;
params->minus = 0;
params->plus = 0;
params->space = 0;
params->hash = 0;
params->zero = 0;
params->width = 0;
params->precision = UINT_MAX;
params->h = 0;
params->l = 0;

(void)args;
}
