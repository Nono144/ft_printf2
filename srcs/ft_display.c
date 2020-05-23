#include "ft_printf.h"

static  int	ft_masktype(char c)
{
	char *masktype;
	int i;

	masktype = "cdDospuixX%";
	i = 0;
	while (masktype[i])
		if (c == masktype[i++])
			return (c);
	return (0);
}

void	ft_display(t_str *str)
{
	if (str->type == 'd')
		ft_display_d(str);
	else if (str->type == 'c')
		ft_display_c(str);
	else if (str->type == 's')
		ft_display_s(str);
	else if (str->type == 'p')
		ft_display_p(str);
	else if (str->type == 'x' || str->type == 'X')
		ft_display_x(str, ('x' - str->type)/('x' - 'X'));
	else if (str->type == 'u')
		ft_display_u(str);
	else if (str->type == '%')
		ft_write(1, "%", 1, str);
	else if (str->type == 'i')
		ft_display_d(str);
	else if (ft_masktype(str->type))
		ft_display_c(str);
	else 
	{
		str->len += ft_printf("%%%s", str->flags);
		if (str->width != -1)
			str->len += ft_printf("%d", str->width);
		if (str->precision != -1)
			str->len += ft_printf(".%d", str->precision);
		str->len +=ft_printf("%c", str->type);
	}
}
