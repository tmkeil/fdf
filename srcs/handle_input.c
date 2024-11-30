/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:40:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/30 13:02:16 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_new(t_data **data)
{
	t_img	*buffer;

	buffer = NULL;
	ft_set_n_paint_buffer(*data, &buffer);
	ft_connect_points(*data, &buffer);
	ft_put_buffer_to_window(data, &buffer);
}

int	mouseclick_down(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 5)
		ft_zoom_out(&data, &data->wirefr);
	else if (button == 4)
		ft_zoom_in(&data, &data->wirefr);
	if (button == 1)
	{
		data->mouse.mouse_down = 1;
		data->mouse.mouse_x = x;
		data->mouse.mouse_y = y;
	}
	return (0);
}

int	mouseclick_up(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 1)
		data->mouse.mouse_down = 0;
	return (0);
}

int	mousemove(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mouse.mouse_down)
	{
		if (x > data->mouse.mouse_x || x < data->mouse.mouse_x)
			ft_move(&data, x, 0);
		if (y > data->mouse.mouse_y || y < data->mouse.mouse_y)
			ft_move(&data, y, 1);
	}
	return (0);
}

int	keyup(int key, void *param)
{
	bool	stat;
	t_data	*data;

	stat = false;
	data = (t_data *)param;
	if (key == ESC || !data)
		destroy(data);
	else if (key == W || key == UP)
	{
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_x);
		stat = true;
	}
	else if (key == A || key == LEFT)
	{
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_y);
		stat = true;
	}
	else if (key == D || key == RIGHT)
	{
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_z);
		stat = true;
	}
	if (stat)
		ft_draw_new(&data);
	return (0);
}
