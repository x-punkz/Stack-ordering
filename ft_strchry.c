#include "libft.h"

char	*ft_strchry(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (s[i] == ((unsigned char)c - 49))
			return ((char *)s);
		i++;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
