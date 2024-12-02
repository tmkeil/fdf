/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:51 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 19:22:37 by tkeil            ###   ########.fr       */
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

static void	ft_move_back(t_wire **wire, float x, float y)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*wire)->transformed;
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			ft_translate(&p[i][j], x, y);
			j++;
		}
		i++;
	}
}

void	ft_rot_bonus(t_data *data, int key)
{
	float	x;
	float	y;

	x = data->wirefr->avg_w;
	y = data->wirefr->avg_h;
	if (key == W)
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_y);
	else if (key == S)
		ft_rotate(&data->wirefr, -2.0f, ft_rotate_y);
	if (!data->mouse.ctrl_down && key == A)
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_x);
	else if (!data->mouse.ctrl_down && key == D)
		ft_rotate(&data->wirefr, -2.0f, ft_rotate_x);
	if (data->mouse.ctrl_down && key == A)
		ft_rotate(&data->wirefr, 2.0f, ft_rotate_z);
	else if (data->mouse.ctrl_down && key == D)
		ft_rotate(&data->wirefr, -2.0f, ft_rotate_z);
	ft_move_back(&data->wirefr, x, y);
	ft_middle(&data->wirefr);
	ft_draw_new(&data);
}
