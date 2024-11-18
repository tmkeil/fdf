/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/17 22:56:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpxl(t_image_data *img, int x, int y, int color)
{
	int	offset;

	offset = x * (img->bpp / 8) + y * img->linelen;
	*(unsigned int *)(img->data + offset) = color;
}

void	ft_fill(t_mlx *mlx, int x, int y, int color)
{
	int				i;
	int				j;
	t_image_data	*img;

	img = malloc(sizeof(t_image_data));
	if (!img)
		return ;
	img->img = mlx_new_image(mlx->mlx_ptr, x, y);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->linelen,
			&img->endian);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putpxl(img, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, img->img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img->img);
	free(img);
}

int	main(void)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (1);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (free(mlx), 1);
	x = 1000;
	y = 1000;
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, x, y, "Hello world!");
	if (!mlx->mlx_win)
		return (free(mlx), 1);
	ft_fill(mlx, x, y, 0xFF0000);
	mlx_loop(mlx);
	free(mlx);
}
