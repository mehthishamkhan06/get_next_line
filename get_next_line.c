/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:54:43 by mohkhan           #+#    #+#             */
/*   Updated: 2024/07/21 10:54:47 by mohkhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *str)
{
	char	*res;
	int		bytes_read;

	bytes_read = 1;
	res = (char *)malloc(BUFFER_SIZE + 1);
	if (!res)
		return (free(str), NULL);
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, res, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(res), free(str), NULL);
		res[bytes_read] = '\0';
		str = ft_strjoin(str, res);
		if (!str)
			return (free(res), NULL);
	}
	if (str && str[0] == '\0')
		return (free(str), free(res), NULL);
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
		return (free(str), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n' && ++i)
		res[i - 1] = str[i - 1];
	res[i] = '\0';
	return (res);
}

char	*next_line(char *str)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	res = (char *)malloc(ft_strlen(str) - i + 1);
	if (!res)
		return (free(str), NULL);
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

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	str = reader(fd, str);
	if (!str)
		return (NULL);
	res = present_line(str);
	if (!res)
		str = NULL;
	str = next_line(str);
	return (res);
}
