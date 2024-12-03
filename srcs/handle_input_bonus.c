/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:46:03 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/03 12:41:06 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_down(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 5)
		ft_zoom_out(&data, &data->wirefr);
	else if (button == 4)
		ft_zoom_in(&data, &data->wirefr);
	if (button == 1)
	{
		data->mouse.mouse_down = true;
		data->mouse.mouse_x = x;
		data->mouse.mouse_y = y;
	}
	ft_instructions(data->var->mlx_ptr, data->var->mlx_win);
	return (0);
}

int	mouse_up(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 1)
		data->mouse.mouse_down = false;
	return (0);
}

int	mousemove(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mouse.mouse_down)
	{
		if (x > data->mouse.mouse_x || x < data->mouse.mouse_x)
			ft_move_x(&data, x);
		if (y > data->mouse.mouse_y || y < data->mouse.mouse_y)
			ft_move_y(&data, y);
		ft_instructions(data->var->mlx_ptr, data->var->mlx_win);
	}
	return (0);
}

int	keyup(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC || !data)
		destroy(data);
	if (key == CTRL)
		data->mouse.ctrl_down = false;
	if (!data->mouse.ctrl_down && key == P)
	{
		if (!ft_wnd_resize_bonus(&data, 100))
			return (ft_cleardata(data), 0);
	}
	else if (!data->mouse.ctrl_down && key == M)
	{
		if (!ft_wnd_resize_bonus(&data, -100))
			return (ft_cleardata(data), 0);
	}
	ft_instructions(data->var->mlx_ptr, data->var->mlx_win);
	return (0);
}

int	keydown(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == CTRL)
		data->mouse.ctrl_down = true;
	if (key == W || key == S || key == A || key == D)
		ft_rot_bonus(data, key);
	return (0);
}
