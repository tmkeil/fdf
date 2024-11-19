/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/18 22:42:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_mlx *mlx, t_line *line)
{
	int	e;

	ft_arrangeline(line);
	ft_window_fill(mlx, BACKCOL);
	while (1)
	{
		ft_putpxl(mlx->img0, line->p1->x, line->p1->y, line->p1->color);
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

// int	main(void)
// {
// 	t_mlx			*mlx;
// 	t_line			*line;
// 	t_image_data	*img;

// 	mlx = malloc(sizeof(t_mlx));
// 	img = malloc(sizeof(t_image_data));
// 	if (!mlx || !img)
// 		return (1);
// 	mlx->mlx_ptr = mlx_init();
// 	if (!mlx->mlx_ptr)
// 		return (free(mlx), 1);
// 	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Hello world!");
// 	img->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
// 	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->linelen,
// 			&img->endian);
// 	if (!mlx->mlx_win)
// 		return (free(mlx), 1);
// 	ft_linealloc(&line);
// 	mlx->img0 = img;
// 	ft_drawline(mlx, line);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img0->img, 0, 0);
// 	mlx_loop(mlx);
// 	free(mlx);
// }

int	ft_prep_mlx(t_mlx *mlx)
{
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (free(mlx), 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	t_map	*map;

	if (argc != 2 || !*argv[1])
		return (1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	if (!ft_parsemap(map, argv[1]))
		return (1);
	if (!ft_valid_input(map))
		return (ft_clear(map), 1);
	if (!ft_prep_mlx(mlx))
		return (ft_clear(map), 1);
	ft_wireframe(mlx, map);
	mlx_loop(mlx);
	return (ft_clear(map), free(mlx), 0);
}
