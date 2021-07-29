#include "ft_printf.h"

void	ft_processor(t_spec *spec)
{
	int	len;

	len = 0;
	if (spec->spec == 'd' || spec->spec == 'i')
		len = ft_output_int(spec);
	else if (spec->spec == 's')
		len = ft_output_str(spec);
	else if (spec->spec == 'c' || spec->spec == '%')
		len = ft_output_char(spec);
	else if (spec->spec == 'p')
		ft_output_pointer(spec);
	else if (spec->spec == 'x' || spec->spec == 'X')
		len = ft_output_hex(spec);
	else if (spec->spec == 'u')
		len = ft_output_unsigned(spec);
}
