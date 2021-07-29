#include "ft_printf.h"

static int	int_len(int d)
{
	int	len;

	len = 1;
	if (d < 0)
		len++;
	while (d / 10 != 0)
	{
		len++;
		d = d / 10;
	}
	return (len);
}

char	*int_init(va_list ap, t_spec *spec, int *len)
{
	char	*str;
	long	d;

	d = va_arg(ap, int);
	*len = int_len(d);
	if (d < 0 && (spec->prec >= *len || (spec->flags == '0' && spec->prec < 0)))
	{
		d *= -1;
		spec->minus = 1;
		spec->len++;
		(*len)--;
	}
	str = ft_itoa(d);
	return (str);
}

int	ft_output_int(t_spec *spec)
{
	char	*str_int;
	int		len;

	str_int = int_init(spec->ap, spec, &len);
	ft_prec_digit(spec, len, str_int);
	return (0);
}
