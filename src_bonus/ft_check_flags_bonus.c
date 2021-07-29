#include "ft_printf_bonus.h"

int	ft_prec_digit(t_spec *spec, int len, char *str_int)
{
	if (spec->prec == 0 && str_int[0] == '0')
	{
		ft_putcharstr(' ', spec->width);
		spec->len += spec->width;
		free(str_int);
		return (0);
	}
	if (spec->flags == '-')
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
	 else
		ft_minus(spec, len, str_int);
	spec->len += len;
	free(str_int);
	return (0);
}

int	ft_precision(int prec, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (prec < len && prec >= 0)
	{
		len = prec;
	}
	return (len);
}

void	ft_space_digit_minus(t_spec *spec, int len, char *str_int)
{
	if (spec->width > len && spec->width > spec->prec)
	{	
		if (spec->prec > len)
		{
			ft_putstr(str_int, len);
			ft_putcharstr(' ', spec->width - spec->prec - spec->minus);
			spec->len += spec->width - spec->prec - spec->minus;
		}
		else
		{
			ft_putstr(str_int, len);
			ft_putcharstr(' ', spec->width - len);
			spec->len += spec->width - len;
		}
	}
	else
		ft_putstr(str_int, len);
}

void	ft_space_digit(t_spec *spec, int len)
{
	if (spec->width > len && spec->width > spec->prec)
	{	
		if (spec->prec > len)
		{
			if (spec->flags == '0' && spec->prec < 0)
				ft_putcharstr('0', spec->width - spec->prec - spec->minus);
			else
				ft_putcharstr(' ', spec->width - spec->prec - spec->minus);
			spec->len += spec->width - spec->prec - spec->minus;
		}
		else
		{
			if (spec->flags == '0' && spec->prec < 0)
			{
				ft_putcharstr('0', spec->width - len -spec->minus);
				spec->len += spec->width - len -spec->minus;
			}	
			else
			{	
				ft_putcharstr(' ', spec->width - len);
				spec->len += spec->width - len;
			}
		}
	}
}

void	ft_minus(t_spec *spec, int len, char *str_int)
{
	if (spec->flags =='0' && spec->prec < 0 && spec->minus)
	{
		ft_putcharstr('-', 1);
	}
	ft_space_digit(spec, len);
	if (spec->prec > len)
	{
		if (spec->minus)
			ft_putcharstr('-', 1);
		ft_putcharstr('0', spec->prec - len);
		spec->len += spec->prec - len;
	}
	ft_putstr(str_int, len);
}
