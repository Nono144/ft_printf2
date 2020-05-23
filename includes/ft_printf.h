#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
//#include <stdint.h>
//#include <ctype.h>
//#include <limits.h>

int	ft_strcmp(char *s1, char *s2);

typedef struct s_str
{
	va_list		args;
	size_t		i;
	int		precision;
	int		width;
	char		type;
	char		sign;
	char		convert[6];
	char		flags[6];
	char		length[6];
	int		len;
}		t_str;


size_t	ft_parse(t_str *str, char *s);
size_t	ft_display_d(t_str *str);
void	ft_initialize(t_str *str);
char	*ft_strnnew(size_t size);
int	ft_printf(char *s, ...);
void	ft_display(t_str *str);
int	ft_display_c(t_str *str);
int	ft_display_s(t_str *str);
char	*ft_itoa_hex(unsigned long long num, int maj);
size_t	ft_display_p(t_str *str);
size_t	ft_display_x(t_str *str, int maj);
size_t	ft_display_u(t_str *str);
size_t	ft_display_g(t_str *str, size_t len);
size_t	ft_display_gs(t_str *str, size_t len);
size_t	ft_display_zeroes(t_str *str, size_t len);
int		ft_is_flag(t_str *str, char c);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
size_t		ft_strlen(char *s);
void		ft_write(int fd, char *buf, size_t len, t_str *str);
char		*ft_itoa_n(unsigned long long num);
void		ft_erase_flag(t_str *str, char flag);
long long		ft_get_num(t_str *str);
unsigned long long 	ft_get_unum(t_str *str);
	
#endif
