#include "ft_get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if ((char)c == '\0')
		return (str + ft_strlen(s));
	while (s[i] && (char)c != s[i])
		i++;
	if ((char)c == s[i])
		return (str + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i])
		res[i++] = s1[i++];
	while (s2[j])
		res[i++] = s2[j++];
	res[i++] = '\0';
	return (res);
}