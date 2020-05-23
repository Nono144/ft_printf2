#include "ft_printf.h"
#include "libft.h"

size_t			ft_display_d(t_str *str)
{
	long			num;
	unsigned long long 	unum;
	char 			*s_num;
	size_t			len;
	char flag_sign;

	num = ft_get_num(str);
	if (num < 0)
	{
		unum = -num;
		str->sign = 1;
	}
	else
		unum = num;
	s_num = ft_itoa_n(unum);
	len  = ft_strlen(s_num);
	flag_sign = (ft_is_flag(str, '-') == 0);
	if (flag_sign && (ft_is_flag(str, '0') == 0 || str->precision != -1))
		ft_display_g(str, len);
	if (str->sign)//
		ft_write(1, "-", 1, str);//
	else if (ft_is_flag(str, '+'))//
		ft_write(1, "+", 1, str);//
	else if (ft_is_flag(str, ' '))//
	       ft_write(1, " ", 1, str);//	
	ft_display_zeroes(str, len);
	ft_write(1, s_num, len, str);
	if (!flag_sign)
		ft_display_g(str, len);
	free(s_num);
	return (len);
}

