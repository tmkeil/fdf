/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/23 21:58:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpxl(t_img **img, int x, int y, uint32_t color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	offset = x * ((*img)->bpp / 8) + y * (*img)->linelen;
	*(unsigned int *)((*img)->data + offset) = color;
}

int	ft_set_n_paint_buffer(t_data *data, t_img **buffer)
{
	int	i;
	int	j;

	if (!data->img->buffer1 || !data->img->buffer2)
		return (0);
	if (data->img->current == data->img->buffer1)
		*buffer = data->img->buffer2;
	else
		*buffer = data->img->buffer1;
	if (!buffer)
		return (0);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			ft_putpxl(buffer, j++, i, BACKCOL);
		i++;
	}
	return (1);
}

void	ft_put_buffer_to_window(t_data **data, t_img **current)
{
	t_mlx	*mlx;

	mlx = (*data)->var;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, (*current)->img, 0, 0);
	(*data)->img->current = *current;
}

static void	ft_update_current(int *current_x, int *current_y, t_line_vars *line)
{
	int	e;

	e = 2 * line->error;
	if (e >= line->dy)
	{
		line->error += line->dy;
		*current_x += line->sx;
	}
	if (e <= line->dx)
	{
		line->error += line->dx;
		*current_y += line->sy;
	}
}

void	ft_drawline(t_point *p1, t_point *p2, t_img **buffer)
{
	t_point		current;
	t_line_vars	line;

	current.x = p1->x;
	current.y = p1->y;
	current.color = p1->color;
	ft_set_line(&line, p1, p2);
	while (1)
	{
		ft_putpxl(buffer, current.x, current.y, current.color);
		if (current.x == p2->x && current.y == p2->y)
			break ;
		ft_update_current(&current.x, &current.y, &line);
		// ft_interpol_color(p1, p2, current);
	}
}
