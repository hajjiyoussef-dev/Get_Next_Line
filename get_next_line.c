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
#include "stdio.h"

static void buffer_shifting(char *buf, int start)
{
    int i;

    i = 0;
    while (buf[start])
    {

        buf[i++] = buf[start++];
    }
    buf[i] = '\0';
}

static int get_line(char *buf, char **line)
{
    ssize_t i;
    int new_line;
    char *help_line;
    char *new_help_line;

    new_line = 0;
    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    if (buf[i] == '\n')
        new_line = 1;
    help_line = ft_calloc((i + new_line + 1), sizeof(char));
    if (!help_line)
        return (-1);
    ft_memcpy(help_line, buf, (i + new_line));
    new_help_line = ft_strjoin(*line, help_line);
    free(help_line);
    if (!new_help_line)
        return (free(*line), -1);
    free(*line);
    *line = new_help_line;
    buffer_shifting(buf, (i + new_line));
    return (new_line);
}
int fill_buffer(int fd, char *buffer, char *line)
{
    int bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0)
    {
        free(buffer);
        if (*line)  
            free(line);
        line = NULL;
        return (-1);
    }
    else if (bytes_read == 0)
    {
        buffer[0] = '\0';
        if (line && *line != '\0')
            return (-2);
        return (-1);
    }
        buffer[bytes_read] = '\0';
    return (bytes_read);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    
    char *line;
    int result;
    int line_finde;

    line_finde = 0;
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (buffer[0] = '\0', NULL);
    while (1)
    {
        if (buffer[0] == '\0')
        {
            result = fill_buffer(fd, buffer, line);
            if (result == -1)
                return (NULL);
            else if (result == -2)
                return (line);
        }
        line_finde = get_line(buffer, &line);
        if (line_finde == -1)
        {
            free(buffer);
            return (free(line), NULL);
        }
        if (line_finde)
            return (line);
    }
}
