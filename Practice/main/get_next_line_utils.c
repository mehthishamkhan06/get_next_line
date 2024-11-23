#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s1, int c)
{
	char	*str;

	if (!s1)
		return (0);
	str = (char *)s1;
	while (*str != (unsigned char) c)
	{
		if (!*str)
			return (0);
		str++;
	}	
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[i] = '\0';
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free (s1);
	return (res);
}
// int	main(void)
// {
// 	char	str[20] = "HELLO";
// 	char	c;

// 	c = 'E';
// 	printf("%s\n", ft_strchr(str, c));
// }

