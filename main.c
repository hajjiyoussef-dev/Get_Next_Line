#include "get_next_line.h" 
//#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <stdio.h> 
#include <stdlib.h>

// void f()
// {
//     system("leaks a.out");
// }
// int main(void)
// {
//     int fd;
//     fd =  open("get_next_line.c", O_RDONLY);

//     char *line;
//     atexit(f);
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }

int main(void)
{
    // int fd1 = open("test.txt", O_RDONLY);
    // int fd2 = open("test1.txt", O_RDONLY);

    //   if (fd1 < 0 || fd2 < 0)
    // {
    //     perror("Error opening file");
    //     if (fd1 >= 0) close(fd1);
    //     if (fd2 >= 0) close(fd2);
    //     return (1);
    // }

    // char *line_fd1 = get_next_line(fd1);
    // char *line_fd2 = get_next_line(fd2); 

    // while (line_fd1 || line_fd2)
    // {
    //     if (line_fd1)
    //     {
    //         printf("%s", line_fd1);
    //         free(line_fd1);
    //         line_fd1 = get_next_line(fd1);
    //     }
    //     if (line_fd2)
    //     {
    //         printf("%s", line_fd2);
    //         free(line_fd2);
    //         line_fd2 = get_next_line(fd2);
    //     }
    // }
    
    // close(fd1);
    // close(fd2);

    // return (0);
    int fd = open("42_with_nl", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    free(str);
}