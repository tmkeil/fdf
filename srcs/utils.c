/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 22:49:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpxl(t_img **img, int x, int y, uint32_t color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	// printf("a\n");
	if (!img || !*img || !(*img)->data)
		return ;
	// printf("b\n");
	offset = x * ((*img)->bpp / 8) + y * (*img)->linelen;
	// printf("c\n");
	*(unsigned int *)((*img)->data + offset) = color;
	// printf("d\n");
}

int	ft_set_n_paint_buffer(t_data *data, t_img **buffer)
{
	int	i;
	int	j;

	// printf("a1\n");
	if (!data->img->buffer1 || !data->img->buffer2)
		return (0);
	// printf("a2\n");
	if (data->img->current == data->img->buffer1)
		*buffer = data->img->buffer2;
	else
		*buffer = data->img->buffer1;
	// printf("a3\n");
	if (!buffer)
		return (0);
	i = 0;
	// printf("a4\n");
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			ft_putpxl(buffer, j++, i, BACKCOL);
		i++;
	}
	printf("abcdefgh\n");
	return (1);
}

void	ft_put_buffer_to_window(t_data **data, t_img **current)
{
	t_mlx	*mlx;

	mlx = (*data)->var;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, (*current)->img, 0, 0);
	(*data)->img->current = *current;
}

int	ft_drawline(t_point *p1, t_point *p2, t_img **buffer)
{
	int			e;
	t_point		*p;
	t_line_vars	*line;

	printf("draw\n");
	p = p1;
	line = NULL;
	if (!ft_lineset(&line, p1, p2))
		return (0);
	// printf("nach set\n");
	while (1)
	{
		printf("a");
		ft_putpxl(buffer, p->x, p->y, p->color);
		if (p->x <= p2->x && p->y <= p2->y)
			break ;
		e = 2 * line->error;
		if (e >= line->dy)
		{
			line->error += line->dy;
			p->x += line->sx;
		}
		if (e <= line->dx)
		{
			line->error += line->dx;
			p->y += line->sy;
		}
		// p->color = ft_interpolate(p1, p2, p);
	}
	return (1);
}
