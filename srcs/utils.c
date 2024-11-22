/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:10 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 15:16:19 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpxl(t_img **img, int x, int y, uint32_t color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	if (!img || !*img || !(*img)->data)
		return ;
	offset = x * ((*img)->bpp / 8) + y * (*img)->linelen;
	*(unsigned int *)((*img)->data + offset) = color;
}

int	ft_set_n_paint_buffer(t_data *data, t_img **buffer)
{
	int	i;
	int	j;

	if (!data->img->buffer1 || !data->img->buffer2)
		return (0);
	if (data->img->current == data->img->buffer1)
		*buffer = data->img->buffer2;
	else
		*buffer = data->img->buffer1;
	if (!buffer || !*buffer || !(*buffer)->data)
		return (0);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			ft_putpxl(buffer, j++, i, BACKCOL);
		i++;
	}
}

void	ft_put_buffer_to_window(t_data **data, t_img **current)
{
	t_mlx	*mlx;

	mlx = (*data)->var;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, (*current)->img, 0, 0);
	(*data)->img->current = *current;
}
