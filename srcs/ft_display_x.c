#include "ft_printf.h"
#include "libft.h"

static	void		ft_display_pound(t_str *str, int l_pound, int maj)
{
	if (l_pound == 0)
		return ;
	if (maj == 0)
		ft_write(1, "0x", l_pound, str);
	else
		ft_write(1, "0X", l_pound, str);
}

static int	ft_load_pound(t_str *str, char *s_num)
{
	if (s_num[0] == '\0' && str->precision < 0)
		return (1);
	if (s_num[0] != '\0' && ft_is_flag(str, '#'))
		return (2);
	return (0);
}

static void	ft_display_before(t_str *str, size_t len, int l_pound, int maj)
{
	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0') && str->precision < 0)
	{
		ft_display_pound(str, l_pound, maj);
		ft_display_z(ft_max(str->precision, len), str->width - l_pound, str);
	}
	else if (!ft_is_flag(str, '-'))
	{
		ft_display_g(ft_max(str->precision, len), str->width - l_pound, str);
		ft_display_pound(str, l_pound, maj);
	}
	else
		ft_display_pound(str, l_pound, maj);
	ft_display_z(len, str->precision, str);
}

void		ft_display_x(t_str *str, int maj)
{
	char 		*s_num;
	size_t		len;
	int 		l_pound;

	ft_get_unum(str);
	s_num = ft_itoa_hex(str, maj);
	l_pound = ft_load_pound(str, s_num);
	len  = ft_strlen(s_num);
	ft_display_before(str, len, l_pound, maj);
	ft_write(1, s_num, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(ft_max(str->precision, len), str->width - l_pound, str);
	free(s_num);
}
