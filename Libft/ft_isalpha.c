/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:35:31 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/09/09 16:32:04 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	int ret1;
	int ret2;

	ret1 = isalpha(32);
	printf("lib >> %d \n", ret1);
	ret2 = ft_isalpha(32);
	printf("ft >> %d \n", ret2);

	printf("================\n");

	ret1 = isalpha(65);
	printf("lib >> %d \n", ret1);
	ret2 = ft_isalpha(65);
	printf("ft >> %d \n", ret2);

	printf("================\n");

	ret1 = isalpha(97);
	printf("lib >> %d \n", ret1);
	ret2 = ft_isalpha(97);
	printf("ft >> %d \n", ret2);

	printf("================\n");

	return (0);
}*/
