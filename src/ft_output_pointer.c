#include "ft_printf.h"

void	print_p(t_spec *spec, int len, char *str_int)
{
	if (spec->flags =='0' && spec->prec < 0 )
	{
		ft_putcharstr('-', 1);
	}
	ft_space_digit(spec, len);
	if (spec->prec > len)
	{
		write(1, "0x", 2);
		ft_putcharstr('0', spec->prec - len);
		spec->len += spec->prec - len;
	}
	else
		write(1, "0x", 2);
	ft_putstr(str_int, len);
}

static char	*ft_itoa_pointer(unsigned long n)
{
	char	*str;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_sizelen_pointer(n);
	str = (char *) malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		if (n % 16 > 9)
			str[i] = 'a' + (n % 16) - 10;
		else
			str[i] = '0' + (n % 16);
		n /= 16;
		i--;
	}
	return (str);
}

static char	*pointer_init(va_list ap, t_spec *spec, int *len)
{
	char			*str;
	unsigned long	d;

	d = va_arg(ap, unsigned long);
	*len = ft_sizelen_pointer(d);
	if (d < 0 && (spec->prec >= *len || (spec->flags == '0' && spec->prec < 0)))
	{
		d *= -1;
		spec->minus = 1;
		spec->len++;
		(*len)--;
	}
	str = ft_itoa_pointer(d);
	return (str);
}

static void	ft_minus_minus( t_spec *spec, int len, char *str_int)
{
	if (spec->prec > len)
	{
		if (spec->minus)
			ft_putcharstr('-', 1);
		ft_putcharstr('0', spec->prec - len);
		spec->len += spec->prec - len;
	}
	ft_space_digit_minus(spec, len, str_int);
}

int	ft_output_pointer(t_spec *spec)
{
	char	*str_int;
	int		len;

	str_int = pointer_init(spec->ap, spec, &len);
	spec->width -= 2;
	if (spec->prec == 0)
	{
		ft_putcharstr(' ', spec->width);
		if (spec->width > 0)
			spec->len += spec->width;
		if (ft_strlen(str_int) == 1 && str_int[0] == '0')
			spec->len += write(1, "0x", 2);
		free(str_int);
		return (0);
	}
	if (spec->flags == '-' )
	{
		write(1, "0x", 2);
		ft_minus_minus(spec, len, str_int);
	}
	else
		print_p(spec, len, str_int);
	spec->len += len + 2 ;
	free(str_int);
	return (0);
}
