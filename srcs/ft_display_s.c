#include "ft_printf.h"
#include "libft.h"

static char	*ft_get_string(t_str *str)
{
	char *s;

	s = (char *)(va_arg(str->args, char*));
	return (s);
}

int		ft_display_s(t_str *str)
{
	char *s;
	size_t len;

	if ((s = (char *)ft_get_string(str)) == NULL)
	{
		s = "(null)";
		if (str->precision > 0 && str->precision <6)
			s= "";
	}
	len = ft_strlen(s);
	//printf("\nprec:%d  len:%ld\n", str->precision, len); 
	if (str->precision < 0)
		str->precision = len;
	if (!ft_is_flag(str, '-'))
		ft_display_gs(str, len);
	ft_write(1, s,  ft_min(len, str->precision), str);
	if (ft_is_flag(str, '-'))
		ft_display_gs(str, len); 
	return (ft_strlen(s));
}
