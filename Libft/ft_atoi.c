/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:56:36 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/02/20 12:53:36 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (res * 10) + (str[c] - '0');
		c++;
	}
	return (res * s);
}

/*int	main(void)
{
	int			ret1;
	int			ret2;


	ret1 = atoi("0");
	printf("lib >> %d \n", ret1);
	ret2 = ft_atoi("0");
	printf("ft >> %d \n", ret2);
	printf("================\n");

	ret1 = atoi("299:3");
	printf("lib >> %d \n", ret1);
	ret2 = ft_atoi("299:3");
	printf("ft >> %d \n", ret2);
	printf("================\n");

	ret1 = atoi("-325");
	printf("lib >> %d \n", ret1);
	ret2 = ft_atoi("-325");
	printf("ft >> %d \n", ret2);
	printf("================\n");

	ret1 = atoi("+42");
	printf("lib >> %d \n", ret1);
	ret2 = ft_atoi("+42");
	printf("ft >> %d \n", ret2);
	printf("================\n");

	ret1 = atoi("007");
	printf("lib >> %d \n", ret1);
	ret2 = ft_atoi("007");
	printf("ft >> %d \n", ret2);
	printf("================\n");

	ret1 = atoi("+-22");
	printf("lib >> %d \n", ret1);
	ret2 = ft_atoi("+-22");
	printf("ft >> %d \n", ret2);
	printf("================\n");
}*/
