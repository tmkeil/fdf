/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:39 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 18:05:26 by tkeil            ###   ########.fr       */
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
	while (i < data->wnd.wnd_h)
	{
		j = 0;
		while (j < data->wnd.wnd_w)
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

