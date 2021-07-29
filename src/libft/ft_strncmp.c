#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_1;
	unsigned char	*s2_2;

	s1_1 = (unsigned char *)s1;
	s2_2 = (unsigned char *)s2;
	while ((*s1_1 || *s2_2) && n--)
	{
		if (*s1_1++ != *s2_2++)
			return (*(s1_1 - 1) - *(s2_2 - 1));
	}
	return (0);
}
