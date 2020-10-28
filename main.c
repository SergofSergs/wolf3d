/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:46:15 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/28 16:38:10 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDHT, HEIGHT, "Wolf3d");
	mlx->nulls = 0;
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc != 2)
		return (error_mesage("Usage: ./wolf3d MAP_FILE\n"));
	if (!(mlx = mlx_initial()))
	{
		ft_putstr("Malloc error\n");
		return (0);
	}
	if ((i = (check_file(mlx, argv[1]))) != -10)
	{
		if (i > 0)
		{
			while(--i != -1)
				free(mlx->arr[i]);
			free(mlx->arr);
		}
		free(mlx);
		return (error_mesage("Invalid file\n"));
	}
	else
		ft_putstr("All good\n");
	i = -1;
	while (++i < mlx->height)
	{
		j = -1;
		while(++j < mlx->width)
		{
			ft_putstr(ft_itoa(mlx->arr[i][j]));
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	mlx_hook(mlx->win, 2, 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, red_button, NULL);
	mlx_loop(mlx->ptr);
	return (0);

}
