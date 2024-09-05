/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:23:32 by xbasabe-          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:33 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += 360;
	if (angle >= 360)
		angle -= 360;
	return (angle);
}

t_img	*get_texture(float angle, int flag, t_game *g)
{
	angle = nor_angle(angle);
	if (flag == 1)
	{
		if (angle > 90 && angle < 270)
			return (g->tex_n);
		else
			return (g->tex_s);
	}
	else
	{
		if (angle > 0 && angle < 180)
			return (g->tex_e);
		else
			return (g->tex_w);
	}
}
