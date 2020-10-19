/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:42:26 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/18 09:02:50 by pjoseth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIDHT 1280
# define HEIGHT 720
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	unsigned char	*img_data;
	int				height;
	int				width;
}					t_mlx;

int		error_mesage(char *str);
int		key_press(int key, t_mlx *mlx);
int		red_button(void *p);
t_mlx	*mlx_initial(char *str);
int		check_file(t_mlx *mlx, char *str);

#endif
