/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:57 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/19 13:41:05 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	str = (char *)malloc(len + 1);
	if (start > ft_strlen(s))
	{
		*str = '\0';
		return (str);
	}
	if (!str)
	{
		return (0);
	}
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
