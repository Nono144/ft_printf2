#include "ft_printf.h"

static void		ft_display_4bc(t_str *str)
{
	unsigned char lc[4];

	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0'))
		ft_display_z(4, str->width, str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(4, str->width, str);
	lc[3] = 0b10000000 | (0b00111111 & str->num);
	lc[2] = 0b10000000 | (0b00111111 & (str->num >> 6));
	lc[1] = 0b10000000 | (0b00111111 & (str->num >> 12));
	lc[0] = 0b11110000 | (0b00000111 & (str->num >> 18));
	if (ft_is_flag(str, '-'))
		ft_display_g(4, str->width, str);
	write(1, lc, 4);
	str->len+=4;
}

static void		ft_display_3bc(t_str *str)
{
	unsigned char lc[3];

	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0'))
		ft_display_z(3, str->width, str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(3, str->width, str);
	lc[2] = 0b10000000 | (0b00111111 & str->num);
	lc[1] = 0b10000000 | (0b00111111 & (str->num >> 6));
	lc[0] = 0b11100000 | (0b00001111 & (str->num >> 12));
	write(1, lc, 3);
	if (ft_is_flag(str, '-'))
		ft_display_g(3, str->width, str);
	str->len+=3;
}

static void		ft_display_2bc(t_str *str)
{
	unsigned char lc[2];

	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0'))
		ft_display_z(2, str->width, str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(2, str->width, str);	
	lc[1] = 0b10000000 | (0b00111111  & str->num);
	lc[0] = 0b11000000 | ((0b00011111) & (str->num >> 6));
	write(1, lc, 2);
	if (ft_is_flag(str, '-'))
		ft_display_g(2, str->width, str);
	str->len+=2;
}

static void		ft_display_1bc(t_str *str)
{
	if (!ft_is_flag(str, '-') && ft_is_flag(str, '0'))
		ft_display_z(1, str->width, str);
	else if (!ft_is_flag(str, '-'))
		ft_display_g(1, str->width, str);
	write(1, &str->num, 1);
	if (ft_is_flag(str, '-'))
		ft_display_g(1, str->width, str);
	str->len++;
}

void	ft_display_c(t_str *str)
{
	ft_get_char(str);
	if (str->num <= 0x7f)
		ft_display_1bc(str);
	else if (str->num <= 0x7ff)
		ft_display_2bc(str);
	else if (str->num <= 0xffff)
		ft_display_3bc(str);
	else if (str->num <= 0x10ffff)
		ft_display_4bc(str);
}
