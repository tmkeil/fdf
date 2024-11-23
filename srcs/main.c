/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/23 16:35:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	ft_linealloc(t_line **line)
// {
// 	(*line) = malloc(sizeof(t_line));
// 	if (!*line)
// 		return ;
// 	(*line)->p1 = malloc(sizeof(t_point));
// 	(*line)->p2 = malloc(sizeof(t_point));
// 	if (!(*line)->p1 || !(*line)->p2)
// 		return ;
// 	(*line)->p1->color = PKTCOL;
// 	(*line)->p2->color = PKTCOL;
// 	(*line)->p1->x = 500;
// 	(*line)->p2->x = 500;
// 	(*line)->p1->y = 20;
// 	(*line)->p2->y = 600;
// }

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

	data = NULL;
	if (argc != 2)
		return (1);
	if (argc != 2 || !*argv[1])
		return (1);
	if (!ft_init(&data))
		return (1);
	printf("width = %i\nwidth * 4 = %i\nlinelen = %i\n", WIDTH, 4 * WIDTH,
		data->img->current->linelen);
	if (!ft_parsemap(&data, argv))
		return (ft_cleardata(data), 1);
	if (!ft_wireframe(&data))
		return (printf("abcdefgh\n"), ft_cleardata(data), 1);
	mlx_loop(data->var->mlx_ptr);
	return (ft_cleardata(data), 0);
}
