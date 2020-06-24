#include "ft_printf.h"

static int	ft_isalpha(char c)
{
	if (c <= '9' && c >= '0')
		return (c);
	return (0);
}

static	void	ft_parse_st(t_str *str)
{
	int l_flags;

	ft_get_num(str);
	if ((str->width = str->num) < 0)
	{
		l_flags = ft_strlen(str->flags);
		str->flags[l_flags] = '-';
		str->flags[l_flags + 1] = '\0';
		str->width = -str->width;
	}
	str->i++;
}

void	ft_parse_width(t_str *str, char *s)
{
	int width;

	width = (ft_isalpha(s[str->i]) == 0 ? -1 : 0);
	if (s[str->i] == '*')
		ft_parse_st(str);		
	else
	{
		while(ft_isalpha(s[str->i]))
		{
			width = 10 * width  + (s[str->i] - '0');
			str->i++;
		}
		str->width = width;
	}
}
