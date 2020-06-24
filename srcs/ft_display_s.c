#include "ft_printf.h"
#include "libft.h"

static unsigned int	ft_strlen_ls(wchar_t *s, int precision)
{
	unsigned i;

	i = 0;
	while (*s)
	{
		if (*s < 0x7f && precision - i >= 1)
			i++;
		else if (*s < 0x7ff && precision  - i >= 2)
			i += 2;
		else if (*s < 0xffff && precision - i >= 3)
			i += 3;
		else if (precision - i >= 4)
			i += 4;
		else
			return (i);
		s++;
	}
	return (i);
}

static void	ft_display_ss(t_str *str)
{
	size_t len;

	ft_get_string(str);
	if (str->arg == NULL)
		str->arg = "(null)";
	len = ft_strlen(str->arg);
	if (str->precision < 0)
		str->precision = len;
	if (ft_is_flag(str, '0') && !ft_is_flag(str, '-'))
		ft_display_z(0, str->width - ft_min(str->precision, len), str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(0, str->width - ft_min(str->precision, len), str);
	ft_write(1, str->arg,  ft_min(len, str->precision), str);
	if (ft_is_flag(str, '-'))
		ft_display_g(0, str->width - ft_min(str->precision, len), str);
}

static void	ft_display_ws(t_str *str)
{
	char *ls;
	unsigned int len;

	ft_get_wstring(str);
	if (str->arg == NULL)
		str->arg= L"(null)";
	if (str->precision < 0)
		str->precision = (unsigned int)(~0) >> 1;
	len = ft_strlen_ls(str->arg, str->precision);
	ls = malloc(len + 1);
	ft_load_ls(str->arg, ls, len);
	if (ft_is_flag(str, '0') && !ft_is_flag(str, '-'))
		ft_display_z(0, str->width - ft_min(str->precision, len), str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(0, str->width - ft_min(str->precision, len), str);
	ft_write(1, ls, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(0, str->width - ft_min(str->precision, len), str);
}

void	ft_display_s(t_str *str)
{
	if (ft_strcmp(str->length, "l") == 0)
		ft_display_ws(str);
	else
		ft_display_ss(str);
}
