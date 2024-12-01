/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:40:13 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 14:28:54 by tobke            ###   ########.fr       */
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
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_rot_bonus(data, key);
	if (key == P)
		ft_z(&data->wirefr, 0);
	else if (key == M)
		ft_z(&data->wirefr, 1);
	ft_instructions(data->var->mlx_ptr, data->var->mlx_win);
	return (0);
}

int	keydown(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == CTRL)
		data->mouse.ctrl_down = true;
	return (0);
}
