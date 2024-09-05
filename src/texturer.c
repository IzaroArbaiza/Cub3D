/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:45:54 by xbasabe-          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_tex_pix(t_img *tex, int tex_x, int tex_y)
{
	char	*tex_pix;

	tex_pix = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(int *)tex_pix);
}

void	tex_pix_put(t_game *g, int x, int y, int tex_pix)
{
	void	*pixel;

	pixel = g->render->addr + \
		(y * g->render->line_len + x * (g->render->bpp / 8));
	*(unsigned int *)pixel = tex_pix;
}

int	draw_texture(t_game *g, int wall_x, float *wall, t_img *tex)
{
	double	wall_y;
	double	tex_x;
	double	tex_y;
	double	step;
	double	tex_pos;

	wall_y = wall[0];
	tex_x = g->r->col_x;
	tex_x = (tex_x - floor(g->r->col_x)) * 64;
	if (g->r->colition == 1)
	{
		tex_x = g->r->col_y;
		tex_x = (tex_x - floor(g->r->col_y)) * 64;
	}
	step = 64.0 / (wall[1] - wall[0]);
	tex_pos = 64;
	while (wall_y-- > wall[1])
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		if (wall_y >= 0 && wall_y < HIGHT)
			tex_pix_put(g, wall_x, wall_y, get_tex_pix(tex, \
				(int)tex_x, (int)tex_y));
	}
	return (0);
}
