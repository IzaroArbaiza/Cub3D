/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:42:14 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/02/29 16:30:48 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1000

# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_read(int fd, char *str);
char	*get_the_line(char *str);
char	*get_str(char *str);

size_t	ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *str, int i);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
