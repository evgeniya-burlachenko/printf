#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	if ((char)c == 0)
		return (str + i);
	while (i--)
	{
		if (s[i] == (char)c)
			return (str + i);
	}
	return (NULL);
}
