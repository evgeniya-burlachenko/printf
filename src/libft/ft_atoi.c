#include "libft.h"

int	ft_atoi(const char *str)
{
	long int		num;
	int				sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}	
	while (ft_isdigit(*str))
	{
		num = num * 10 + (int)*str - '0';
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		str++;
	}
	return (num * sign);
}
