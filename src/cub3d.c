/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:43:47 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (printf("Error\nInvalid number of arguments"), 0);
	g = ft_calloc(sizeof(t_game), 1);
	g->r = ft_calloc(sizeof(t_game), 1);
	map_parse(argv[1], g, g->r);
	g->mlx = mlx_init(g);
	g->mlx_win = mlx_new_window(g->mlx, WIDTH, HIGHT, "Cub3D");
	init_image(g);
	init_flags(g);
	open_texture(g);
	mlx_hook(g->mlx_win, 2, 1L << 0, key_press, g);
	mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
	mlx_hook(g->mlx_win, 17, 0L << 0, hooked_mouse, g->mlx);
	mlx_loop_hook(g->mlx, loop_hook, g);
	mlx_loop(g->mlx);
	mlx_destroy_image(g->mlx, g->render->img_ptr);
	mlx_destroy_window(g->mlx, g->mlx_win);
	return (0);
}
