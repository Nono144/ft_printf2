#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <stdint.h>
//#include <ctype.h>
//#include <limits.h>

int	ft_strcmp(char *s1, char *s2);

typedef struct s_str
{
	va_list		args;
	intmax_t	num;
	uintmax_t	unum;
	void		*arg;
	unsigned int	i;
	int		precision;
	int		width;
	char		type;
	char		convert[6];
	char		flags[6];
	char		length[6];
	int		len;
}		t_str;

int		ft_printf(char *s, ...);
void		ft_parse(t_str *str, char *s);
void		ft_parse_size(t_str *str, char *s);
void		ft_parse_precision(t_str *str, char *s);
void		ft_parse_type(t_str *str, char *s);
void		ft_parse_width(t_str *str, char *s);
void		ft_parse_flags(t_str *str, char *s);
void		ft_display_d(t_str *str);
void		ft_display(t_str *str);
void		ft_display_c(t_str *str);
void		ft_display_s(t_str *str);
void		ft_display_p(t_str *str);
void		ft_display_x(t_str *str, int maj);
void		ft_display_u(t_str *str);
void		ft_display_g(int len1, int len2, t_str *str);
void		ft_display_z(int len1, int len2, t_str *str);
void		ft_display_gs(t_str *str, size_t len);
void		ft_display_zs(t_str *str, size_t len);
void		ft_display_oth(t_str *str);
void		ft_display_goth(t_str *str);
void		ft_display_zoth(t_str *str);
void		ft_display_o(t_str *str);
void		ft_get_num(t_str *str);
void		ft_get_unum(t_str *str);
void		ft_get_char(t_str *str);
void		ft_get_wstring(t_str *str);
void		ft_get_string(t_str *str);
void		ft_initialize(t_str *str);
void		ft_load_ls(wchar_t *ws, char *ls, unsigned int len);
int		ft_is_flag(t_str *str, char c);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
size_t		ft_strlen(char *s);
void		ft_write(int fd, const void *buf, size_t len, t_str *str);
char		*ft_itoa_hex(t_str *str, int maj);
char		*ft_itoa_n(t_str *str);
char		*ft_itoa_o(t_str *str);
char		*ft_itoa_u(t_str *str);

	
#endif
