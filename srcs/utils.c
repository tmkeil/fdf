/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/25 12:45:15 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_update_current(int *cur_x, int *cur_y, t_line_vars *line)
{
	int	e;

	e = 2 * line->error;
	if (e >= line->dy)
	{
		line->error += line->dy;
		*cur_x += line->sx;
	}
	if (e <= line->dx)
	{
		line->error += line->dx;
		*cur_y += line->sy;
	}
}

void	ft_set_max_width(t_wire *wire)
{
	int	i;
	int	j;
	int	min;
	int	max;

	i = 0;
	max = 0;
	min = INT_MAX;
	while (i < wire->height)
	{
		j = 0;
		while (j < wire->widths[i])
		{
			if (wire->transformed[i][j].x <= min)
				min = wire->transformed[i][j].x;
			if (wire->transformed[i][j].x >= max)
				max = wire->transformed[i][j].x;
			j++;
		}
		i++;
	}
	wire->max_w = max - min;
}

void	ft_set_max_height(t_wire *wire)
{
	int	i;
	int	j;
	int	min;
	int	max;

	i = 0;
	max = 0;
	min = INT_MAX;
	while (i < wire->height)
	{
		j = 0;
		while (j < wire->widths[i])
		{
			if (wire->transformed[i][j].y <= min)
				min = wire->transformed[i][j].y;
			if (wire->transformed[i][j].y >= max)
				max = wire->transformed[i][j].y;
			j++;
		}
		i++;
	}
	wire->max_h = max - min;
}
