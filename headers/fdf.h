/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:59:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/20 18:05:24 by tkeil            ###   ########.fr       */
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

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
}					t_mlx;

typedef struct s_image_data
{
	void			*img;
	char			*data;
	int				linelen;
	int				bpp;
	int				endian;
}					t_image_data;

typedef struct s_imgs
{
	t_image_data	*current;
	t_image_data	*buffer1;
	t_image_data	*buffer2;
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

typedef struct s_data
{
	t_mlx			*var;
	t_imgs			*img;
	t_wireframe		*wirefr;
}					t_data;

typedef struct s_map
{
	int				**profile;
	int				**colors;
	int				*widths;
	int				height;
}					t_map;

// init
int					ft_init(t_data **data);

//
int					ft_abs(int value);
int					ft_rgb(int r, int g, int b);
void				ft_arrangeline(t_line *line);
void				ft_putpxl(t_image_data *img, int x, int y, int color);
void				ft_paint_buffer(t_mlx *mlx, t_image_data *img, int color);

// utils
int					ft_map_height(char *filename);
void				ft_set_current(t_data *data, t_image_data **current);

// utils2
size_t				ft_len(char **map_ln);
int					ft_abs(int value);
int					ft_rgb(int r, int g, int b);
size_t				ft_wordcount(char *line);

// numbers
long				ft_atol(char *s);
long				ft_atol_base(const char *str, int str_base);

// parse
int					ft_parsemap(t_map **map, char **argv);

// clear
void				ft_clearmap(t_map *map);
void				ft_clrptr(void **ptr);
void				ft_cleardata(t_data *data);

#endif
