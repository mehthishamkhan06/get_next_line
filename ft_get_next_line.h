#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define BUFFER_SIZE 5 
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif