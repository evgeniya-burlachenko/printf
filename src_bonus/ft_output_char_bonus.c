#include "ft_printf_bonus.h"

void	ft_width_flags(t_spec *spec, char c)
{
	if (spec->width > 1)
	{
		if (spec->flags == '-')
		{
			ft_putchar(c);
			ft_putcharstr(' ', spec->width - 1);
			spec->len += spec->width - 1;
		}
		else if (spec->flags == '0')
		{
			ft_putcharstr('0', spec->width - 1);
			ft_putchar(c);
			spec->len += spec->width - 1;
		}
		else if (spec->flags != '-')
		{
			ft_putcharstr(' ', spec->width - 1);
			ft_putchar(c);
			spec->len += spec->width - 1;
		}
	}
	else
		ft_putchar(c);
	spec->len += 1;
}

int	ft_output_char(t_spec *spec)
{
	char	c;

	if (spec->spec == '%' || spec->spec == ' ')
		c = spec->spec;
	else
		c = (char)va_arg(spec->ap, int);
	ft_width_flags(spec, c);
	return (0);
}
