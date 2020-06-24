#include "ft_printf.h"
#include "libft.h"

void	ft_get_num(t_str *str)
{
	if (ft_strcmp(str->length, "l") == 0)
		str->num = (long)(va_arg(str->args, long));
	else if (ft_strcmp(str->length, "ll" ) == 0)
		str->num = (long long)(va_arg(str->args, long long));
	else if (ft_strcmp(str->length, "h") == 0)
		str->num = (short)(va_arg(str->args, int));
	else if (ft_strcmp(str->length, "hh") == 0)
		str->num = (char)(va_arg(str->args, int));
	else
		str->num = (int)(va_arg(str->args, int));
}

void		ft_get_unum(t_str *str)
{
	if (ft_strcmp(str->length, "l") == 0 || str->type == 'p')
		str->unum = (unsigned long)(va_arg(str->args, unsigned long));
	else if (ft_strcmp(str->length, "ll") == 0)
		str->unum = (unsigned long long)(va_arg(str->args, unsigned long long));
	else if (ft_strcmp(str->length, "h") == 0)
		str->unum = (unsigned short)(va_arg(str->args, unsigned int));
	else if (ft_strcmp(str->length, "hh") == 0)
		str->unum = (unsigned char)(va_arg(str->args, unsigned int));
	else
		str->unum = (unsigned)(va_arg(str->args, unsigned));
}

void		ft_get_char(t_str *str)
{
	if (ft_strcmp(str->length, "l") == 0 || str->type == 'C')
		str->num = (wchar_t)(va_arg(str->args, wint_t));
	else
		str->num = (char)(va_arg(str->args, int));
}

void	ft_get_string(t_str *str)
{
	str->arg = (char *)(va_arg(str->args, char*));
}

void	ft_get_wstring(t_str *str)
{
	str->arg= (wchar_t*)(va_arg(str->args, wchar_t *));
}
