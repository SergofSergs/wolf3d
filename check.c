/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 08:57:46 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/18 12:50:51 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		countnums(t_mlx *mlx, char *str, int i) //проверяет строки
{
	int		j;
	int		len;
	int		nulls;
	int		dig;

	j = -1;
	len = ft_strlen(str);
	nulls = 0;
	dig = 0;
	if (i == 0 || i == mlx->height - 1) // если подали первую или последнюю строки они должны состоять из стен полностью
	{
		while (str[++j])
		{
			if (str[j] == 48)
				return (-1);
		}
	}
	else //в строке должны быть только цифры
		while (str[++j])
		{
			if (j == 48) //на карте должен быть хотябы один ноль
				nulls++;
			if ((str[j] >= 48 || str[j] <= 57))
			{	
				dig++;
				if ((str[j + 1] >= 48 || str[j + 1] <= 57) && str[j + 1])
					return (error_mesage("Only one digit numbers\n"));
			}
		}
	if ((i != 0 || i != mlx->height - 1) && (!nulls))
		return (error_mesage("There must at least one place without walls\n"));
	return (dig);
}

int		check_width(t_mlx *mlx, char *str)
{
	int		fd;
	int		i;
	int		width;
	char	*line;

	line = NULL;
	i = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (i == 0)
			mlx->width = countnums(mlx, str, i);
		else if (i != 0)
		{	
			if ((width = countnums(mlx, str, i)) == -1)
			{
				free(line);
				return (error_mesage("There must be walls on the map borders\n"));
			};
		}
		if (i != 0 && (mlx->width != width) && (mlx->width < 3))
		{
			free(line);
			return (error_mesage("Raws must be the same lenght (more than 3)\n"));
		}
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

int		check_line(char *str)
{
	int i;
	int n;
	int len;

	i = -1;
	n = 0;
	len = ft_strlen(str);
	while (str[++i])
	{
		if ((i == 0 && str[i] == 48) || (i == len - 1 && str == 48)) // первый и последний символстороки не могут быть нулями
			return (error_mesage("There must be walls on the map borders\n"));
		if (str[i] >= 48 || str[i] <= 57) // считаем цифры?????
			n++;
		if ((str[i] < 48 || str[i] > 57) && str[i] != ' ' && str[i] != '\t') // разрешены только цифры, пробелы и табы
			return (error_mesage("You can use only numbers, tabs and spaces\n"));
	}
	return (n);
}

int		get_height(t_mlx *mlx, char *str)
{
	int		fd;
	char	*line;

	mlx->height = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if ((check_line(line)) == 0) // что-то должно быть энивэй
		{
			free(line);
			return (0);
		}
		mlx->height++;
		free(line);
	}
	close(fd);
	if (mlx->height < 3) // высота не может быть меньше 3
		return (0);
	return (1);
}

int		check_file(t_mlx *mlx, char *str)
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(str, O_RDONLY)) <= 2 || read(fd, line, 0) < 0) //файл ли это?
		return (error_mesage("Access fail\n"));
	close (fd);
	if (!(get_height(mlx, str))) // проверяем высоту лабиринта
		return (error_mesage("3x3 - is the minimal map grid\n"));
	if (!(check_width(mlx, str))) // проверяем ширину лабиринта
		return (0);
	return (1);
}
/*В результате на вход должна подаваться прямоугольная/квадратная карта. 
Она может состоять только из чисел и 
по всему периметру должна быть ограждена текстурами/стенами. 
Минимальный размер карты - 3х3 с нулём в середине.*/