/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/20 18:13:31 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_data *data, t_line *line)
{
	int		e;
	t_img	*current;

	current = NULL;
	ft_arrangeline(line);
	ft_set_current(data, &current);
	ft_paint_buffer(data->var, current, BACKCOL);
	while (1)
	{
		ft_putpxl(current, line->p1->x, line->p1->y, line->p1->color);
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
	}
	ft_put_buffer_to_window(data, current);
}

void	ft_linealloc(t_line **line)
{
	(*line) = malloc(sizeof(t_line));
	if (!*line)
		return ;
	(*line)->p1 = malloc(sizeof(t_point));
	(*line)->p2 = malloc(sizeof(t_point));
	if (!(*line)->p1 || !(*line)->p2)
		return ;
	(*line)->p1->color = PKTCOL;
	(*line)->p2->color = PKTCOL;
	(*line)->p1->x = 20;
	(*line)->p2->x = 600;
	(*line)->p1->y = 20;
	(*line)->p2->y = 600;
}

// void	ft_print(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	printf("height of the map: %i\n", map->height);
// 	while (i < map->height)
// 	{
// 		printf("Reihe %i. Width = %i\n", i + 1, map->widths[i]);
// 		j = 0;
// 		while (j < map->widths[i])
// 		{
// 			printf("x = %i, z = %i\n", j, map->profile[i][j]);
// 			printf("color = %i\n", map->colors[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_map	*map;
	t_line	*line;

	data = NULL;
	map = NULL;
	if (argc < 2 && argc != 4)
		return (1);
	if (argc != 2 || !*argv[1])
		return (1);
	if (!ft_parsemap(&map, argv))
		return (ft_clearmap(map), 1);
	if (!ft_init(&data))
		return (ft_clearmap(map), ft_cleardata(data), 1);
	ft_linealloc(&line);
	ft_drawline(data, line);
	// ft_print(map);
	ft_put_buffer_to_window(data, data->img->current);
	// ft_wireframe(data, map);
	mlx_loop(data->var->mlx_ptr);
	return (ft_clearmap(map), ft_cleardata(data), 0);
}

// int	main(void)
// {
// 	t_data	*data;
// 	t_line	*line;

// 	data = NULL;
// 	if (!ft_init(&data))
// 		return (1);
// 	ft_linealloc(&line);
// 	ft_drawline(data, line);
// 	ft_put_buffer_to_window(data, data->img->current);
// 	mlx_loop(data->var->mlx_ptr);
// 	free(data->var);
// }
