char *get_next_line(int fd)
{
    static  char    *str;
    char            *s;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
}