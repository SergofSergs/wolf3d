/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:52:00 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/14 14:45:54 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initial_calculations(t_game *game, int x)
{
	game->point_on_camera = 2 * x / (double)WIDHT - 1;
	game->ray_dir_x = game->view_vector_x + game->camera_x
		* game->point_on_camera;
	game->ray_dir_y = game->view_vector_y + game->camera_y
		* game->point_on_camera;
	game->map_x = (int)game->player_pos_x;
	game->map_y = (int)game->player_pos_y;
	game->dist_from_x_to_x = sqrt(1 + (game->ray_dir_y * game->ray_dir_y)
		/ (game->ray_dir_x * game->ray_dir_x));
	game->dist_from_y_to_y = sqrt(1 + (game->ray_dir_x * game->ray_dir_x)
		/ (game->ray_dir_y * game->ray_dir_y));
}

void	which_dir(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->dist_to_next_x = (game->player_pos_x - game->map_x)
			* game->dist_from_x_to_x;
	}
	else
	{
		game->step_x = 1;
		game->dist_to_next_x = (game->map_x + 1.0 - game->player_pos_x)
			* game->dist_from_x_to_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->dist_to_next_y = (game->player_pos_y - game->map_y)
			* game->dist_from_y_to_y;
	}
	else
	{
		game->step_y = 1;
		game->dist_to_next_y = (game->map_y + 1.0 - game->player_pos_y)
			* game->dist_from_y_to_y;
	}
}

void	dda(int **arr, t_game *game)
{
	game->hit = 0;
	while (game->hit == 0)
	{
		if (game->dist_to_next_x < game->dist_to_next_y)
		{
			game->dist_to_next_x += game->dist_from_x_to_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->dist_to_next_y += game->dist_from_y_to_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (arr[(int)game->map_x][(int)game->map_y] > 0)
			game->hit = 1;
	}
}

void	raycasting(t_game *game, t_mlx *mlx)
{
	int		x;

	x = -1;
	while (++x < WIDHT)
	{
		initial_calculations(game, x);
		which_dir(game);
		dda(mlx->arr, game);
		color(game);
		draw_walls(game, mlx, x);
	}
}
