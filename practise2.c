#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 15

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    printf("%d\n", fd);

    char buf[BUFFER_SIZE];

    if (fd != -1)
    {
        size_t numread
    }
}