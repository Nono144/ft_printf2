#include "ft_printf.h"
#include "libft.h"

char *mask_type = "cdspuixX%";

static int	ft_isalpha(char c)
{
	if (c <= '9' && c >= '0')
		return (c);
	return (0);
}

/*static intmax_t		ft_get_num(t_str *str)
{
	intmax_t	num;

	num = (intmax_t)(va_arg(str->args, int));
	return (num);
}*/

static int	ft_parse_type(t_str *str, char *s)
{
	/*int i;
	char c;

	i = 0;
	while (mask_type[i])
	{
		if ((c = mask_type[i]) == s[str->i])
		{
			str->type = c;
			str->i++;
			return ((int)c);
		}
		i++;
	}*/
	if (s[str->i] != '\0')
		str->type = s[str->i++];
	return (0);
}

static size_t	ft_parse_width(t_str *str, char *s)
{
	int num;
	int width;

	width = (ft_isalpha(s[str->i]) == 0 ? -1 : 0);
	if (s[str->i] == '*')
	{
		num = (int)ft_get_num(str);
		if (num > 0)
		{
			width = (int)num;
			str->width = (size_t)width;
		}
		str->i++;
	}
	else
	{
		while(ft_isalpha(s[str->i]))
		{
			width = 10 * width  + (s[str->i] - '0');
			str->i++;
		}
		str->width = width;
	}
	return (str->i);
}

static	int	ft_parse_precision(t_str *str, char *s)
{
	int num;
	int precision;
	
	str->precision = -1;
	precision = 0; /* prend la valeur de width sinon */
	if (s[str->i] == '.')
	{
		str->i++;
		if (s[str->i] == '*')
		{
			num = (int)ft_get_num(str);
			if (num > 0)
				precision = (int)num;
			str->precision = precision;
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
	return (str->i);
}

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

size_t	ft_parse_flags(t_str *str, char *s)
{
	static char *mask_flags;
	int i;
	char c;

	mask_flags = "-+0 #";
	i = 0;
	str->flags[i] = '\0';
	while ((c = ft_is_in_tab(mask_flags, s[str->i])) != 0)
	{
		if (!ft_is_in_tab(str->flags, c))
			str->flags[i++] = s[str->i];
		str->flags[i] = '\0';
		str->i++;
	}
	return (str->i);
}

static  int	ft_parse_len(t_str *str, char *s)
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
		str->length[i] = '\0';
		str->i++;
	}
	return (str->i);
}

size_t	ft_parse(t_str *str, char *s)
{
	size_t len;
	int c;

	len = 0;
	if ((c = s[str->i]) == '%')
	{
		str->i++;
		ft_initialize(str);
		ft_parse_flags(str, s);
		ft_parse_width(str, s);
		ft_parse_precision(str, s);
		ft_parse_len(str, s);
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
	return (len);
}
