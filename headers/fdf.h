/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:59:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/23 22:02:38 by tkeil            ###   ########.fr       */
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
	void		*mlx_ptr;
	void		*mlx_win;
}				t_mlx;

typedef struct s_img
{
	void		*img;
	char		*data;
	int			linelen;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_imgs
{
	t_img		*current;
	t_img		*buffer1;
	t_img		*buffer2;
}				t_imgs;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	u_int32_t	color;
}				t_point;

typedef struct s_line_vars
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
}				t_line_vars;

typedef struct s_map
{
	int			**profile;
	int			**colors;
	int			*widths;
	int			height;
}				t_map;

typedef struct s_wireframe
{
	t_point		**transformed;
}				t_wireframe;

typedef struct s_data
{
	t_mlx		*var;
	t_imgs		*img;
	t_map		*map;
	t_wireframe	*wirefr;
}				t_data;

// init
int				ft_init(t_data **data);

// utils
void			ft_putpxl(t_img **img, int x, int y, uint32_t color);
int				ft_set_n_paint_buffer(t_data *data, t_img **buffer);
void			ft_put_buffer_to_window(t_data **data, t_img **current);
void			ft_drawline(t_point *p1, t_point *p2, t_img **buffer);

// utils2
size_t			ft_wordcount(char *line);
int				ft_map_height(char *filename);
void			ft_set_line(t_line_vars *line, t_point *p1, t_point *p2);

// numbers
long			ft_atol(char *s);
long			ft_atol_base(const char *str, int str_base);

// parse
int				ft_parsemap(t_data **data, char **argv);

// clear
void			ft_cleardata(t_data *data);
void			ft_clrptr(void **ptr);

// wireframe
int				ft_wireframe(t_data **data);

// transformation
void			ft_scale(t_point *point, float scale);
void			ft_translate(t_point *point, float x, float y);
void			ft_rotate(t_point *p, float w, void (*f)(t_point *, float));

// rotation matrices
void			ft_project_isometric(t_point *point, float rad);
void			ft_rotate_x(t_point *point, float rad);
void			ft_rotate_y(t_point *point, float rad);
void			ft_rotate_z(t_point *point, float rad);

// void			ft_print(t_point **map, t_map *v);

#endif
