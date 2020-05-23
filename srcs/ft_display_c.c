#include "ft_printf.h"
#include "libft.h"

static int	ft_get_char(t_str *str)
{
	char c;

	c = (char)(va_arg(str->args, int));
	return (c);
}

int	ft_display_c(t_str *str)
{
	char c;
	int len;

	c = ft_get_char(str);
	len = 1;		
	if (str->precision < 0)
		str->precision = len;
	if (!ft_is_flag(str, '-'))
		ft_display_gs(str, len);
	ft_write(1, &c, len, str);
	if (ft_is_flag(str, '-'))
		ft_display_gs(str, len); 
	return (len);
}
