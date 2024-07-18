# define BUFFER_SIZE 5 
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

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
    {
		res[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
		res[i] = s2[j];
        i++;
        j++;
    }
	res[i++] = '\0';
	return (res);
}
char	*ft_free(char *str, char *s)
{
	free(s);
	free(str);
	return (NULL);
}

char	*ft_readline(int fd, char *s, size_t buff)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(buff + 1);
	if (!str)
		return (NULL);
	while (i != 0 && !ft_strchr(s, '\n'))
	{
		i = read(fd, str, buff);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		s = ft_strjoin(s, str);
	}
	if (s[0] == '\0')
	{
		ft_free(str, s);
		return (NULL);
	}
	free (str);
	return (s);
}

char	*ft_currentline(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_newline(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_readline(fd, str, BUFFER_SIZE);
	if (!str)
		return (NULL);
	s = ft_currentline(str);
	str = ft_newline(str);
	return (s);
}

int main()
{
    int fd;

    printf("hello");
    fd = open("text.txt", O_RDWR | O_APPEND, 00700);
    
    char *line = get_next_line(fd);
    printf("%s\n", line);
    free (line);
}

// int main()
// {
//     int fd;

//     printf("hello");
//     fd = open("text.txt", O_RDWR | O_APPEND, 00700);
//     printf("%s\n", get_next_line(fd));
//     // printf("fd of file --> %d\n", fd);

//     write(1, "HELLO WORLD", 11);
//     write(fd, "HELLO WORLD", 11);
// }