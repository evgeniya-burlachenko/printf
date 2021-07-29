#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_1;
	unsigned char	*s2_2;

	s1_1 = (unsigned char *)s1;
	s2_2 = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_1++ != *s2_2++)
			return (*(s1_1 - 1) - *(s2_2 - 1));
	}
	return (0);
}
