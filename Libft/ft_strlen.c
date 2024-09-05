/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:47:13 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/13 10:27:47 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != 0)
		c++;
	return (c);
}

/*int	main()
{
	const char str1[] = "Hey marvin!!";
	const char str2[] = "";
	int ret1;
	int ret2;

	ret1 = strlen(str1);
	printf("str_lib >> %d \n", ret1);
	ret2 = ft_strlen(str1);
	printf("str_ft >> %d \n", ret2);

	printf("================\n");

	ret1 = strlen(str2);
	printf("str_lib >> %d \n", ret1);
	ret2 = ft_strlen(str2);
	printf("str_ft >> %d \n", ret2);

	return (0);
}*/
