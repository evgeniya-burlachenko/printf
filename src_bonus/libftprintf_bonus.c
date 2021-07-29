#include "ft_printf_bonus.h"

void	ft_init(t_spec *spec, const char *s)
{
	spec->width = 0;
	spec->prec = -1;
	spec->spec = 0;
	spec->flags = 0;
	spec->str = 0;
	spec->len = 0;
	spec->minus = 0;
	spec->str = (char *)s;
}

void	ft_default(t_spec *spec)
{
	spec->width = 0;
	spec->prec = -1;
	spec->spec = 0;
	spec->flags = 0;
	spec->minus = 0;
}

int	ft_printf(const char *s, ...)
{
	t_spec	*spec;
	int		len_finish;

	spec = malloc(sizeof(t_spec));
	if (!spec)
		return (-1);
	ft_init(spec, s);
	va_start(spec->ap, s);
	while (*spec->str)
	{
		if (*spec->str == '%')
		{
			ft_default(spec);
			spec->str++;
			pars(spec);
			continue ;
		}
		write(1, spec->str, 1);
		spec->str++;
		spec->len++;
	}
	va_end(spec->ap);
	len_finish = spec->len;
	free(spec);
	return (len_finish);
}
