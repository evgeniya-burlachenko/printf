#include "ft_printf.h"

void	ft_putstr(char const *s, int num)
{
	if (!s || num < 0 )
		return ;
	 write(1, s, num);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putcharstr(char c, int num)
{
	int	i;

	if (num < 0)
		return (0);
	i = num;
	while (num--)
		write(1, &c, 1);
	return (i);
}

int	ft_sizelen_hex_pointer(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_sizelen_pointer(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
