#include "ft_printf.h"

static char	*ft_itoa_hex(unsigned int n, char spec)
{
	char	*str;
	size_t	i;

	if (spec == 'x')
		spec = 'a';
	else
		spec = 'A';
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_sizelen_hex_pointer(n);
	str = (char *) malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		if (n % 16 > 9)
			str[i] = spec + (n % 16) - 10;
		else
			str[i] = '0' + (n % 16);
		n /= 16;
		i--;
	}
	return (str);
}

static char	*hex_init(va_list ap, t_spec *spec, int *len)
{
	char			*str;
	unsigned int	d;

	d = va_arg(ap, unsigned);
	*len = ft_sizelen_hex_pointer(d);
	if (d < 0 && (spec->prec >= *len || (spec->flags == '0' && spec->prec < 0)))
	{
		d *= -1;
		spec->minus = 1;
		spec->len++;
		(*len)--;
	}
	str = ft_itoa_hex(d, spec->spec);
	return (str);
}

int	ft_output_hex(t_spec *spec)
{
	char	*str_int;
	int		len;

	str_int = hex_init(spec->ap, spec, &len);
	ft_prec_digit(spec, len, str_int);
	return (0);
}
