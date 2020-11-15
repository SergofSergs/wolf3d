/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:13:31 by pjoseth           #+#    #+#             */
/*   Updated: 2020/11/14 13:29:19 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		countblocks(char *line)
{
	int		i;
	int		blocks;

	i = -1;
	blocks = 0;
	while (line[++i])
	{
		if ((line[i] >= 48 && line[i] <= 57) && (line[i + 1])
			&& (line[i + 1] >= 48 && line[i + 1] <= 57))
			return (error_mesage("Only one digit numbers\n"));
		if (line[i] == ' ' && line[i + 1] != ' ' && line[i + 1])
			blocks++;
	}
	if (line[0] != '\0')
		blocks++;
	return (blocks);
}

void	return_raw_number(int i)
{
	int		q;
	char	*srt;
	char	*str;

	q = i + 1;
	srt = ft_itoa(q);
	str = ft_strjoin("Row - ", srt);
	ft_putendl(str);
	free(srt);
	free(str);
}

void	assemble_arr(int **arr, char *str)
{
	int		i;
	int		fd;
	char	*line;

	i = -1;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		fill_line(arr[++i], line);
		free(line);
	}
}

void	fill_line(int *arr, char *line)
{
	int		i;
	int		j;
	char	**z;

	i = 0;
	j = 0;
	z = ft_strsplit(line, ' ');
	while (z[i])
	{
		arr[i] = ft_atoi(z[i]);
		free(z[i]);
		i++;
	}
	free(z);
}
