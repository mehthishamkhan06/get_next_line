# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int main()
{
    int fd;

    fd = open("text.txt", O_RDWR | O_APPEND, 00700);

    printf("fd of file --> %d\n", fd);

    write(1, "HELLO WORLD", 11);
    write(fd, "HELLO WORLD", 11);

    return 0;
}
