/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/19 18:14:41 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int value)
{
	return ((((value) * ((value) >= 0)) - ((value) * ((value) < 0))));
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

int	ft_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}
