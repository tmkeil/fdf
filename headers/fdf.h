/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:59:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 19:53:20 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 800
# define HEIGHT 800
# define BACKCOL 0x000000
# define WHITE 0xffffff

# define ESC 53
# define CTRL 256

# define W 13
# define S 1
# define A 0
# define D 2

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define P 35
# define M 46

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
	float		avg_w;
	float		avg_h;
}				t_wire;

typedef struct s_mouse
{
	bool		mouse_down;
	bool		ctrl_down;
	int			mouse_x;
	int			mouse_y;
}				t_mouse;

typedef struct s_wnd
{
	int			wnd_w;
	int			wnd_h;
}				t_wnd;

typedef struct s_data
{
	t_mlx		*var;
	t_imgs		*img;
	t_wire		*wirefr;
	t_mouse		mouse;
	t_wnd		wnd;
}				t_data;

typedef struct s_line_vars
{
	float		dx;
	float		dy;
	int			len;
	float		sx;
	float		sy;
}				t_line_vars;

// main
int				destroy(t_data *data);

// init
int				ft_init(t_data **data);
int				ft_init_var(t_data **data);
int				ft_init_imgs(t_data **data);

// utils
int				keyup_mand(int key, void *param);
int				destroy_mand(t_data *data);
int				ft_set_n_paint_buffer(t_data *data, t_img **buffer);
void			ft_put_buffer_to_window(t_data **data, t_img **current);
void			ft_set_max_width(t_wire *wire);

// utils2
size_t			ft_wordcount(char *line);
int				ft_map_height(char *filename);
void			ft_putpxl(t_img **buffer, int x, int y, uint32_t color);
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
void			ft_clear_images(t_imgs **imgs, void *mlx_ptr);
void			ft_clear_mlx(t_data **data);
void			ft_clrptr(void **ptr);

// wireframe
int				ft_wire(t_data *data);
void			ft_drawline(t_data *d, t_point *p1, t_point *p2, t_img **buf);

// transformation
void			ft_autoscale(t_wire **wire, float fac, float pad);
void			ft_translate(t_point *point, float x, float y);
void			ft_rotate(t_wire **a, float w, void (*f)(t_point *, float));
void			ft_setorigin(t_wire **wire);
void			ft_setdefault(t_wire **wire);

// rotation matrices
void			ft_project_isometric(t_point *point, float rad);
void			ft_rotate_x(t_point *point, float rad);
void			ft_rotate_y(t_point *point, float rad);
void			ft_rotate_z(t_point *point, float rad);

// mouse
void			ft_zoom_out(t_data **data, t_wire **wire);
void			ft_zoom_in(t_data **data, t_wire **wire);

void			ft_transform_points(t_wire **wire, int w, int h);
void			ft_connect_points(t_data *data, t_img **buffer);

// positioning
void			ft_middle(t_wire **wire);
void			ft_avg_width(t_wire **wire, float val);
void			ft_avg_height(t_wire **wire, float val);

// resizing wnd
int				ft_wnd_resize_mand(t_data **data, int size);
int				ft_wnd_resize_bonus(t_data **data, int size);

// event handling bonus
void			ft_instructions(void *ptr, void *win);
int				mouse_down(int button, int x, int y, void *param);
int				mouse_up(int button, int x, int y, void *param);
int				mousemove(int x, int y, void *param);
int				keyup(int key, void *param);
int				keydown(int key, void *param);
void			ft_draw_new(t_data **data);
void			ft_move_x(t_data **data, int val);
void			ft_move_y(t_data **data, int val);
void			ft_rot_bonus(t_data *data, int key);

#endif
