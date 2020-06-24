#include "ft_printf.h"

static 	int	ft_get_len(uintmax_t num, char type)
{
	int i;
	int base;

	i = 0;
	if (type == 'o')
		base = 8;
	else if (type == 'h')
		base = 16;
	else
		base = 10;
	while (num != 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_hex(t_str *str, int maj)
{
	size_t 			len;
	int 			mod;
	char			*s;

	len = ft_get_len(str->unum, 'h');
	if ((s = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[len--] = '\0';	
	while (str->unum != 0)
	{
		mod = str->unum % 16;
		if (mod <= 9)
			s[(len--)] = '0' + mod;
		else
			s[(len--)] = 'a' - 10 + maj * ('A' - 'a') + mod;
		str->unum /= 16;
	}
	return (s);
}

char	*ft_itoa_o(t_str *str)
{
	size_t 			len;
	char			*s;

	len = ft_get_len(str->unum, 'o');
	if ((s = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[len--] = '\0';
	while (str->unum != 0)
	{
		s[(len--)] = '0' + str->unum % 8;
		str->unum /= 8;
	}
	return (s);
}

char	*ft_itoa_u(t_str *str)
{
	unsigned int 	len;
	char		*s;

	len = ft_get_len(str->unum, 'd');
	if ((s = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[len--] = '\0';
	while (str->unum != 0)
	{
		s[len--] = (str->unum % 10) + '0';
		str->unum /= 10;
	}
	return (s);
}

char	*ft_itoa_n(t_str *str)
{
	unsigned int 	len;
	char *s;

	str->unum = (str->num < 0 ? -str->num : str->num);
	len = ft_get_len(str->unum, 'd');
	if ((s = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	s[len--] = '\0';
	while (str->unum != 0)
	{
		s[len--] = (str->unum % 10) + '0';
		str->unum /= 10;
	}
	return (s);
}
