/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:41:37 by xbasabe-          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	set_colition_flag(t_game *g, float x, float y, double angle)
{
	float	px;
	float	py;

	px = x - cos(degree_to_radians(angle)) * 0.0025;
	py = y - sin(degree_to_radians(angle)) * 0.0025;
	if (g->map[(int)px][(int)y] == '1')
	{
		g->r->colition = 0;
		return (1);
	}
	if (g->map[(int)x][(int)py] == '1')
	{
		g->r->colition = 1;
		return (1);
	}
	return (0);
}

float	dda(t_game *g, double angle)
{
	float	ray[2];
	float	distance;

	ray[0] = g->r->p_x;
	ray[1] = g->r->p_y;
	while (colition(g, (int)ray[0], (int)ray[1]) == 0)
		incr_calc(&ray[0], &ray[1], angle);
	set_colition_flag(g, ray[0], ray[1], angle);
	g->r->col_x = ray[0];
	g->r->col_y = ray[1];
	distance = sqrt(powf(ray[0] - g->r->p_x, 2.0)
			+ powf(ray[1] - g->r->p_y, 2.0));
	distance = unfish(distance, angle, g->r->player_angle);
	return (distance);
}

void	incr_calc(float *ray_x, float *ray_y, double ray)
{
	float	ray_cos;
	float	ray_sin;

	ray_cos = cos(degree_to_radians(ray)) * 0.0025;
	ray_sin = sin(degree_to_radians(ray)) * 0.0025;
	*ray_x += ray_cos;
	*ray_y += ray_sin;
}

int	colition(t_game *g, int x, int y)
{
	if (!g->map[x][y])
		return (2);
	if (g->map[x][y] == '1' || g->map[x][y] == ' ')
		return (1);
	else
		return (0);
}
