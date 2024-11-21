/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 18:28:58 by yhajji            #+#    #+#             */
/*   Updated: 2024-11-20 18:28:58 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_free(char **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
    
}

char  *ft_read_line(int fd, char *res) // put the line in the buffer 
{
    char *buffer;
    char *help;
    int    bytes_read;

    buffer = (char *) malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer) 
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {   
        bytes_read = read(fd, buffer, BUFFER_SIZE)  == -1 ;
        if (bytes_read == -1)
        {
            ft_free(buffer);
            ft_free(&res);
            return (NULL);
        }
        buffer[bytes_read] = '\0'; 
        help = res; // to free the res bu hold th address of it int the tmp ;
        res = ft_strjoin(res, buffer);
        ft_free(&help);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    ft_free(&buffer);
    return(res);
}

char *get_next_line(int fd)
{
    static char *res;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
    {
        free(&res);
        return (NULL);
    }
    res = ft_read_line(fd, res); // read the firest line in the fd 
    if (!res)
        return (NULL);
    line = ft_get_the_line(res);
    res =  ft_get_the_next(res);
    return (line);
}
