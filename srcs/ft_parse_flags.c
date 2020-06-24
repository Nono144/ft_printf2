#include "ft_printf.h"

static int		ft_is_in_tab(char *tab, char c)
{
	while (*tab)
	{
		if (*tab == c)
			return (c);
		tab++;
	}
	return (0);
}

void	ft_parse_flags(t_str *str, char *s)
{
	int i;
	char c;

	i = 0;
	str->flags[i] = '\0';
	while ((c = ft_is_in_tab("-+0 #", s[str->i])) != 0)
	{
		if (!ft_is_in_tab(str->flags, c))
			str->flags[i++] = s[str->i];
		str->flags[i] = '\0';
		str->i++;
	}
}
