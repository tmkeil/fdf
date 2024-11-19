/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:59:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/18 22:13:09 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1000
# define HEIGHT 1000
# define BACKCOL 0xffffff
# define PKTCOL 0x000000

# include "../mlx/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_image_data
{
	void			*img;
	char			*data;
	int				linelen;
	int				bpp;
	int				endian;
}					t_image_data;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_image_data	*img0;
	t_image_data	*img1;
	t_image_data	*img2;
}					t_mlx;

typedef struct s_imgs
{
	t_image_data	*img1;
	t_image_data	*img2;
}					t_imgs;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct s_line
{
	t_point			*p1;
	t_point			*p2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				error;
}					t_line;

typedef struct s_wireframe
{
	int				num_lines;
	t_line			*lines;
}					t_wireframe;

typedef struct s_map
{
	t_point			**matrix;
	int				*widths;
	int				height;
}					t_map;

typedef struct s_nested
{
	void			**val_col;
}					t_nested;

void				del(void *content);
int					ft_abs(int value);
int					ft_rgb(int r, int g, int b);
void				ft_arrangeline(t_line *line);
void				ft_window_fill(t_mlx *mlx, int color);
void				ft_putpxl(t_image_data *img, int x, int y, int color);

#endif
