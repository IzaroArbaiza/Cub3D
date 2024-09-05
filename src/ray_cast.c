/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:08:48 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

unsigned long	rgb_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	raycast(t_game *g)
{
	double	ray;
	double	end_ray;

	ray = correct_cast_angle(g);
	end_ray = ray + FOV;
	end_ray = nor_angle(end_ray);
	cast(g, ray);
	mlx_clear_window(g->mlx, g->mlx_win);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->render->img_ptr, 0, 0);
}

double	correct_cast_angle(t_game *g)
{
	double	look;

	look = g->r->player_angle;
	look -= FOV / 2;
	look = nor_angle(look);
	return (look);
}

float	cast(t_game *g, double ray)
{
	int		i;
	float	distance;
	float	wall[2];
	float	limit[2];

	i = 0;
	while (++i <= WIDTH)
	{
		distance = dda(g, ray);
		floor_wall_roof_proportion(distance, wall, 0);
		limit[0] = 0;
		limit[1] = wall[1];
		draw_vert_line(g, WIDTH - i, limit, rgb_hex(g->rgb_up[0], \
			g->rgb_up[1], g->rgb_up[2]));
		limit[0] = wall[0];
		limit[1] = HIGHT;
		draw_vert_line(g, WIDTH - i, limit, rgb_hex(g->rgb_down[0], \
			g->rgb_down[1], g->rgb_down[2]));
		floor_wall_roof_proportion(distance, wall, 1);
		draw_texture(g, WIDTH - i, wall, get_texture(ray, g->r->colition, g));
		ray += 0.03846;
		ray = nor_angle(ray);
	}
	return (distance);
}
