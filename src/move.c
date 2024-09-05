/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:47:59 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	mod_turn(t_game *g)
{
	double	turn;

	turn = 0;
	if (g->r->w_flag == 1)
		turn = g->r->player_angle;
	else if (g->r->a_flag == 1)
		turn = g->r->player_angle + 90;
	else if (g->r->d_flag == 1)
		turn = g->r->player_angle - 90;
	else if (g->r->s_flag == 1)
		turn = g->r->player_angle + 180;
	turn = nor_angle(turn);
	return (turn);
}

void	move_player(t_game *g)
{
	float	sinus;
	float	cosen;
	float	increment;
	float	next[2];
	float	m_ray;

	sinus = 0;
	cosen = 0;
	increment = 0.3;
	if (g->r->r_flag == 1 || g->r->l_flag == 1)
		turn_player(g);
	else if (g->r->w_flag == 1 || g->r->s_flag == 1
		|| g->r->a_flag == 1 || g->r->d_flag == 1)
	{
		m_ray = mod_turn(g);
		sinus = increment * sin(degree_to_radians(m_ray));
		cosen = increment * cos(degree_to_radians(m_ray));
		next[1] = g->r->p_y + sinus;
		next[0] = g->r->p_x + cosen;
		move(next, g);
	}
}

void	move(float *next, t_game *g)
{
	int	jump[2];

	jump[0] = (int)next[0];
	jump[1] = (int)next[1];
	if (check_colition(g, jump) == 0)
	{
		g->r->p_x = next[0];
		g->r->p_y = next[1];
	}
}

void	turn_player(t_game *g)
{
	if (g->r->r_flag == 1)
		g->r->player_angle = g->r->player_angle - 2;
	else if (g->r->l_flag == 1)
	{
		g->r->player_angle = g->r->player_angle + 2;
	}
	g->r->player_angle = nor_angle(g->r->player_angle);
}

void	do_event(t_game *g)
{
	if (g->r->r_flag == 0 && g->r->l_flag == 0
		&& g->r->w_flag == 0 && g->r->a_flag == 0
		&& g->r->s_flag == 0 && g->r->d_flag == 0)
		return ;
	move_player(g);
}
