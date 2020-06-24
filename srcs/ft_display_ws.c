#include "ft_printf.h"

int		ft_load_2bc(wchar_t *ws, char *ls)
{
	*(ls) = 0b11000000 | ((0b00011111) & (*ws >> 6));
	*(ls+1) = 0b10000000 | (0b00111111  & *ws);
	return (2);
}

int		ft_load_3bc(wchar_t *ws, char *ls)
{
	*(ls) = 0b11100000 | (0b00001111 & (*ws >> 12));
	*(ls + 1) = 0b10000000 | (0b00111111 & (*ws >> 6));
	*(ls + 2) = 0b10000000 | (0b00111111 & *ws);
	return (3);
}

int		ft_load_4bc(wchar_t *ws, char *ls)
{
	*(ls) = 0b11110000 | (0b00000111 & (*ws >> 18));
	*(ls+1) = 0b10000000 | (0b00111111 & (*ws >> 12));
	*(ls+2) = 0b10000000 | (0b00111111 & (*ws >> 6));
	*(ls+3) = 0b10000000 | (0b00111111 & *ws);
	return (4);
}

void		ft_load_ls(wchar_t *ws, char *ls, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (len > i)
	{
		if (*ws < 0x7f)
			ls[i++] = (char)(*ws);
		else if (*ws < 0x7ff)
			i += ft_load_2bc(ws, ls + i);
		else if (*ws < 0xffff)
			i += ft_load_3bc(ws, ls + i);
		else if (*ws < 0x10ffff)
			i += ft_load_4bc(ws, ls + i);
		ws++;
	}
}
