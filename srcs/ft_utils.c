#include "ft_printf.h"
#include "libft.h"

size_t		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ft_is_flag(t_str *str, char c)
{
	int i;

	i = 0;
	while (str->flags[i])
	{
		if (str->flags[i] == c)
			return (c);
		i++;
	}
	return (0);
}

void		ft_write(int fd, char *buf, size_t len, t_str *str)
{
	write(fd, buf, len);
	str->len += (int)len;
}

void		ft_erase_flag(t_str *str, char flag)
{
	int i;

	i = 0;
	while (str->flags[i])
	{
		if (str->flags[i] == flag)
			str->flags[i] = 1;
		i++;	
	}
}
