/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 14:16:18 by yhajji            #+#    #+#             */
/*   Updated: 2024-11-22 14:16:18 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strdup(const char *s1);
void *ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char *get_next_line(int fd);


#endif