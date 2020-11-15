/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:13:56 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/14 14:45:29 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_press(int key, t_mlx *mlx)
{
	int i;

	i = -1;
	if (key == 53)
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
	if (key == 257 || key == 258)
		mlx->game->sprint = 1;
	if (key == 126)
		mlx->game->up = 1;
	if (key == 125)
		mlx->game->down = 1;
	if (key == 123)
		mlx->game->left = 1;
	if (key == 124)
		mlx->game->right = 1;
	return (0);
}

int			release_to_not(int key, t_mlx *mlx)
{
	if (key == 257 || key == 258)
		mlx->game->sprint = 0;
	if (key == 126)
		mlx->game->up = 0;
	if (key == 125)
		mlx->game->down = 0;
	if (key == 123)
		mlx->game->left = 0;
	if (key == 124)
		mlx->game->right = 0;
	return (0);
}
