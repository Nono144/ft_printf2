#include "libft.h"

static int		taille_str(uintmax_t n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}


char			*ft_itoa_umax(uintmax_t n)
{
	char			*str;
	size_t			len;

	len = taille_str(n);
	str = ft_strnnew(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	while (len > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[len] = n % 10 + '0';
	return (str);
}
