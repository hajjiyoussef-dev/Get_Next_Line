
//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int fd1 = open("get_next_line.c", O_RDONLY);
	int fd2 = open("get_next_line_bonus.c", O_RDONLY);

	char *line_fd1 = get_next_line(fd1);
	char *line_fd2 = get_next_line(fd2);

	while (line_fd1 || line_fd2)
	{
		if (line_fd1)
		{
			printf("%s", line_fd1);
			free(line_fd1);
			line_fd1 = get_next_line(fd1);
		}
		if (line_fd2)
		{
			printf("%s", line_fd2);
			free(line_fd2);
			line_fd2 = get_next_line(fd2);
		}
	}

	close(fd1);
	close(fd2);

	// return (0);
	// int fd = open("42_with_nl", O_RDONLY);
	// char *str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
}