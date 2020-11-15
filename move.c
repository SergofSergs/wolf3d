/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:18:50 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/14 16:53:46 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_left(t_game *game, double rs)
{
	double old_dir;
	double old_plane;

	old_dir = game->view_vector_x;
	old_plane = game->camera_x;
	game->view_vector_x = game->view_vector_x * cos(rs * -1)
		- game->view_vector_y * sin(rs * -1);
	game->view_vector_y = old_dir * sin(rs * -1)
		+ game->view_vector_y * cos(rs * -1);
	game->camera_x = game->camera_x * cos(rs * -1)
		- game->camera_y * sin(rs * -1);
	game->camera_y = old_plane * sin(rs * -1)
		+ game->camera_y * cos(rs * -1);
}

void	key_right(t_game *game, double rs)
{
	double old_dir;
	double old_plane;

	old_dir = game->view_vector_x;
	old_plane = game->camera_x;
	game->view_vector_x = game->view_vector_x * cos(rs)
		- game->view_vector_y * sin(rs);
	game->view_vector_y = old_dir * sin(rs)
		+ game->view_vector_y * cos(rs);
	game->camera_x = game->camera_x * cos(rs)
		- game->camera_y * sin(rs);
	game->camera_y = old_plane * sin(rs)
		+ game->camera_y * cos(rs);
}

void	key_down(int **arr, t_game *game, double ms)
{
	if (arr[(int)(game->player_pos_x - game->view_vector_x * ms)]
		[(int)game->player_pos_y] == 0)
		game->player_pos_x -= game->view_vector_x * ms;
	if (arr[(int)game->player_pos_x]
		[(int)(game->player_pos_y - game->view_vector_y * ms)] == 0)
		game->player_pos_y -= game->view_vector_y * ms;
}

void	key_up(int **arr, t_game *game, double ms)
{
	if (arr[(int)(game->player_pos_x + game->view_vector_x * ms)]
		[(int)game->player_pos_y] == 0)
		game->player_pos_x += game->view_vector_x * ms;
	if (arr[(int)game->player_pos_x]
		[(int)(game->player_pos_y + game->view_vector_y * ms)] == 0)
		game->player_pos_y += game->view_vector_y * ms;
}

int		move(t_mlx *mlx)
{
	double	ms;
	double	rs;

	if (mlx->game->sprint == 1)
		ms = 0.06;
	else
		ms = 0.03;
	rs = 0.03;
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->ptr, WIDHT, HEIGHT);
	if (mlx->game->up == 1)
		key_up(mlx->arr, mlx->game, ms);
	if (mlx->game->down == 1)
		key_down(mlx->arr, mlx->game, ms);
	if (mlx->game->left == 1)
		key_right(mlx->game, rs);
	if (mlx->game->right == 1)
		key_left(mlx->game, rs);
	raycasting(mlx->game, mlx);
	map(mlx, mlx->game);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}
