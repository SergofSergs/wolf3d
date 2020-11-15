/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:46:15 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/14 16:32:26 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		player_inits(t_game *game, t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < mlx->height)
	{
		while (y < mlx->width)
		{
			if (mlx->arr[x][y] == 9)
			{
				mlx->arr[x][y] = 0;
				game->player_pos_x = x + 0.4;
				game->player_pos_y = y + 0.4;
				return (0);
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (1);
}

int		check_ret(t_mlx *mlx, int i)
{
	if (i > 0)
	{
		while (--i != -1)
			free(mlx->arr[i]);
		free(mlx->arr);
	}
	free(mlx->game);
	free(mlx);
	return (error_mesage("Invalid file\n"));
}

int		error_mesage(char *str)
{
	ft_putstr(str);
	return (0);
}

t_mlx	*mlx_initial(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->game = (t_game*)malloc(sizeof(t_game))))
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDHT, HEIGHT, "Wolf3d");
	mlx->img = mlx_new_image(mlx->ptr, WIDHT, HEIGHT);
	mlx->nulls = 0;
	mlx->game->view_vector_x = -1;
	mlx->game->view_vector_y = 0;
	mlx->game->camera_x = 0;
	mlx->game->camera_y = 0.9;
	mlx->game->player_pos = 0;
	mlx->game->up = 0;
	mlx->game->down = 0;
	mlx->game->left = 0;
	mlx->game->right = 0;
	mlx->img_data = (unsigned char*)mlx_get_data_addr(mlx->img, &mlx->bpp,
		&mlx->size_line, &mlx->endian);
	return (mlx);
}

int		main(int argc, char **argv)
{
	int		i;
	t_mlx	*mlx;

	if (argc != 2)
		return (error_mesage("Usage: ./wolf3d MAP_FILE\n"));
	if (!(mlx = mlx_initial()))
	{
		ft_putstr("Malloc error\n");
		return (0);
	}
	if ((i = (check_file(mlx, argv[1]))) != -10)
		return (check_ret(mlx, i));
	else
		ft_putstr("All good\n");
	if (player_inits(mlx->game, mlx) == 1)
		return (check_ret(mlx, (mlx->height - 1)));
	raycasting(mlx->game, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, release_to_not, mlx);
	mlx_hook(mlx->win, 17, 0, red_button, mlx);
	mlx_loop_hook(mlx->ptr, move, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
