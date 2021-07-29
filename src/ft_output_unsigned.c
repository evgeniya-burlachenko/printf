#include "ft_printf.h"

static int	ft_sizelen_uint(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_uint(unsigned int n)
{
	char	*str;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_sizelen_uint(n);
	str = (char *) malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

static char	*uint_init(va_list ap, t_spec *spec, int *len)
{
	char			*str;
	unsigned int	d;

	d = va_arg(ap, int);
	*len = ft_sizelen_uint(d);
	if (d < 0 && (spec->prec >= *len || (spec->flags == '0' && spec->prec < 0)))
	{
		d *= -1;
		spec->minus = 1;
		spec->len++;
		(*len)--;
	}
	str = ft_itoa_uint(d);
	return (str);
}

int	ft_output_unsigned(t_spec *spec)
{
	char	*str_int;
	int		len;

	str_int = uint_init(spec->ap, spec, &len);
	ft_prec_digit(spec, len, str_int);
	return (0);
}
