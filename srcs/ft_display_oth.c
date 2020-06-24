#include "ft_printf.h"

void	ft_display_oth(t_str  *str)
{
	if (ft_is_flag(str, '0') && !ft_is_flag(str, '-'))
		ft_display_z(0, str->width - 1, str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(0, str->width - 1, str);
	ft_write(1, &(str->type), 1, str);
	if (ft_is_flag(str, '-'))
		ft_display_g(0, str->width - 1, str);
}


