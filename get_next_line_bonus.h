/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 17:01:36 by yhajji            #+#    #+#             */
/*   Updated: 2024-11-26 17:01:36 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#ifndef MAX_OPEN
#define MAX_OPEN 10240
#endif

char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strdup(const char *s1);
void    *ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char    *get_next_line(int fd);

#endif