/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:46:16 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/13 12:25:47 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = 0;
		i++;
	}
}

/*int     main(void)
{
	char str1[] = "Hey marvin!!";
	char str2[] = "Hey marvin!!";
	char str3[] = "Hey marvin!!";
	char str4[] = "Hey marvin!!";

	bzero(str1, 4);
	printf("str1 >> %s \n", str1);
	ft_bzero(str2, 4);
	printf("str2 >> %s \n", str2);

	printf("================\n");

	bzero(str3, 0);
	printf("str3 >> %s \n", str3);
	ft_bzero(str4, 0);
	printf("str4 >> %s \n", str4);

	return (0);
}*/
