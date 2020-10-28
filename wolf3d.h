/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjoseth <pjoseth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:42:26 by pjoseth           #+#    #+#             */
/*   Updated: 2020/10/28 16:18:32 by pjoseth          ###   ########.fr       */
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
	int				collumns;
	int				nulls;
	int				**arr;
}					t_mlx;

int					error_mesage(char *str);
int					key_press(int key, t_mlx *mlx);
int					red_button(t_mlx *mlx);
t_mlx				*mlx_initial(void);

int					check_file(t_mlx *mlx, char *str);
int					get_height(t_mlx *mlx, char *str);
int					get_width(t_mlx *mlx, char *str);
int					check_line(t_mlx *mlx, char *line, int i, int len);
int					check_line2(t_mlx *mlx, char *line, int i);

int					countblocks(char *line);
void				return_raw_number(int i);
void				assemble_arr(int **arr, char *str);
void				fill_line(int *arr, char *line);

#endif
