/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:42:26 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/16 12:52:52 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIDHT 1000
# define HEIGHT 500
# include "libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

typedef struct		s_game
{
	double			player_pos_x;
	double			player_pos_y;
	double			view_vector_x;
	double			view_vector_y;
	double			camera_x;
	double			camera_y;
	double			point_on_camera;
	double			ray_dir_x;
	double			ray_dir_y;
	double			map_x;
	double			map_y;
	double			dist_to_next_x;
	double			dist_to_next_y;
	double			dist_from_x_to_x;
	double			dist_from_y_to_y;
	double			step_x;
	double			step_y;
	double			perp_wall_dist;
	int				hit;
	int				side;
	int				draw_start;
	int				draw_end;
	int				line_height;
	int				color;
	short			up;
	short			down;
	short			left;
	short			right;
	short			sprint;
	double			old_dir;
	double			old_plane;
	int				player_pos;
}					t_game;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	unsigned char	*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				height;
	int				width;
	int				collumns;
	int				nulls;
	int				**arr;
	t_game			*game;
}					t_mlx;

int					player_inits(t_game *game, t_mlx *mlx);
int					check_ret(t_mlx *mlx, int i);
int					error_mesage(char *str);
t_mlx				*mlx_initial(void);

int					key_press(int key, t_mlx *mlx);
int					red_button(t_mlx *mlx);
int					press_to_move(int key, t_mlx *mlx);
int					release_to_not(int key, t_mlx *mlx);

int					check_file(t_mlx *mlx, char *str);
int					get_height(t_mlx *mlx, char *str);
int					get_width(t_mlx *mlx, char *str);
int					check_line(t_mlx *mlx, char *line, int i, int len);
int					check_line2(t_mlx *mlx, char *line, int i);

int					countblocks(char *line);
void				return_raw_number(int i);
void				assemble_arr(int **arr, char *str);
void				fill_line(int *arr, char *line);

void				initial_calculations(t_game *game, int x);
void				which_dir(t_game *game);
void				dda(int **arr, t_game *game);
void				raycasting(t_game *game, t_mlx *mlx);

void				pix_to_img(t_mlx *mlx, int color, int x, int l);
void				draw_lines(t_mlx *mlx, int x);
void				draw_walls(t_game *game, t_mlx *mlx, int x);
void				color(t_game *game);
void				map(t_mlx *mlx, t_game *game);

void				key_left(t_game *game, double rs);
void				key_right(t_game *game, double rs);
void				key_down(int **arr, t_game *game, double ms);
void				key_up(int **arr, t_game *game, double ms);
int					move(t_mlx *mlx);

#endif
