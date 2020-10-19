/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:13:56 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/18 08:14:37 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	if (key == 12)
		mlx_clear_window(mlx->ptr, mlx->win);
	return (0);
}

int		red_button(void *p)
{
	(void)p;
	exit(0);
}
