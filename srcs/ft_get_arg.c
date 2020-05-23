#include "ft_printf.h"
#include "libft.h"

long long		ft_get_num(t_str *str)
{
	long long num;

	if (ft_strcmp(str->length, "l") == 0)
		num = (long)(va_arg(str->args, long));
	else if (ft_strcmp(str->length, "ll" ) == 0)
		num = (long long)(va_arg(str->args, long long));
	else if (ft_strcmp(str->length, "h") == 0)
		num = (short)(va_arg(str->args, int));
	else if (ft_strcmp(str->length, "hh") == 0)
		num = (char)(va_arg(str->args, int));
	else
		num = (int)(va_arg(str->args, int));
	return (num);
}

unsigned long long	ft_get_unum(t_str *str)
{
	unsigned long long unum;
	char	long_type;

	long_type = 0;
	if ((str->type == 'p' || str->type == 'x' || str->type == 'X') && ft_strcmp(str->length, "") == 0)
		long_type = 1;
	if (ft_strcmp(str->length, "l") == 0 || long_type == 1)
		unum = (unsigned long)(va_arg(str->args, unsigned long));
	else if (ft_strcmp(str->length, "ll") == 0)
		unum = (unsigned long long)(va_arg(str->args, unsigned long long));
	else if (ft_strcmp(str->length, "h") == 0)
		unum = (unsigned short)(va_arg(str->args, unsigned int));
	else if (ft_strcmp(str->length, "hh") == 0)
		unum = (unsigned char)(va_arg(str->args, unsigned int));
	else
		unum = (unsigned)(va_arg(str->args, unsigned));
	return (unum);
}

