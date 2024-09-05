/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:45:51 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../GNL/get_next_line.h"

int	line_verify(t_game *g, char *l, int i)
{
	char	*aux;

	if (l[i] == 'N' && l[i + 1] == 'O' && l[i + 2] == ' ')
		return (g->no = check_path(ft_strtrim(l + 3, " \n")), free(l), 0);
	else if (l[i] == 'S' && l[i + 1] == 'O' && l[i + 2] == ' ')
		return (g->so = check_path(ft_strtrim(l + 3, " \n")), free(l), 0);
	else if (l[i] == 'W' && l[i + 1] == 'E' && l[i + 2] == ' ')
		return (g->we = check_path(ft_strtrim(l + 3, " \n")), free(l), 0);
	else if (l[i] == 'E' && l[i + 1] == 'A' && l[i + 2] == ' ')
		return (g->ea = check_path(ft_strtrim(l + 3, " \n")), free(l), 0);
	else if (l[i] == 'F' && l[i + 1] == ' ')
	{
		aux = ft_strtrim(l + 2, " \n");
		if (check_int(aux) == 0)
			return (free(aux), g->t_f = ft_strtrim(l + 2, " \n"), free(l), 0);
		free(aux);
	}
	else if (l[i] == 'C' && l[i + 1] == ' ')
	{
		aux = ft_strtrim(l + 2, " \n");
		if (check_int(aux) == 0)
			return (free(aux), g->t_c = ft_strtrim(l + 2, " \n"), free(l), 0);
		free(aux);
	}
	return (free(l), 1);
}

int	verification(char *line, t_game *g, int count)
{
	char	*aux;

	aux = ft_strtrim(line, " ");
	if (aux[0] && count < 6)
		return (line_verify(g, aux, 0));
	free(aux);
	if (!g->no || !g->no || !g->we || !g->ea)
		ft_error("Error\nLack of arguments\n");
	if (g->t_f && g->t_c)
		if (int_verification(g->t_f, g->t_c, g) == 1)
			return (1);
	return (0);
}

void	read_map_extended(char **str, char **line, t_game *game, int *count)
{
	int		i;
	char	*aux;

	i = verification(*line, game, *count);
	if (!empty(*line) && *count >= 6 && i == 0)
	{
		aux = ft_strjoin(*str, *line);
		free(*str);
		*str = ft_strdup(aux);
		free(aux);
	}
	if (!empty(*line) && i == 0)
		(*count)++;
	if (!empty(*line) && i == 1)
		ft_error("Error\nInvalid arguments\n");
}

void	read_map(int fd, t_game *game)
{
	int		count;
	char	*line;
	char	*str;

	count = 0;
	line = get_next_line(fd);
	str = ft_strdup("");
	while (line)
	{
		read_map_extended(&str, &line, game, &count);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(str, '\n');
	game->map_cop = ft_split(str, '\n');
	free(line);
	free(str);
}

void	map_parse(char *argv, t_game *game, t_ray *ray)
{
	int		fd;

	cub_file(argv, 0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nCan't open the file\n");
	else if (fd <= 0)
		ft_error("Error\nMap file Wrong!!\n");
	read_map(fd, game);
	map_args(game, ray);
}
