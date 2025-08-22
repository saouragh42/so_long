/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:48:57 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/22 02:49:04 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h> 
# include <stdint.h>

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);

void	*ft_calloc_gnl(size_t count, size_t size);

void	ft_bzero_gnl(void *s, size_t n);

char	*ft_strdup_gnl(const char *s1);

size_t	ft_strlen_until(const char *str, char c);

char	*extract_line(char	*static_buffer);

char	*ft_strjoin_free(char *s1, char *s2, int bytes_read);

char	*obtain_remaining(char *static_buffer);

#endif
