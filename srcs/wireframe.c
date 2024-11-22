/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:56 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 15:08:00 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_data *data, t_line *line)
{
	int		e;
	t_img	*current;

	ft_lineset(line);
	while (1)
	{
		ft_putpxl(&current, line->p1->x, line->p1->y, line->p1->color);
		if (line->p1->x == line->p2->x && line->p1->y == line->p2->y)
			break ;
		e = 2 * line->error;
		if (e >= line->dy)
		{
			line->error += line->dy;
			line->p1->x += line->sx;
		}
		if (e <= line->dx)
		{
			line->error += line->dx;
			line->p1->y += line->sy;
		}
		line->p1->color = ft_interpolate(data);
	}
}

void	ft_connect_points(t_data *data, t_img **buffer, float x, float y)
{
	
}

int	ft_transfer_points(t_data **data)
{
	int		i;
	int		j;
	t_point	**tp;

	tp = &(*data)->wirefr->transformed;
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
}

int	ft_transform_points(t_data **data)
{
	ft_translate(data, WIDTH / 2, HEIGHT / 2, 0);
	ft_rotate_x(data, 35.264f);
	ft_rotate_y(data, 45.0f);
}

int	ft_wireframe(t_data **data)
{
	t_img	**buffer;

	if (!ft_transfer_points(&data))
		return (0);
	ft_transform_points(&data);
	if (!ft_set_n_paint_buffer(*data, buffer))
		return (0);
	ft_connect_points(*data, buffer, 0, 0);
	ft_put_buffer_to_window(data, buffer);
}
