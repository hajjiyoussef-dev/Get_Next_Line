//#include  "get_next_line.h"
#include  "get_next_line_bonus.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>




int main(void)
{
    int fd =  open("get_next_line.c" , O_RDONLY);
    int fd2 =  open("get_next_line_bonus.c" , O_RDONLY);

    char *linefd = get_next_line(fd);
    char *linefd2 = get_next_line(fd2);


    while (linefd || linefd2 )
    {
        if (linefd)
        {
            printf("%s", linefd);
            free(linefd);
            linefd = get_next_line(fd);
        }
        if (linefd2)
        {
            printf("%s", linefd2);
            free(linefd2);
            linefd2 = get_next_line(fd2);
        }
    }
    return (0) ; 
}

// int main(void)
// {
//     int fd = open("get_next_line.c" , O_RDONLY);

//     char *line;
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s" , line);
//         free(line);
//     }

//     return (0);
    
// }