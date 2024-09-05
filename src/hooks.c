/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:38:22 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(g->mlx, g->render->img_ptr);
		mlx_destroy_window(g->mlx, g->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode != RIGHT && keycode != LEFT && keycode != W
		&& keycode != A && keycode != D && keycode != S)
		return (1);
	else if (keycode == RIGHT)
		g->r->r_flag = 1;
	else if (keycode == LEFT)
		g->r->l_flag = 1;
	else if (keycode == W)
		g->r->w_flag = 1;
	else if (keycode == A)
		g->r->a_flag = 1;
	else if (keycode == D)
		g->r->d_flag = 1;
	else if (keycode == S)
		g->r->s_flag = 1;
	return (keycode);
}

int	key_release(int keycode, t_game *g)
{
	if (keycode != RIGHT && keycode != LEFT && keycode != W
		&& keycode != A && keycode != D && keycode != S)
		return (1);
	else if (keycode == RIGHT)
		g->r->r_flag = 0;
	else if (keycode == LEFT)
		g->r->l_flag = 0;
	else if (keycode == W)
		g->r->w_flag = 0;
	else if (keycode == A)
		g->r->a_flag = 0;
	else if (keycode == D)
		g->r->d_flag = 0;
	else if (keycode == S)
		g->r->s_flag = 0;
	return (keycode);
}

int	hooked_mouse(t_game *g)
{
	(void)g;
	exit(EXIT_SUCCESS);
}

void	mouse_move(t_game *g)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(g->mlx, g->mlx_win, &x, &y);
	if (y < 0 || y > HIGHT)
		return ;
	if (x < 0 || x > WIDTH)
		return ;
	if (x > WIDTH - WIDTH / 4)
		g->r->player_angle = g->r->player_angle - 2;
	else if (x <= WIDTH / 4)
		g->r->player_angle = g->r->player_angle + 2;
}

int	loop_hook(t_game *g)
{
	do_event(g);
	mouse_move(g);
	raycast(g);
	sprite_to_map(g);
	return (0);
}