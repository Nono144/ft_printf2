#include "ft_printf.h"

static	void		ft_display_pound(t_str *str, int l_pound)
{
	if (l_pound == 0)
		return ;
	else
		ft_write(1, "0", l_pound, str);
}

static int	ft_load_pound(t_str *str, char *s_num)
{
	if (s_num[0] == '\0' && str->precision < 0)
		return (1);
	return (0);
}

void		ft_display_u(t_str *str)
{
	char 		*s_num;
	size_t		len;
	int 		l_pound;

	ft_get_unum(str);
	s_num = ft_itoa_u(str);
	l_pound = ft_load_pound(str, s_num);
	len  = ft_strlen(s_num);
	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0') && str->precision < 0)
		ft_display_z(ft_max(str->precision, len), str->width - l_pound, str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(ft_max(str->precision, len), str->width - l_pound, str);
	ft_display_pound(str, l_pound);
	ft_display_z(len, str->precision, str);
	ft_write(1, s_num, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(ft_max(str->precision, len), str->width - l_pound, str);
	free(s_num);
}
