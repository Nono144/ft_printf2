#include "ft_printf.h"
#include "libft.h"

/*static intmax_t		ft_get_num(t_str *str)
{
	unsigned long num;

	num = (unsigned long)(va_arg(str->args, unsigned long));
	return (num);
}*/

size_t	ft_display_p(t_str *str)
{
	unsigned long long num;
	char *s_num;
	size_t	len;
	char l_prefix;

	l_prefix = 2;
	if ((num = ft_get_unum(str)) == 0)
	{
		s_num = "(nil)";
		l_prefix = 0;
	}
	else
		s_num = ft_itoa_hex(num, 0);
	len = ft_strlen(s_num);
	if (!ft_is_flag(str, '-'))
		ft_display_g(str, len + l_prefix);
	ft_write(1, "0x", l_prefix, str);
	ft_write(1, s_num, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(str, len + l_prefix);
	return (len);
}
