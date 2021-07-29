#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *)s;
	while (n != 0)
	{
		buf[n - 1] = c;
		n--;
	}
	return (s);
}
