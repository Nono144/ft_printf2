#include "ft_printf.h"

static 	int	ft_get_len(unsigned long long num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static int	ft_get_len_hex(unsigned long long num)
{
	size_t len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_hex(unsigned long long num, int maj)
{
	unsigned long long 	mod;
	size_t 			len;
	char		*str;

	len = ft_get_len_hex(num);
	if ((str = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[len--] = '\0';	
	while (num != 0)
	{
		mod = num % 16;
		if (mod <= 9)
			str[(len--)] = '0' + mod;
		else
			str[(len--)] = 'a'+ maj * ('A' - 'a') + mod - 10;
		num /= 16;
	}
	return (str);
}


char	*ft_itoa_n(unsigned long long num)
{
	size_t	len;
	char *str;

	len = ft_get_len(num);
	if ((str = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	str[len--] = '\0';
	while (num != 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
