/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:56 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/23 22:06:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_connect_points(t_data *data, t_img **buffer)
{
	t_point	**tp;
	int		x;
	int		y;

	tp = data->wirefr->transformed;
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->widths[y])
		{
			if (x + 1 < data->map->widths[y])
				ft_drawline(&tp[y][x], &tp[y][x + 1], buffer);
			if (y + 1 < data->map->height && x < data->map->widths[y + 1])
				ft_drawline(&tp[y][x], &tp[y + 1][x], buffer);
			x++;
		}
		y++;
	}
}

int	ft_transfer_points(t_data **data)
{
	int		i;
	int		j;
	t_point	**tp;

	tp = malloc(sizeof(t_point *) * (*data)->map->height);
	if (!tp)
		return (0);
	i = 0;
	while (i < (*data)->map->height)
	{
		j = 0;
		tp[i] = malloc(sizeof(t_point) * (*data)->map->widths[i]);
		if (!tp[i])
			return (0);
		while (j < (*data)->map->widths[i])
		{
			tp[i][j].x = (float)j;
			tp[i][j].y = (float)i;
			tp[i][j].z = (float)(*data)->map->profile[i][j];
			tp[i][j].color = (*data)->map->colors[i][j];
			j++;
		}
		i++;
	}
	return ((*data)->wirefr->transformed = tp, 1);
}

void	ft_transform_points(t_data **data)
{
	int		i;
	int		j;
	t_point	**ordinates;

	i = 0;
	ordinates = (*data)->wirefr->transformed;
	while (i < (*data)->map->height)
	{
		j = 0;
		while (j < (*data)->map->widths[i])
		{
			ft_scale(&ordinates[i][j], 30);
			ft_rotate(&ordinates[i][j], 30.0f, ft_project_isometric);
			ft_translate(&ordinates[i][j], WIDTH / 2, HEIGHT / 2);
			j++;
		}
		i++;
	}
}

int	ft_wireframe(t_data **data)
{
	t_img	*buffer;

	buffer = NULL;
	if (!ft_transfer_points(data))
		return (0);
	ft_transform_points(data);
	if (!ft_set_n_paint_buffer(*data, &buffer))
		return (0);
	ft_connect_points(*data, &buffer);
	return (ft_put_buffer_to_window(data, &buffer), 1);
}
