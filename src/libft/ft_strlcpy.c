#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}
