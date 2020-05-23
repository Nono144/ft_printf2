#include "ft_printf.h"
#include "libft.h"



/*static 	unsigned 	ft_get_num(t_str *str)
{
	unsigned	num;

	num = (unsigned)(va_arg(str->args, unsigned int));
	return (num);
}*/


size_t			ft_display_u(t_str *str)
{
	unsigned long long num;
	char 		*s_num;
	size_t		len;
	char flag_sign;

	num = ft_get_unum(str);
	s_num = ft_itoa_n(num);
	len  = ft_strlen(s_num);
	flag_sign = (ft_is_flag(str, '-') == 0);
	//printf("\nYOYO: %d\n", flag_sign);
	//str->precision = (str->precision < 0 ? 1 : str->precision);
	if (flag_sign  && (ft_is_flag(str, '0') == 0 || (str->precision != -1)))
		ft_display_g(str, len);
	ft_write(1, "-", str->sign, str);
	ft_display_zeroes(str, len);
	ft_write(1, s_num, len, str);
	if (!flag_sign)
		ft_display_g(str, len);
	free(s_num);
	return (len);
}
