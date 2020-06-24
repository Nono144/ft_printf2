#include "ft_printf.h"

void	ft_parse_type(t_str *str, char *s)
{
	if (s[str->i] != '\0')
		str->type = s[str->i++];
}
