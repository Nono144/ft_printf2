#include "ft_printf.h"

static	int	ft_is_in_tab(char *tab, char c)
{
	while (*tab)
	{
		if (*tab == c)
			return (c);
		tab++;
	}
	return (0);
}

void	ft_parse_size(t_str *str, char *s)
{
	static char *mask_length;
	int i;
	char c;

	mask_length = "lh";
	i = 0;
	str->length[i] = '\0';
	while ((c = ft_is_in_tab(mask_length, s[str->i])) != 0 && i < 2)
	{
		str->length[i++] = s[str->i];
		str->i++;
	}
	str->length[i] ='\0';
}
