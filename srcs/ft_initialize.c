#include "ft_printf.h"

/*typedef struct s_str
{
	va_list		args;
	size_t		i;
	long int	precision;
	long int	width;
	char		type;
	char		convert[6];
	char		flag[2];
}		t_str; */

void	ft_initialize(t_str *str)
{
	int i;
	int j;
	int k;

	str->precision = -1;
	str->width = -1;
	str->sign = 0;
	i = 0;
	while (i < 6)
		str->convert[i++] = 0;
	j = 0;
	while (j < 2)
		str->flags[j++] = 0;
	k = 0;
	while (k < 3)
		str->length[k++] = 0;
	str->type = '\0';
}

