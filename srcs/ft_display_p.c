#include "ft_printf.h"

static int	ft_load_pound(char *s_num, t_str *str)
{
	if (s_num[0] == '\0' && str->precision < 0)
		return (3);
	return (2);
}

static void	ft_display_before(t_str *str, size_t len, int l_pound)
{
	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0') && str->precision < 0)
	{
		ft_write(1, "0x0", l_pound, str);
		ft_display_z(ft_max(str->precision, len), str->width - l_pound, str);
	}
	else if (!ft_is_flag(str, '-'))
	{
		ft_display_g(ft_max(str->precision, len), str->width - l_pound, str);
		ft_write(1, "0x0", l_pound, str);
	}
	else
		ft_write(1, "0x0", l_pound, str);
	ft_display_z(len, str->precision, str);
}

void		ft_display_p(t_str *str)
{
	char 		*s_num;
	size_t		len;
	int 		l_pound;

	ft_get_unum(str);
	s_num = ft_itoa_hex(str, 0);
	len  = ft_strlen(s_num);
	l_pound = ft_load_pound(s_num, str);
	ft_display_before(str, len, l_pound);
	ft_write(1, s_num, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(ft_max(str->precision, len), str->width - l_pound, str);
	free(s_num);
}
