/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:13:56 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/16 12:53:04 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_press(int key, t_mlx *mlx)
{
	int i;

	i = -1;
	if (key == 65307)
	{
		while (++i < mlx->height)
			free(mlx->arr[i]);
		free(mlx->arr);
		free(mlx->game);
		free(mlx);
		exit(0);
	}
	press_to_move(key, mlx);
	return (0);
}

int			red_button(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i < mlx->height)
		free(mlx->arr[i]);
	free(mlx->arr);
	free(mlx->game);
	free(mlx);
	exit(0);
}

int			press_to_move(int key, t_mlx *mlx)
{
	if (key == 65505 || key == 65506)
		mlx->game->sprint = 1;
	if (key == 65362)
		mlx->game->up = 1;
	if (key == 65364)
		mlx->game->down = 1;
	if (key == 65361)
		mlx->game->left = 1;
	if (key == 65363)
		mlx->game->right = 1;
	return (0);
}

int			release_to_not(int key, t_mlx *mlx)
{
	if (key == 65505 || key == 65506)
		mlx->game->sprint = 0;
	if (key == 65362)
		mlx->game->up = 0;
	if (key == 65364)
		mlx->game->down = 0;
	if (key == 65361)
		mlx->game->left = 0;
	if (key == 65363)
		mlx->game->right = 0;
	return (0);
}
