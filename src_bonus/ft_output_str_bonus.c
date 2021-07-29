#include "ft_printf_bonus.h"

static char	*str_init(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == 0)
		str = "(null)";
	return (str);
}

static int	ft_prec_digit_str(t_spec *spec, int len, char *str)
{
	if (spec->width > len)
	{
		if (spec->flags == '-')
		{	
			ft_putstr(str, len);
			ft_putcharstr(' ', spec->width - len);
			spec->len += spec->width - len;
		}
		else if (spec->flags == '0')
		{
			ft_putcharstr('0', spec->width - len);
			ft_putstr(str, len);
			spec->len += spec->width - len;
		}
		else
		{
			ft_putcharstr(' ', spec->width - len);
			ft_putstr(str, len);
			spec->len += spec->width - len;
		}
	}
	else
		ft_putstr(str, len);
	spec->len += len;
	return (0);
}

int	ft_output_str(t_spec *spec)
{
	char	*str;
	int		len;

	str = str_init(spec->ap);
	len = ft_precision(spec->prec, str);
	ft_prec_digit_str(spec, len, str);
	return (0);
}
