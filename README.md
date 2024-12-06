# get_next_line
**42 Network Project**
A function to read a line from a file descriptor.

## Introduction
`get_next_line` is part of the 42 curriculum. It focuses on creating a function that reads one line at a time from a file descriptor, handling various edge cases and different buffer sizes.

## Features
. Reads one line at a time.
. Works with files, stdin, and pipes.
. Supports multiple file descriptors (bonus).

## Function Prototype
```c

char *get_next_line(int fd);
```


## Example Code
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return 1;

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
## Testing
**Compile and Run**
 1. Compile a test file with:
```c
gcc -Wall -Wextra -Werror -o test test.c get_next_line.c get_next_line_utils.c
./test
```
2. Test with various files:
. Empty files
. Files with long lines
. Files with multiple lines
. Stdin input
## Bonus Features
. Support for multiple file descriptors.
. Edge case handling for buffer sizes.
. Compile the bonus version with:
```c
gcc -Wall -Wextra -Werror -o test test.c get_next_line_bonus.c get_next_line_utils_bonus.c
./test
```
## Project Structure
```c
get_next_line/
├── get_next_line.c
├── get_next_line.h
├── get_next_line_utils.c
└── README.md
```
Author
[yhajji] - 42 Network Student

