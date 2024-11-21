#include "get_next_line.h" 

#include <fcntl.h> // For open
#include <stdio.h> // For printf
#include <stdlib.h>

int main(void)
{
    int fd = open("get_next_line.h", O_RDONLY);

    char *line ;

     while ((line = get_next_line(fd)))
    {
        printf("Line: %s", line); 
        free(line);              
    }

    close(fd); // Close the file
    return (0);
}