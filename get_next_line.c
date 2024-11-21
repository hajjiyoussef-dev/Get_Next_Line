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
char *ft_get_the_next(char *res)
{
    int i;
    int j;
    char *line;

    i = 0;
    j = 0;
    while (res[i] && res[i] != '\n')
        i++;
    if (!res[i])
    {
        ft_free(&res);
        return (NULL);
    }
    line = malloc(((ft_strlen(res) - i) + 1) * sizeof(char));
    i++;
    while (res[i])
        line[j++] = res[i++];
    ft_free(&res);
    return (line);
}
char *ft_get_the_line(char *res)
{
    char *res_line;
    int i;

    i = 0;
    if (!res[i])
        return (NULL);
    while (res[i] && res[i] != '\n')
        i++;
    if (res[i] == '\n')
        res_line = malloc((i + 2) * sizeof(char));
    else
        res_line =  malloc((i + 1) * sizeof(char));
    if (!res_line)
        return (NULL);
    i = 0;
    while (res[i] && res[i] != '\n')
    {
        res_line[i] = res[i];
        i++;
    }
    if (res[i] && res[i] == '\n')
        res_line[i++] = '\n';
    // res_line[i] = '\0';
    return (res_line);
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
            ft_free(&buffer);
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
        ft_free(&res);
        return (NULL);
    }
    res = ft_read_line(fd, res); // read the firest line in the fd 
    if (!res)
        return (NULL);
    line = ft_get_the_line(res);
    res =  ft_get_the_next(res);
    return (line);
}
