/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:33:46 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/19 12:24:19 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	size_t			i;

	ptr_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(ptr_s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
int     main(void)
{
	const char str[] = "Hey marvin!!";
	char *ret1;
	char *ret2;

	ret1 = memchr(str, 109, 10);
	printf("str_lib >> %s \n", ret1);
	ret2 = ft_memchr(str, 109, 10);
	printf("str_ft >> %s \n", ret2);

	printf("================\n");

	ret1 = memchr(str, 109, 3);
	printf("str_lib >> %s \n", ret1);
	ret2 = ft_memchr(str, 109, 3);
	printf("str_ft >> %s \n", ret2);

	printf("================\n");

	ret1 = memchr(str, 75, 10);
	printf("str_lib >> %s \n", ret1);
	ret2 = ft_memchr(str, 75, 10);
	printf("str_ft >> %s \n", ret2);

	return (0);
}*/
