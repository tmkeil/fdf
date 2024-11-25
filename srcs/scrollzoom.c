/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouseevents.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:17:35 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/25 00:43:21 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_out(t_data **data, t_wire **wire)
{
	int		i;
	int		j;
	t_img	*buffer;

	buffer = NULL;
	i = 0;
	printf("zoom out\n");
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			(*wire)->transformed[i][j].x *= (1 - 0.1);
			(*wire)->transformed[i][j].y *= (1 - 0.1);
			(*wire)->transformed[i][j].z *= (1 - 0.1);
			j++;
		}
		i++;
	}
	ft_set_n_paint_buffer(*data, &buffer);
	ft_connect_points(*data, &buffer);
	ft_put_buffer_to_window(data, &buffer);
}

void	ft_zoom_in(t_data **data, t_wire **wire)
{
	int		i;
	int		j;
	t_img	*buffer;

	buffer = NULL;
	i = 0;
	printf("zoom in\n");
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			(*wire)->transformed[i][j].x *= (1 + 0.1);
			(*wire)->transformed[i][j].y *= (1 + 0.1);
			(*wire)->transformed[i][j].z *= (1 + 0.1);
			j++;
		}
		i++;
	}
	ft_set_n_paint_buffer(*data, &buffer);
	ft_connect_points(*data, &buffer);
	ft_put_buffer_to_window(data, &buffer);
}
