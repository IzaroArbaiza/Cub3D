/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:21:14 by xbasabe-          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	unfish(float distance, float angle, double player_angle)
{
	float	beta;

	beta = player_angle - angle;
	if (beta >= 360)
		beta -= 360;
	else if (beta < 0)
		beta += 360;
	beta = degree_to_radians(beta);
	return (distance * cos(beta));
}

int	floor_wall_roof_proportion(float distance, float *wall, int flag)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HIGHT / distance);
	draw_start = HIGHT / 2 - line_height / 2;
	if (draw_start < 0 && flag == 0)
		draw_start = 0;
	draw_end = HIGHT / 2 + line_height / 2;
	if (draw_end >= HIGHT && flag == 0)
		draw_end = HIGHT;
	wall[1] = draw_start;
	wall[0] = draw_end;
	return (line_height);
}

int	draw_vert_line(t_game *g, int x, float *limit, int color)
{
	double	delta_y;
	int		pixels;
	double	pixel_y;

	delta_y = limit[1] - limit[0];
	pixels = sqrt((delta_y * delta_y) + (delta_y * delta_y));
	delta_y /= pixels;
	pixel_y = limit[0];
	while (pixels)
	{
		img_pix_put(g, x, pixel_y, color);
		pixel_y += delta_y;
		--pixels;
	}
	return (0);
}

void	img_pix_put(t_game *g, int x, int y, int color)
{
	char	*pixel;

	pixel = g->render->addr + (y * g->render->line_len
			+ x * (g->render->bpp / 8));
	*(int *)pixel = color;
}

void	init_image(t_game *g)
{
	g->render = ft_calloc(sizeof(t_img), 1);
	g->render->img_ptr = mlx_new_image(g->mlx, WIDTH, HIGHT);
	g->render->addr = mlx_get_data_addr(g->render->img_ptr, &(g->render->bpp),
			&(g->render->line_len), &(g->render->endian));
}
