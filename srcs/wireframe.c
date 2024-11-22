/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:56 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 22:50:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_connect_points(t_data *data, t_img **buffer, int x, int y)
{
	t_point	**tp;
	int		i;

	tp = data->wirefr->transformed;
	if (y >= data->map->height || x >= data->map->widths[y])
		return ;
	i = 0;
	while (i < data->map->widths[0] - 10)
	{
		printf("draw line from x = %f, y = %f, z = %f\n", tp[x + i][y].x, tp[x + i][y].y, tp[x + i][y].z);
		printf("to x = %f, y = %f, z = %f\n", tp[x + (i + 1)][y].x, tp[x + (i + 1)][y].y, tp[x + (i + 1)][y].z);
		printf("test\n");
		ft_drawline(&tp[0][x + i], &tp[0][x + (i + 1)], buffer);
		i++;
	}
	// ft_connect_points();
	// ft_connect_points();
	// ft_connect_points();
	// ft_connect_points();
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

void	ft_print(t_point **map, t_map *v)
{
	int	i;
	int	j;

	i = 0;
	printf("height of the map abc: %i\n", v->height);
	while (i < v->height)
	{
		printf("Reihe %i. Width = %i\n", i + 1, v->widths[i]);
		j = 0;
		while (j < v->widths[i])
		{
			printf("x = %f, y = %f, z = %f\n", map[i][j].x, map[i][j].y, map[i][j].z);
			printf("color = %i\n", map[i][j].color);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_transform_points(t_data **data)
{
	ft_translate(data, WIDTH / 2, HEIGHT / 2, 0);
	ft_rotate(data, 35.264f, ft_rotate_x);
	ft_rotate(data, 45.0f, ft_rotate_y);
}

int	ft_wireframe(t_data **data)
{
	t_img	*buffer;

	buffer = NULL;
	if (!ft_transfer_points(data))
		return (0);
	// printf("b1\n");
	ft_transform_points(data);
		printf("\n");
	ft_print((*data)->wirefr->transformed, (*data)->map);
	printf("\n");
	if (!ft_set_n_paint_buffer(*data, &buffer))
		return (0);
	ft_connect_points(*data, &buffer, 0, 0);
	return (ft_put_buffer_to_window(data, &buffer), 1);
}
