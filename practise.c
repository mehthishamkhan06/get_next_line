#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 15
int main(int argc, char *argv[])
{
    int fd = open(argv[1],O_RDONLY);
    printf("%d\n", fd);
    char buf[BUFFER_SIZE];

    if (fd != -1)
    {
        ssize_t numRead = read(fd, buf, BUFFER_SIZE - 1);
        while (numRead > 0)
        {
            buf[numRead] = '\0';
            printf("%s\n", buf);
            numRead = read(fd, buf, BUFFER_SIZE - 1);
        }
    }
    else
    {
        printf("ERROR\n");
    }
}