#include "ft_printf.h"

static void	parse_width(t_spec *spec)
{
	if (ft_isdigit((int)*spec->str) || *spec->str == '*')
	{
		while (ft_isdigit((int)*spec->str))
			spec->width = (int)spec->width * 10 + *spec->str++ - '0';
		if (*spec->str == '*')
		{
			spec->width = va_arg(spec->ap, int);
			if (spec->width < 0)
			{
				spec->flags = '-';
				spec->width *= -1;
			}
			spec->str++;
		}
	}	
}

static void	parse_prec(t_spec *spec)
{
	if (*spec->str == '.')
	{
		spec->str++;
		spec->prec = 0;
		while (ft_isdigit((int)*spec->str))
			spec->prec = (int)spec->prec * 10 + *spec->str++ - '0';
		if (*spec->str == '*')
		{
			spec->prec = va_arg(spec->ap, int);
			spec->str++;
		}
	}
}

static char	*ft_spec(t_spec *spec)
{
	if (ft_strrchr(LIST_SPEC, *spec->str))
	{
		spec->spec = *spec->str;
		ft_processor(spec);
		if (*spec->str)
			spec->str++;
	}
	else
		spec->spec = ' ';
	return (spec->str);
}

char	*pars(t_spec *spec)
{
	while (!(ft_strrchr(LIST_SPEC, *spec->str)) && (*spec->str != '\0'))
	{
		while (*spec->str == '-' || *spec->str == '0')
		{
			if (spec->flags == '-')
			{
				spec->str++;
				break ;
			}
			if (*spec->str == '-' || *spec->str == '0')
				spec->flags = *spec->str++;
		}
		parse_width(spec);
		parse_prec(spec);
		if (!(ft_strrchr(LIST_SPEC, *spec->str)))
			spec->str++;
	}
	ft_spec(spec);
	 return (spec->str);
}
