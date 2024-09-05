/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:44:08 by iarbaiza          #+#    #+#             */
/*   Updated: 2024/06/21 13:59:28 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1300
# define HIGHT 800 //1024

# define W 119
# define S 115
# define A 97
# define D 100
# define RIGHT 65363
# define LEFT 65361
# define M_PI 3.14159265358979323846

# define FOV 50

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "./minilib/mlx.h"
# include "./Libft/libft.h"

typedef struct s_ray
{
	double	player_angle;
	float	p_x;
	float	p_y;
	int		w_flag;
	int		s_flag;
	int		a_flag;
	int		d_flag;
	int		r_flag;
	int		l_flag;
	int		colition;
	float	col_x;
	float	col_y;
}	t_ray;

typedef struct s_img
{
	void	*img_ptr;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;

	char	**map;
	char	**map_cop;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*t_f;
	char	*t_c;
	int		rgb_up[3];
	int		rgb_down[3];
	int		width_map;
	int		height_map;
	t_ray	*r;
	void	*img;
	t_img	*render;
	t_img	*tex_n;
	t_img	*tex_s;
	t_img	*tex_e;
	t_img	*tex_w;
}	t_game;

/* ********************************************************** */
/*                           PARSEO                           */
/* ********************************************************** */
/* Reading map - read_map.c*/
int		line_verify(t_game *g, char *line, int i);
int		verification(char *line, t_game *g, int count);
void	read_map_extended(char **str, char **line, t_game *game, int *count);
void	read_map(int fd, t_game *game);
void	map_parse(char *argv, t_game *m, t_ray *ray);

/* Utils Parse - utils_parse.c*/
char	*check_path(char *path);
int		check_int(char *str);
int		empty(char *str);
int		cub_file(char *argv, int mod);
int		int_verification(char *temp_f, char *temp_c, t_game *g);

/* ********************************************************** */
/*                           ERRORS                           */
/* ********************************************************** */
/* Map errors - check_map.c*/
void	get_player_angle(t_game *g, char c);
void	fill_map(char **map, int x, int y);
int		check_line(t_game *game, char *next, char *pre, int x);
int		get_player(t_game *game, t_ray *ray);
void	map_args(t_game *game, t_ray *ray);

/* Checks colitions - check_colition.c */
int		check_colition(t_game *g, int *next);

/* ********************************************************** */
/*                         RAYCASTING                         */
/* ********************************************************** */
/* DDA - dda.c */
float	dda(t_game *g, double angle);
void	incr_calc(float *ray_x, float *ray_y, double ray);
int		colition(t_game *g, int x, int y);

/* Casting */
void	raycast(t_game *g);
double	correct_cast_angle(t_game *g);
float	cast(t_game *g, double ray);
float	degree_to_radians(float degree);

/* ********************************************************** */
/*                           DRAWING                          */
/* ********************************************************** */
/* 3D printing - map3D.c*/
float	unfish(float distance, float angle, double player_angle);
int		floor_wall_roof_proportion(float distance, float *wall, int flag);
int		draw_vert_line(t_game *g, int x, float *limit, int color);
void	img_pix_put(t_game *g, int x, int y, int color);
void	init_image(t_game *g);

/*wall_direction.c*/
t_img	*get_texture(float angle, int flag, t_game *g);
float	nor_angle(float angle);

//texturer.c
int		get_tex_pix(t_img *tex, int x, int y);
void	tex_pix_put(t_game *g, int x, int y, int tex_pix);
void	open_texture(t_game *g);
int		draw_texture(t_game *g, int wall_x, float *wall, t_img *tex);

/* ********************************************************** */
/*                           MOVING                           */
/* ********************************************************** */
/* initialize movements - initialize.c */
void	init_flags(t_game *g);

/*move.c*/
double	mod_turn(t_game *g);
void	move_player(t_game *g);
void	move(float *next, t_game *g);
void	turn_player(t_game *g);
void	do_event(t_game *g);

/*  hook event */
int		key_press(int keycode, t_game *g);
int		key_release(int keycode, t_game *g);
int		hooked_mouse(t_game *g);
void	mouse_move(t_game *g);
int		loop_hook(t_game *g);

/* ********************************************************** */
/*                           EXTRAS                           */
/* ********************************************************** */

/* Utils */
void	ft_error(char	*str);
int		is_valid_char(char c, char *valid_char);
void	remove_spaces(char *str);
void	free_char2(char **str);
int		ft_strlen_int(char *str);

/* 2D map - 2D.c*/
void	sprite_wall(int c_x, int c_y, t_game *g);
void	sprite_floor(int c_x, int c_y, t_game *g);
void	sprite_player(int c_x, int c_y, t_game *g);
void	sprite_to_map(t_game *g);
void	player_cell(t_game *g);
void	render_rect(t_game *g, int x, int y, int color);

#endif
