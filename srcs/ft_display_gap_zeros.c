#include "ft_printf.h"
#include "libft.h"

int		ft_lpound(t_str *str)
{
		if (ft_is_flag(str, '#') != 0 && str->type == 'x')
			return (2);
		if (ft_is_flag(str, '#') != 0 && str->type == 'X')
			return (2);
		return (0);
}

size_t		ft_display_g(t_str *str, size_t len)
{
		int step;
		int flag;

		step = str->len;
		flag = ft_lpound(str);//
		str->precision = (str->precision < 0 ? 1 : str->precision);
		if (ft_is_flag(str, '+') || ft_is_flag(str, ' ') || str->sign)//
			flag += 1;
		while ((str->len - step) < (str->width -flag - ft_max(str->precision, len)))
			ft_write (1, " ", 1, str);
		return (str->i);
}

size_t		ft_display_gs(t_str *str, size_t len)
{
		int step;

		str->precision = (str->precision < 0 ? 0 : str->precision);
		step = str->len;
		while ((str->len - step) < (str->width - ft_min(str->precision, len)))
			ft_write (1, " ", 1, str);
		return (str->i);
}

size_t		ft_display_zeroes(t_str *str, size_t len)
{
		int step;
		int precision;
		int flag;

		step = str->len;
		precision = (str->precision < 0 ? 1 : str->precision);
		flag = ft_lpound(str) + (ft_is_flag(str, '+') || str->sign || ft_is_flag(str,' '));
		while ((str->len - step) < (precision - (int)len))
			ft_write(1, "0", 1, str);
		if (ft_is_flag(str, '0') && (str->precision < 0)) 
			while ((str->len - step) < (str->width - flag - (int)(len)))
				ft_write(1, "0", 1, str);
		return (str->len);
}
