/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:20:18 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (empty(path))
		ft_error("Error\nEmpty path\n");
	if (cub_file(path, 1) == 1)
		fd = -1;
	if (fd <= 0)
		ft_error("Error\nWrong XPM file\n");
	close(fd);
	return (path);
}

int	check_int(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ','
			&& str[i] != ' ' && str[i] != '\t')
			return (1);
		else
			j = 0;
		if (str[i] == ',')
			j += 2;
		if (str[i] == ',' && (str[i - 1] > '0' && str[i - 1] < '9')
			&& (str[i + 1] > '0' && str[i + 1] < '9'))
			k += 1;
		i++;
	}
	if (j == 4 && k == 4)
		j = 0;
	return (j);
}

int	empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	cub_file(char *argv, int mod)
{
	size_t	len;

	len = ft_strlen(argv);
	if (mod == 0)
	{
		if (argv[len - 4] != '.' || argv[len - 3] != 'c'
			|| argv[len - 2] != 'u' || argv[len - 1] != 'b')
			return (1);
	}
	else if (mod == 1)
	{
		if (argv[len - 4] != '.' || argv[len - 3] != 'x'
			|| argv[len - 2] != 'p' || argv[len - 1] != 'm')
			return (1);
	}
	return (0);
}

int	int_verification(char *temp_f, char *temp_c, t_game *g)
{
	int		i;
	char	**tmp;

	i = -1;
	remove_spaces(temp_f);
	tmp = ft_split(temp_f, ',');
	while (++i < 3)
	{
		if (ft_atoi(tmp[i]) > 255)
			return (free_char2(tmp), 1);
		g->rgb_down[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	free(tmp);
	i = -1;
	remove_spaces(temp_c);
	tmp = ft_split(temp_c, ',');
	while (++i < 3)
	{
		if (ft_atoi(tmp[i]) > 255)
			return (free_char2(tmp), 1);
		g->rgb_up[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	return (free(tmp), 0);
}
