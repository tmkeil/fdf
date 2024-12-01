/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:12:51 by tobke             #+#    #+#             */
/*   Updated: 2024/12/01 13:30:09 by tobke            ###   ########.fr       */
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

void	ft_rot_bonus(t_data *data, int key)
{
	if (key == UP)
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_y);
	else if (key == DOWN)
		ft_rotate(&data->wirefr, -2.0f, ft_rotate_y);
	if (!data->mouse.ctrl_down && key == LEFT)
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_x);
	else if (!data->mouse.ctrl_down && key == RIGHT)
		ft_rotate(&data->wirefr, -2.0f, ft_rotate_x);
	if (data->mouse.ctrl_down && key == LEFT)
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_z);
	else if (data->mouse.ctrl_down && key == RIGHT)
		ft_rotate(&data->wirefr, -2.0f, ft_rotate_z);
    ft_draw_new(&data);
}
