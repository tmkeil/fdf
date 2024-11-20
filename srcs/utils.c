/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/20 18:13:12 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_current(t_data *data, t_img **current)
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

void	ft_putpxl(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	offset = x * (img->bpp / 8) + y * img->linelen;
	*(unsigned int *)(img->data + offset) = color;
}

void	ft_paint_buffer(t_mlx *mlx, t_img *buffer, int color)
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

void	ft_put_buffer_to_window(t_data *data, t_img *current)
{
	t_mlx	*mlx;

	mlx = data->var;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, current->img, 0, 0);
	data->img->current = current;
}
