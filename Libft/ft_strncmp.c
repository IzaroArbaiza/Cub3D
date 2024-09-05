/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:27:11 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/21 11:54:11 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;

	i = 0;
	while (i < n && (*(s1 + i) || *(s2 + i)))
	{
		dif = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (dif)
			return (dif);
		i++;
	}
	return (0);
}
