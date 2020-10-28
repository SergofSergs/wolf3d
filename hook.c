/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:13:56 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/28 16:41:16 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int key, t_mlx *mlx)
{
	int i;

	i = -1;
	if (key == 53)
	{
		while (++i < mlx->height)
			free(mlx->arr[i]);
		free(mlx->arr);
		free(mlx);
		exit(0);
	}
	return (0);
}

int		red_button(t_mlx *mlx)
{
	free(mlx);
	exit(0);
}
