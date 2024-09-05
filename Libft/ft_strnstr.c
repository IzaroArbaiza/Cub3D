/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:55:07 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/14 11:31:13 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	while (++i < len && *(haystack + i))
	{
		j = -1;
		while ((i + ++j) < len && *(haystack + i + j) == *(needle + j))
			if (!*(needle + j + 1))
				return ((char *)(haystack + i));
	}
	return (NULL);
}
