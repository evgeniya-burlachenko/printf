#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
