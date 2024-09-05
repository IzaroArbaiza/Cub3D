/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:37:17 by xbasabe-          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_wall(int c_x, int c_y, t_game *g)
{
	int	s_x;
	int	s_y;

	s_x = c_x * 8;
	s_y = c_y * 8;
	render_rect(g, s_x, s_y, 0xF7DC6F);
}

void	sprite_floor(int c_x, int c_y, t_game *g)
{
	int	s_x;
	int	s_y;

	s_x = c_x * 8;
	s_y = c_y * 8;
	render_rect(g, s_x, s_y, 0xFBFCFC);
}

void	sprite_to_map(t_game *g)
{
	int	c_x;
	int	c_y;

	c_x = 0;
	c_y = 0;
	player_cell(g);
	while (g->map[c_y])
	{
		while (g->map[c_y][c_x])
		{
			if (g->map[c_y][c_x] == '1')
				sprite_wall(c_x, c_y, g);
			if (g->map[c_y][c_x] == '0')
				sprite_floor(c_x, c_y, g);
			c_x++;
		}
		c_y++;
		c_x = 0;
	}
}

void	player_cell(t_game *g)
{
	int	c_x;
	int	c_y;

	c_x = 0;
	c_y = 0;
	while (g->map[c_y])
	{
		while (g->map[c_y][c_x])
		{
			if (g->map[c_y][c_x] == 'N' || g->map[c_y][c_x] == 'E'
				|| g->map[c_y][c_x] == 'W' || g->map[c_y][c_x] == 'S'
				|| g->map[c_y][c_x] == 'P')
				g->map[c_y][c_x] = '0';
			c_x++;
		}
		c_y++;
		c_x = 0;
	}
	g->map[(int)(g->r->p_x)][(int)(g->r->p_y)] = 'P';
}

void	render_rect(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;
	int	c_x;
	int	c_y;

	i = 0;
	c_x = x;
	c_y = y;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			mlx_pixel_put(g->mlx, g->mlx_win, c_x, c_y, color);
			j++;
			c_x++;
		}
		c_x -= 8;
		c_y++;
		++i;
	}
}
