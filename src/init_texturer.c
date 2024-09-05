/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texturer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:45:54 by xbasabe-          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_north(t_game *g)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	g->tex_n = ft_calloc(sizeof(t_img), 1);
	g->tex_n->height = HIGHT;
	g->tex_n->width = WIDTH;
	g->tex_n->img_ptr = mlx_new_image(g->mlx, WIDTH, HIGHT);
	g->tex_n->img_ptr = mlx_xpm_file_to_image(g->mlx, g->no, &x, &y);
	g->tex_n->addr = mlx_get_data_addr(g->tex_n->img_ptr, &(g->tex_n->bpp), \
		&(g->tex_n->line_len), &(g->tex_n->endian));
}

void	open_east(t_game *g)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	g->tex_e = ft_calloc(sizeof(t_img), 1);
	g->tex_e->height = HIGHT;
	g->tex_e->width = WIDTH;
	g->tex_e->img_ptr = mlx_new_image(g->mlx, WIDTH, HIGHT);
	g->tex_e->img_ptr = mlx_xpm_file_to_image(g->mlx, g->ea, &x, &y);
	g->tex_e->addr = mlx_get_data_addr(g->tex_e->img_ptr, &(g->tex_e->bpp), \
		&(g->tex_e->line_len), &(g->tex_e->endian));
}

void	open_west(t_game *g)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	g->tex_w = ft_calloc(sizeof(t_img), 1);
	g->tex_w->height = HIGHT;
	g->tex_w->width = WIDTH;
	g->tex_w->img_ptr = mlx_new_image(g->mlx, WIDTH, HIGHT);
	g->tex_w->img_ptr = mlx_xpm_file_to_image(g->mlx, g->we, &x, &y);
	g->tex_w->addr = mlx_get_data_addr(g->tex_w->img_ptr, &(g->tex_w->bpp), \
		&(g->tex_w->line_len), &(g->tex_w->endian));
}

void	open_south(t_game *g)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	g->tex_s = ft_calloc(sizeof(t_img), 1);
	g->tex_s->height = HIGHT;
	g->tex_s->width = WIDTH;
	g->tex_s->img_ptr = mlx_new_image(g->mlx, WIDTH, HIGHT);
	g->tex_s->img_ptr = mlx_xpm_file_to_image(g->mlx, g->so, &x, &y);
	g->tex_s->addr = mlx_get_data_addr(g->tex_s->img_ptr, &(g->tex_s->bpp), \
		&(g->tex_s->line_len), &(g->tex_s->endian));
}

void	open_texture(t_game *g)
{
	open_north(g);
	open_south(g);
	open_east(g);
	open_west(g);
}
