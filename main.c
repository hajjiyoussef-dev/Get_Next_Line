#include "get_next_line.h" 

#include <fcntl.h>
#include <stdio.h> 
#include <stdlib.h>

void f()
{
    system("leaks a.out");
}
int main(void)
{
    int fd;
    fd =  open("get_next_line.c", O_RDONLY);

    char *line;
    atexit(f);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}