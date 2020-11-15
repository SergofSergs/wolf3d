/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:29:28 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/14 16:53:31 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pix_to_img(t_mlx *mlx, int color, int x, int l)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (mlx->bpp / 8) + l * (mlx->size_line);
	while (i < (mlx->bpp / 8))
	{
		mlx->img_data[p + i] = color;
		color >>= 8;
		i++;
	}
}

void	draw_lines(t_mlx *mlx, int x)
{
	int l;

	l = 0;
	while (l < HEIGHT)
	{
		if (l < mlx->game->draw_start)
			pix_to_img(mlx, 0x8f7be8, x, l);
		else if (l >= mlx->game->draw_start && l <= mlx->game->draw_end)
			pix_to_img(mlx, mlx->game->color, x, l);
		else
		{
			if (l > mlx->game->draw_start)
				pix_to_img(mlx, 0x914f19, x, l);
		}
		l++;
	}
}

void	draw_walls(t_game *game, t_mlx *mlx, int x)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->map_x - game->player_pos_x +
			(1 - game->step_x) / 2) / game->ray_dir_x;
	else
		game->perp_wall_dist = (game->map_y - game->player_pos_y +
			(1 - game->step_y) / 2) / game->ray_dir_y;
	game->line_height = (int)(HEIGHT / game->perp_wall_dist);
	game->draw_start = ((-1 * game->line_height) / 2) + (HEIGHT / 2);
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = (game->line_height / 2) + (HEIGHT / 2);
	if (game->draw_end >= HEIGHT)
		game->draw_end = HEIGHT - 1;
	draw_lines(mlx, x);
}

void	map(t_mlx *mlx, t_game *game)
{
	int i;
	int j;
	int q;
	int	w;

	i = -1;
	while (++i < mlx->height * 5)
	{
		j = -1;
		while (++j < mlx->width * 5)
			pix_to_img(mlx, 0x000000, j, i);
	}
	i = -1;
	while (++i < mlx->height)
	{
		j = -1;
		while (++j < mlx->width)
		{
			if (mlx->arr[i][j] != 0)
			{
				q = -1;
				while (++q < 6)
				{
					w = -1;
					while (++w < 6)
						pix_to_img(mlx, 0xFFFFFF, (j * 5 + q), (i * 5 + w));
				}
			}
		}
	}
	q = -1;
	while (++q < 6)
	{
		w = -1;
		while (++w < 6)
			pix_to_img(mlx, 0x00FF00, ((int)game->player_pos_y * 5 + q),
				((int)game->player_pos_x * 5 + w));
	}
}

void	color(t_game *game)
{
	if (game->side == 0)
	{
		if (game->step_x < 0)
			game->color = 0xFF00FF;
		else
			game->color = 0x6FA8DC;
	}
	else
	{
		if (game->step_y > 0)
			game->color = 0xFFFFFF;
		else
			game->color = 0x9900FF;
	}
}
