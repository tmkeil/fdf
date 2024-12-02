/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:16 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 18:47:51 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_data *d, t_point *p1, t_point *p2, t_img **buf)
{
	t_point		cur;
	t_line_vars	line;
	int			len;

	cur.x = p1->x;
	cur.y = p1->y;
	cur.color = p1->color;
	ft_set_line(&line, p1, p2, &len);
	while (len--)
	{
		if (cur.x < 0 || cur.y < 0)
			return ;
		if (cur.x >= d->wnd.wnd_w || cur.y >= d->wnd.wnd_h)
			return ;
		ft_putpxl(buf, cur.x, cur.y, cur.color);
		cur.x += line.sx;
		cur.y += line.sy;
		cur.color = ft_interpol_color(p1, p2, line.len - len, line.len);
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
				ft_drawline(data, &tp[y][x], &tp[y][x + 1], buffer);
			if (y + 1 < data->wirefr->height && x < data->wirefr->widths[y + 1])
				ft_drawline(data, &tp[y][x], &tp[y + 1][x], buffer);
			x++;
		}
		y++;
	}
}

void	ft_transform_points(t_wire **wire, int w, int h)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*wire)->transformed;
	ft_autoscale(wire, 0.5, WIDTH / 12);
	ft_rotate(wire, 30.0f, ft_project_isometric);
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			ft_translate(&p[i][j], w / 2, h / 2);
			j++;
		}
		i++;
	}
	ft_middle(wire);
}

int	ft_wire(t_data *data)
{
	t_img	*buffer;

	buffer = NULL;
	ft_transform_points(&data->wirefr, data->wnd.wnd_w, data->wnd.wnd_h);
	if (!ft_set_n_paint_buffer(data, &buffer))
		return (0);
	ft_connect_points(data, &buffer);
	return (ft_put_buffer_to_window(&data, &buffer), 1);
}
