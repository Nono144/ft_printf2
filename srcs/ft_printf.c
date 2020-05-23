#include "ft_printf.h"

int	ft_printf(char *s, ...)
{
	t_str *str;
	int len;

	if (!(str = (t_str*)malloc(sizeof(t_str))))// sizeof(str) ne marche pas !
		return (-1);
	str->i = 0;
	str->len = 0;
	ft_initialize(str);
	va_start(str->args, s);
	while (s[str->i])
		ft_parse(str, s);
	va_end(str->args);
	len = str->len;
	free(str);
	return (len); 
}
		
