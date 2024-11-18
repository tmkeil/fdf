/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/18 18:31:49 by tkeil            ###   ########.fr       */
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

void	ft_window_fill(t_mlx *mlx, int color)
{
	int				i;
	int				j;
	t_image_data	*img;

	img = malloc(sizeof(t_image_data));
	if (!mlx || !img)
		return ;
	img->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->linelen,
			&img->endian);
	mlx->img0 = img;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			ft_putpxl(mlx->img0, j++, i, color);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img0->img, 0, 0);
	// mlx_destroy_image(mlx->mlx_ptr, mlx->img0->img);
	// free(mlx->img0);
}

void	ft_putpxl(t_image_data *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	offset = x * (img->bpp / 8) + y * img->linelen;
	*(unsigned int *)(img->data + offset) = color;
}

int	ft_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}
