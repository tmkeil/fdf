/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/19 20:33:49 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_current(t_data *data, t_image_data **current)
{
	if (data->img->current == data->img->buffer1)
		*current = data->img->buffer2;
	else
		*current = data->img->buffer1;
}

void	ft_arrangeline(t_line *line)
{
	line->dx = ft_abs(line->p2->x - line->p1->x);
	line->dy = -(ft_abs(line->p2->y - line->p1->y));
	line->sx = (line->p1->x < line->p2->x) - (line->p1->x >= line->p2->x);
	line->sy = (line->p1->y < line->p2->y) - (line->p1->y >= line->p2->y);
	line->error = line->dx + line->dy;
}

void	ft_putpxl(t_image_data *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	offset = x * (img->bpp / 8) + y * img->linelen;
	*(unsigned int *)(img->data + offset) = color;
}

void	ft_paint_buffer(t_mlx *mlx, t_image_data *buffer, int color)
{
	int	i;
	int	j;

	if (!buffer || !buffer->img)
		return ;
	buffer->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	buffer->data = mlx_get_data_addr(buffer->img, &buffer->bpp,
			&buffer->linelen, &buffer->endian);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			ft_putpxl(buffer, j++, i, color);
		i++;
	}
}

int	ft_map_height(int fd)
{
	int	height;

	height = 0;
	while (get_next_line(fd))
		height++;
	return (height);
}
