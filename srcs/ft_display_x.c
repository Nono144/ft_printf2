#include "ft_printf.h"
#include "libft.h"

/*static intmax_t		ft_get_num(t_str *str)
{
	unsigned	num;

	num = (unsigned)(va_arg(str->args, unsigned int));
	return (num);
}*/

static	void		ft_display_pound(t_str *str, int maj)
{
	ft_write(1, "0", 1, str);
	if (maj == 0)
		ft_write(1, "x", 1, str);
	else
		ft_write(1, "X", 1, str);
}

size_t		ft_display_x(t_str *str, int maj)
{
	unsigned long long num;
	char 		*s_num;
	size_t		len;

	num = ft_get_unum(str);
	s_num = ft_itoa_hex(num, maj);
	len  = ft_strlen(s_num);
	if (num == 0)
		ft_erase_flag(str, '#');
	if (!ft_is_flag(str, '-') && (ft_is_flag(str, '0') == 0 || str->precision != -1))
		ft_display_g(str, len);
	if (ft_is_flag(str, '#') != 0 )
		ft_display_pound(str, maj);
	ft_display_zeroes(str, len);
	ft_write(1, s_num, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(str, len);
	free(s_num);
	return (len);
}
