#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define BUFFER_SIZE 5 
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char *get_next_line(int fd);
sizet_t ft_strlen(const char *str);
char    *strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif