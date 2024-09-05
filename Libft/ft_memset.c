/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:37:06 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/14 13:50:18 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len > 0)
	{
		*s = c;
		s++;
		len--;
	}
	return (b);
}

/*int     main(void)
{
	char str1[] = "Hey marvin!!";
	char str2[] = "Hey marvin!!";

	memset(str1, 64, 3);
	printf("str1 >> %s \n", str1);
	ft_memset(str2, 64, 3);
	printf("str2 >> %s \n", str2);

	printf("================\n");

	memset(str1, -4, 3);
	printf("str1 >> %s \n", str1);
	ft_memset(str2, -4, 3);
	printf("str2 >> %s \n", str2);

	printf("================\n");

	memset(str1, 129, 3);
	printf("str1 >> %s \n", str1);
	ft_memset(str2, 129, 3);
	printf("str2 >> %s \n", str2);

	return (0);
}*/
