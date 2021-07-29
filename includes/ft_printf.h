#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../src/libft/libft.h"
# define LIST_SPEC "cspdiuxX%"

typedef struct s_spec
{
	va_list		ap;
	int			width;
	int			prec;
	char		spec;
	char		flags;
	char		*str;
	int			len;
	int			minus;	
}				t_spec;

int		ft_putchar(char c);
int		ft_putcharstr(char c, int num);
int		ft_sizelen_hex_pointer(unsigned int n);
int		ft_sizelen_pointer(unsigned long n);

void	ft_processor(t_spec *spec);
char	*pars(t_spec *spec);

int		ft_output_char(t_spec *spec);
int		ft_output_str(t_spec *spec);
int		ft_output_int(t_spec *spec);
int		ft_output_unsigned(t_spec *spec);
int		ft_output_hex(t_spec *spec);
int		ft_output_pointer(t_spec *spec);

void	ft_minus(t_spec *spec, int len, char *str_int);
void	ft_space_digit(t_spec *spec, int len);
void	ft_space_digit_minus(t_spec *spec, int len, char *str_int);

void	ft_putstr(char const *s, int num);
int		ft_precision(int prec, char *s);
int		ft_printf(const char *s, ...);
void	ft_init(t_spec *spec, const char *s);
int		ft_prec_digit(t_spec *spec, int len, char *str_int);

#endif