/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:57:46 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/15 21:13:12 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_line2(t_mlx *mlx, char *line, int i)
{
	int		q;

	q = -1;
	while (line[++q])
	{
		if (line[q] == 48)
			mlx->nulls++;
		if (line[q] == 57)
			mlx->game->player_pos++;
		if (mlx->game->player_pos > 1)
			return (error_mesage("Only one player\n"));
	}
	if (i == 0)
		mlx->collumns = countblocks(line);
	else if (i != 0)
		mlx->width = countblocks(line);
	if (i != 0 && (mlx->collumns != mlx->width))
		return (error_mesage("All rows must be the same lenght\n"));
	if (mlx->collumns < 3)
		return (error_mesage("Columns error\n"));
	return (mlx->collumns);
	free(line);
	return (1);
}

int		check_line(t_mlx *mlx, char *line, int i, int len)
{
	int		q;

	q = -1;
	if (line[0] <= 48 || line[0] >= 57 ||
		line[len - 1] <= 48 || line[len - 1] >= 57)
		return (error_mesage("There must be walls on edges\n"));
	if (i == 0 || (i == mlx->height - 1))
	{
		while (line[++q])
		{
			if ((line[q] < 49 || line[q] >= 57) && line[q] != ' ')
				return (error_mesage("Walls on the edges are mandatory\n"));
		}
	}
	else
	{
		while (line[++q])
		{
			if ((line[q] < 48 || line[q] > 57) && line[q] != ' ')
				return (error_mesage("Forbidden symbols\n"));
		}
	}
	return (len);
}

int		get_width(t_mlx *mlx, char *str)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (!(check_line(mlx, line, i, (int)ft_strlen(line))))
		{
			return_raw_number(i);
			return (0);
		}
		if (!(check_line2(mlx, line, i)))
		{
			return_raw_number(i);
			return (0);
		}
		i++;
		free(line);
	}
	if (!mlx->nulls && !mlx->game->player_pos)
		return (error_mesage("At least 1 empty room\n"));
	close(fd);
	return (1);
}

int		get_height(t_mlx *mlx, char *str)
{
	int		fd;
	char	*line;

	mlx->height = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		mlx->height++;
		free(line);
	}
	close(fd);
	return (mlx->height);
}

int		check_file(t_mlx *mlx, char *str)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	line = NULL;
	if ((fd = open(str, O_RDONLY)) <= 2 || read(fd, line, 0) < 0)
		return (error_mesage("Access fail\n"));
	close(fd);
	if ((get_height(mlx, str)) < 3)
		return (error_mesage("3 raws is a minimum\n"));
	if (!(get_width(mlx, str)))
		return (0);
	if (mlx->game->player_pos != 1)
		return (error_mesage("No player\n"));
	if (!(mlx->arr = (int**)malloc(sizeof(int*) * (mlx->height))))
		return (0);
	while (++i < mlx->height)
	{
		if (!(mlx->arr[i] = (int*)malloc(sizeof(int) * mlx->width)))
			return (i);
	}
	assemble_arr(mlx->arr, str);
	return (-10);
}
