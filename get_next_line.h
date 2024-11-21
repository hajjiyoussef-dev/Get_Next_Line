/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 14:20:06 by yhajji            #+#    #+#             */
/*   Updated: 2024-11-20 14:20:06 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
#define GET_NEXT_LINE_H 

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10 
#endif 

char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char    *get_next_line(int fd);
char    *ft_get_the_next(char *res);
char    *ft_read_line(int fd, char *res);
char    *ft_get_the_line(char *res);


#endif