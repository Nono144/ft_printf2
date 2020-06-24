#include "ft_printf.h"

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
	else if (str->type == 'x')
		ft_display_x(str, 0);
	else if (str->type == 'X')
		ft_display_x(str, 1);
	else if (str->type == 'u')
		ft_display_u(str);
	else if (str->type == 'i')
		ft_display_d(str);
	else if (str->type == 'o')
		ft_display_o(str);
	else 
		ft_display_oth(str);
}
