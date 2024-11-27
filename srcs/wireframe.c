/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:56 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/27 13:16:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_point *p1, t_point *p2, t_img **buffer)
{
	t_point		current;
	t_line_vars	line;

	current.x = p1->x;
	current.y = p1->y;
	current.color = p1->color;
	ft_set_line(&line, p1, p2);
	while (1)
	{
		ft_putpxl(buffer, current.x, current.y, current.color);
		if (current.x == p2->x && current.y == p2->y)
			break ;
		ft_update_current(&current.x, &current.y, &line);
		current.color = ft_interpol_color(p1, p2, current);
	}
}

void	ft_connect_points(t_data *data, t_img **buffer)
{
	t_point	**tp;
	int		x;
	int		y;

	tp = data->wirefr->transformed;
	y = 0;
	while (y < data->wirefr->height)
	{
		x = 0;
		while (x < data->wirefr->widths[y])
		{
			if (x + 1 < data->wirefr->widths[y])
				ft_drawline(&tp[y][x], &tp[y][x + 1], buffer);
			if (y + 1 < data->wirefr->height && x < data->wirefr->widths[y + 1])
				ft_drawline(&tp[y][x], &tp[y + 1][x], buffer);
			
			x++;
		}
		y++;
	}
}

// void	ft_transform_points(t_wire **wire)
// {
// 	int		i;
// 	int		j;
// 	t_point	**p;

// 	i = 0;
// 	p = (*wire)->transformed;
// 	while (i < (*wire)->height)
// 	{
// 		j = 0;
// 		while (j < (*wire)->widths[i])
// 		{
// 			ft_scale(*wire, &p[i][j], 0.5, 400);
// 			ft_translate(&p[i][j], -(*wire)->max_w, -(*wire)->height);
			
// 			ft_rotate(&p[i][j], 30.0f, ft_project_isometric);
// 			ft_translate(&p[i][j], WIDTH, HEIGHT);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	ft_transform_points(t_wire **wire)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*wire)->transformed;
	ft_scale(wire, 0.5, 400);
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			ft_translate(&p[i][j], -(*wire)->max_w / 2, -(*wire)->height / 2);
			ft_rotate(&p[i][j], 30.0f, ft_project_isometric);
			ft_avg_height(wire);
			ft_avg_width(wire);
			ft_translate(&p[i][j], (*wire)->max_w / 2, (*wire)->height / 2);
			ft_translate(&p[i][j], (*wire)->avg_width / 2, (*wire)->avg_height/ 2);
			j++;
		}
		i++;
	}
}

int	ft_wire(t_data **data)
{
	t_img	*buffer;

	buffer = NULL;
	ft_transform_points(&(*data)->wirefr);
	if (!ft_set_n_paint_buffer(*data, &buffer))
		return (0);
	ft_connect_points(*data, &buffer);
	return (ft_put_buffer_to_window(data, &buffer), 1);
}
