/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:13:31 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/24 13:14:09 by pjoseth          ###   ########.fr       */
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
		if ((line[i] == ' ' || line[i] == '\t') &&
			(line[i + 1] != ' ' && line[i + 1] != '\t') && line[i + 1])
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
