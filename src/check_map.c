/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:07:47 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player_angle(t_game *g, char c)
{
	if (c == 'N')
		g->r->player_angle = 180;
	else if (c == 'S')
		g->r->player_angle = 0;
	else if (c == 'W')
		g->r->player_angle = 270.0;
	else if (c == 'E')
		g->r->player_angle = 90;
}

void	fill_map(char **map, int x, int y)
{
	if (y == -1 || x == -1 || !map[x]
		|| y >= ft_strlen_int(map[x]) || map[x][y] == ' ')
		ft_error("Error\nInvalid Map\n");
	if (map[x][y] == '1')
		return ;
	map[x][y] = '1';
	fill_map(map, x + 1, y);
	fill_map(map, x - 1, y);
	fill_map(map, x, y + 1);
	fill_map(map, x, y - 1);
}

int	check_line(t_game *game, char *next, char *pre, int x)
{
	int		y;
	int		count;
	char	*m;

	y = -1;
	count = 0;
	m = game->map[x];
	while (m && m[++y])
	{
		if (m[y] == 'N' || m[y] == 'S' || m[y] == 'E' || m[y] == 'W')
		{
			fill_map(game->map_cop, x, y);
			count++;
		}
		if (m[y] != '1' && m[y] != ' ' && (y == 0 || m[y + 1] == '\0'
				|| !next || !pre || y >= ft_strlen_int(next)
				|| y >= ft_strlen_int(pre)
				|| (y < ft_strlen_int(next)
					&& (next[y] == ' ' || next[y] == '\t'))
				|| (y < ft_strlen_int(pre) && (pre[y] == ' ' || pre[y] == '\t'))
				|| (!is_valid_char(m[y], "NSEW10 "))))
			ft_error("Error\nInvalid Map\n");
	}
	return (count);
}

int	get_player(t_game *game, t_ray *ray)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x++])
	{
		y = 0;
		while (game->map[x][y++])
		{
			if (is_valid_char(game->map[x][y], "NSEW") == 1)
			{
				game->r->p_x = x + 0.5;
				game->r->p_y = y + 0.5;
				get_player_angle(game, game->map[x][y]);
				return (0);
			}
		}
	}
	if (ray->p_x == 0 || ray->p_y == 0)
		return (ft_error("Error\nInvalid Map Wrong Values\n"), 1);
	return (0);
}

void	map_args(t_game *game, t_ray *ray)
{
	int		count;
	char	*next;
	char	*pre;
	int		x;

	x = -1;
	count = 0;
	while (game->map && game->map[++x])
	{
		if (x == 0)
			pre = NULL;
		else
			pre = game->map[x - 1];
		next = game->map[x + 1];
		count += check_line(game, next, pre, x);
	}
	if (count != 1 || x < 3)
		ft_error("Error\nInvalid Map Missing Value\n");
	get_player(game, ray);
}
