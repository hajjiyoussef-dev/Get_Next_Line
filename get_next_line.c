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

void ft_free(char *ptr)
{
    if(ptr)
    {
        free(ptr);
        ptr = NULL;
    }
}

char *get_next_line(int fd)
{

    static char *buffer[BUFFER_SIZE + 1];
    static size_t start_index = 0;
    size_t read_bayts;
    char *line;

    if (fd < 0 || BUFFER_SIZE < 0)
    {
        return (NULL);
    }
    while (1)
    {
        read_bayts = read(fd, buffer, BUFFER_SIZE);
        if (read_bayts <= 0)
        {
            if (line && *line)
                return (line);
            else
                return (NULL);
        }
        buffer[read_bayts] = '\0';
        start_index = 0;
    }
}
