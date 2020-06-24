#include "ft_printf.h"

static int	ft_isalpha(char c)
{
	if (c <= '9' && c >= '0')
		return (c);
	return (0);
}

void	ft_parse_precision(t_str *str, char *s)
{
	int precision;

	str->precision = -1;
	precision = 0; /* prend la valeur de width sinon */
	if (s[str->i] == '.')
	{
		str->i++;
		if (s[str->i] == '*')
		{
			ft_get_num(str);
			str->precision = str->num;
			str->i++;
		}
		else
		{
			while(ft_isalpha(s[str->i]))
			{
				precision = 10 * precision  + (s[str->i] - '0');
				str->i++;
			}
			str->precision = precision;
		}
	}
}
