#include "ft_get_next_line.h"

// #define BUFFER_SIZE 15
char *get_next_line(int fd)
{
    char *str;
    size_t numread;
    numread = read(fd, str, BUFFER_SIZE - 1);
    
    str = malloc(sizeof(char) * numread);
    if (!str)
        return(NULL);
    if (fd != -1)
    {
        while (numread > 0)
        {
            str[numread] = '\0';
            numread = read(fd, str, BUFFER_SIZE);
            printf("%s", str);
        }    
    }
}
int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    get_next_line(fd);
}