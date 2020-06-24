#include "ft_printf.h"
#include "libft.h"

void	ft_parse(t_str *str, char *s)
{
	int len;
	int c;

	len = 0;
	if ((c = s[str->i]) == '%')
	{
		str->i++;
		ft_initialize(str);
		ft_parse_flags(str, s);
		ft_parse_width(str, s);
		ft_parse_precision(str, s);
		ft_parse_size(str, s);
		ft_parse_type(str, s); 
		ft_display(str);
	}
	else
	{
		while ((c = s[str->i + len])!= '%' && c != '\0' && c != EOF)
			len++;
		ft_write(1, s + str->i, len, str);
		str->i += len;
	}
}
