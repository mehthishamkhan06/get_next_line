#include "get_next_line.h"
#include <limits.h>

char	*reader(int fd, char *str, size_t buffer)
{
	char	*res;
	int		bytes_read;

	bytes_read = 1;
	res = (char *)malloc(buffer + 1);
	if (!res)
		return (0);
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, res, buffer);
		if (bytes_read == -1)
			return (free(res), NULL);
		res[bytes_read] = '\0';
		str = ft_strjoin(str, res);
	}
	if(str[0] == '\0')
		return(free(str), free(res), NULL);
	free(res);
	return (str);
}

char	*present_line(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i] = str[i];
	res[++i] = '\0';
	return (res);
}

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	res = (char *)malloc(ft_strlen(str) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	str = reader(fd, str, BUFFER_SIZE);
	if (!str)
		return (NULL);
	res = present_line(str);
	str = next_line(str);
	return (res);
}

int main()
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	printf("%d\n", fd);
	if (fd == -1)
		printf("ERROR");

	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
}
