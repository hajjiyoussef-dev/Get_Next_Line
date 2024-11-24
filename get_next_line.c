/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 14:16:22 by yhajji            #+#    #+#             */
/*   Updated: 2024-11-22 14:16:22 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void buffer_shifting(char *buf, int start)
{
    int i;

    i = 0;
    while (buf[start])
        buf[i++] = buf[start++];
    buf[i] = '\0';
}

 static int get_line(char *buf, char **line)
{
    ssize_t i;
    int new_line ;
    char *help_line;

    new_line = 0;
    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    if (buf[i] == '\0')
        new_line = 1;
    help_line = ft_calloc((i + new_line + 1), sizeof(char));
    if (!help_line)
        return (-1);
    ft_memcpy(help_line, buf, (i + new_line));
    *line = ft_strjoin(*line, help_line);
    free(help_line);
    if (!*line)
        return (-1);
    buffer_shifting(buf, (i + new_line));
    return (new_line);
}

char *get_next_line(int fd)
{ 
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    int bytes_read;
    int line_finde;

    line_finde = 0;
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    while (1)
    {
        line_finde = get_line(buffer, &line);
        if (line_finde == -1)
            return (free(line), free(buffer), NULL);
        if (!line_finde)
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
            {
                if (line && *line != '\0')
                    line_finde = 1;
                else
                    return (free(line), NULL);
            }
            buffer[bytes_read] = '\0';
        }
    }
}
