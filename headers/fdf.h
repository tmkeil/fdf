/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:59:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/28 03:20:23 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 500
# define HEIGHT 500
# define BACKCOL 0x000000
# define PKTCOL 0xffffff

# define ESC 53

# define UP 126
# define LEFT 123
# define RIGHT 124
# define W 13
# define A 0
# define D 2

# include "../mlx/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
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
	uint32_t	color;
}				t_point;

typedef struct s_wire
{
	t_point		**transformed;
	int			*widths;
	int			height;
	float		max_w;
	float		auto_scale;
	double		avg_w;
	double		avg_h;
}				t_wire;

typedef struct s_mouse
{
	bool		mouse_down;
	int			mouse_x;
	int			mouse_y;
}				t_mouse;

typedef struct s_data
{
	t_mlx		*var;
	t_imgs		*img;
	t_wire		*wirefr;
	t_mouse		mouse;
}				t_data;

typedef struct s_line_vars
{
	float		dx;
	float		dy;
	int			len;
	float		sx;
	float		sy;
}				t_line_vars;

// init
int				ft_init(t_data **data);

// utils
void			ft_putpxl(t_img **img, int x, int y, uint32_t color);
int				ft_set_n_paint_buffer(t_data *data, t_img **buffer);
void			ft_put_buffer_to_window(t_data **data, t_img **current);
void			ft_drawline(t_point *p1, t_point *p2, t_img **buffer);
void			ft_set_max_width(t_wire *wire);

// utils2
size_t			ft_wordcount(char *line);
int				ft_map_height(char *filename);
void			ft_set_line(t_line_vars *line, t_point *p1, t_point *p2,
					int *len);
uint32_t		ft_interpol_color(t_point *p1, t_point *p2, int small, int big);

// numbers
long			ft_atol(char *s);
long			ft_atol_base(const char *str, int str_base);

// parse
int				ft_parsemap(t_data **data, char **argv);

// clear
void			ft_cleardata(t_data *data);
void			ft_clrptr(void **ptr);

// wireframe
int				ft_wire(t_data **data);

// transformation
void			ft_scale(t_wire **wire, float fac, float pad);
void			ft_translate(t_point *point, float x, float y);
void			ft_rotate(t_wire **a, float w, void (*f)(t_point *, float));

// rotation matrices
void			ft_project_isometric(t_point *point, float rad);
void			ft_rotate_x(t_point *point, float rad);
void			ft_rotate_y(t_point *point, float rad);
void			ft_rotate_z(t_point *point, float rad);

// mouse
void			ft_zoom_out(t_data **data, t_wire **wire);
void			ft_zoom_in(t_data **data, t_wire **wire);

void			ft_transform_points(t_wire **wire);
void			ft_connect_points(t_data *data, t_img **buffer);

void			ft_avg_width(t_wire **wire);
void			ft_avg_height(t_wire **wire);

// event handling bonus
int				destroy(t_data *data);
int				mouseclick_down(int button, int x, int y, void *param);
int				mouseclick_up(int button, int x, int y, void *param);
int				mousemove(int x, int y, void *param);
int				keyup(int key, void *param);
void			ft_draw_new(t_data **data);
void			ft_move(t_data **data, int val, int dir);

#endif
