/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:00:08 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_colition(t_game *g, int *next)
{
	if (!g->map[next[0]][next[1]])
		return (2);
	if (g->map[(int)g->r->p_x][next[1]] == '1'
		|| g->map[(int)g->r->p_x][next[1]] == ' ')
		return (1);
	if (g->map[next[0]][(int)g->r->p_y] == '1'
		|| g->map[next[0]][(int)g->r->p_y] == ' ')
		return (1);
	if (g->map[next[0]][next[1]] == '1'
		|| g->map[next[0]][next[1]] == ' ')
		return (1);
	else
		return (0);
}
