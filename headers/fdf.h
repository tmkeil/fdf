/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:59:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 21:30:13 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1500
# define HEIGHT 600
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
	float		x;
	float		y;
	float		z;
	u_int32_t	color;
}				t_point;

typedef struct s_line_vars
{
	float		dx;
	float		dy;
	float		sx;
	float		sy;
	float		error;
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
int				ft_drawline(t_point *p1, t_point *p2, t_img **buffer);

// utils2
int				ft_map_height(char *filename);
int				ft_abs(float value);
size_t			ft_wordcount(char *line);
int				ft_lineset(t_line_vars **line, t_point *p1, t_point *p2);

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
void			ft_translate(t_data **data, float x, float y, float z);
void			ft_rotate_x(t_point *point, float rad);
void			ft_rotate_y(t_point *point, float rad);
void			ft_rotate_z(t_point *point, float rad);
void			ft_rotate(t_data **d, float p, void (*f)(t_point *, float));

#endif
