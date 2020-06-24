#include "ft_printf.h"

void	ft_initialize(t_str *str)
{
	int i;

	str->precision = -1;
	str->width = -1;
	i = 0;
	while (i < 6)
		str->convert[i++] = 0;
	i = 0;
	while (i < 2)
		str->flags[i++] = 0;
	i = 0;
	while (i < 3)
		str->length[i++] = 0;
	str->type = '\0';
}

