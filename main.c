/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:46:15 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/18 08:59:36 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		error_mesage(char *str)
{
	ft_putstr(str);
	return (0);
}

t_mlx	*mlx_initial(char *str)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDHT, HEIGHT, "Wolf3d");
	ft_putstr(str);
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (error_mesage("Usage: ./wolf3d MAP_FILE\n"));
	if (!(check_file(mlx, argv[1])))
		return (error_mesage("Invalid file\n"));
	if (!(mlx = mlx_initial(argv[1])))
	{
		ft_putstr("Malloc error\n");
		return (0);
	}
	mlx_hook(mlx->win, 2, 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, red_button, NULL);
	mlx_loop(mlx->ptr);
	free(mlx);
	return (0);
}
