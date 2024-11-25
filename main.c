#include "get_next_line.h" 

#include <fcntl.h> // For open
#include <stdio.h> // For printf
#include <stdlib.h>

void f()
{
    system("leaks a.out");
}
int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    char *line ;
    atexit(f);
   while ((line = get_next_line(fd)))
   {
        printf(" %s", line);
        free(line);
   }
        
    close(fd);
    return (0);
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>

// int main() {
//     int fd = open("notes.txt", O_RDONLY);  // Open a file                        // Small buffer size
//     int bytes_read;

//     while ((bytes_read = read(fd, buffer, 4)) > 0) {  // Read 4 bytes at a time
//         buffer[bytes_read] = '\0';  // Null-terminate the buffer
//         printf("%s", buffer);       // Print the chunk
//     }

//     close(fd);
//     return 0;
// }