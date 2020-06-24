#include "ft_printf.h"
#include "libft.h"


/*void		ft_display_gs(t_str *str, size_t len)
{
		int step;

		str->precision = (str->precision < 0 ? 0 : str->precision);
		step = str->len;
		while ((str->len - step) < (str->width - ft_min(str->precision, len)))
			ft_write (1, " ", 1, str);
}


void		ft_display_zs(t_str *str, size_t len)
{
		int step;

		step = str->len;
		while ((str->len - step) < (str->width - ft_min(str->precision, len)))
			ft_write (1, "0", 1, str);
}*/

void	ft_display_g(int len1, int len2, t_str *str)
{
	while (len1 < len2)
	{
		ft_write(1, " ", 1, str);
		len1++;
	}
}

void	ft_display_z(int len1, int len2, t_str *str)
{
	while (len1 < len2)
	{
		ft_write(1, "0", 1, str);
		len1++;
	}
}

/*void		ft_display_goth(t_str *str)
{
		int step;

		step = str->len;
		while ((str->len - step) < str->width - 1)
			ft_write (1, " ", 1, str);
}

void		ft_display_zoth(t_str *str)
{
		int step;

		step = str->len;
		while ((str->len - step) < str->width - 1)
			ft_write (1, "0", 1, str);
}
*/
