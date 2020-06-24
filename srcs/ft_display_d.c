#include "ft_printf.h"

static int	ft_load_pound(t_str *str, char *s_num)
{
	if (s_num[0] == '\0' && str->precision < 0)
		return (1);
	return (0);
}

static 	int	ft_load_sign(t_str *str)
{
	if (str->num < 0 || ft_is_flag(str, '+'))
		return (1);
	else if (ft_is_flag(str, ' '))
		return (2);
	return (0);
}

static void	ft_display_sp_si(t_str *str, int l_sign)
{
	if (l_sign == 1)
	{
		if (str->num < 0)
			ft_write(1, "-", 1, str);
		else 
			ft_write(1, "+", 1, str);
	}
	else if (l_sign == 2)
		ft_write(1, " ", 1, str);
}

static	void	ft_display_before(t_str *str, size_t len, int l_pound, int l_sign)
{
	int l_s;

	l_s = l_pound + (l_sign != 0);
	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0') && str->precision < 0)
	{	
		ft_display_sp_si(str, l_sign);
		ft_display_z(ft_max(str->precision, len), str->width - l_s, str);
	}
	else if (!ft_is_flag(str, '-'))
	{
		ft_display_g(ft_max(str->precision, len), str->width - l_s, str);
		ft_display_sp_si(str, l_sign);
	}
	else
		ft_display_sp_si(str, l_sign);
	ft_write(1, "0", l_pound, str);
	ft_display_z(len, str->precision, str);
}

void		ft_display_d(t_str *str)
{
	char 		*s_num;
	size_t		len;
	int 		l_pound;
	int		l_sign;

	ft_get_num(str);
	s_num = ft_itoa_n(str);
	l_pound = ft_load_pound(str, s_num);
	l_sign = ft_load_sign(str);
	len  = ft_strlen(s_num);
	ft_display_before(str, len, l_pound, l_sign);
	ft_write(1, s_num, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(ft_max(str->precision, len), str->width - l_pound - (l_sign != 0), str);
	free(s_num);
}
