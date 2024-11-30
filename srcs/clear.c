/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:32 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 00:25:54 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clrptr(void **ptr)
{
	int	i;

	if (!ptr || !*ptr)
		return ;
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	ft_clear_wireframe(t_wire *wirefr)
{
	int	i;

	i = 0;
	if (wirefr->transformed)
	{
		while (i < wirefr->height)
		{
			if (wirefr->transformed[i])
				free(wirefr->transformed[i]);
			i++;
		}
		free(wirefr->transformed);
	}
	if (wirefr->widths)
		free(wirefr->widths);
	free(wirefr);
}

static void	ft_clear_images(t_imgs *imgs, void *mlx_ptr)
{
	if (imgs->current)
	{
		if (imgs->current == imgs->buffer1)
			imgs->buffer1 = NULL;
		else if (imgs->current == imgs->buffer2)
			imgs->buffer2 = NULL;
		if (imgs->current->data)
			mlx_destroy_image(mlx_ptr, imgs->current->img);
		free(imgs->current);
	}
	if (imgs->buffer1)
	{
		if (imgs->buffer1->data)
			mlx_destroy_image(mlx_ptr, imgs->buffer1->img);
		free(imgs->buffer1);
	}
	if (imgs->buffer2)
	{
		if (imgs->buffer2->data)
			mlx_destroy_image(mlx_ptr, imgs->buffer2->img);
		free(imgs->buffer2);
	}
	free(imgs);
}

void	ft_clear_mlx(t_data *data)
{
	if (data && data->var)
	{
		if (data->var->mlx_win)
			mlx_destroy_window(data->var->mlx_ptr, data->var->mlx_win);
		free(data->var);
	}
}

void	ft_cleardata(t_data *data)
{
	if (data)
	{
		if (data->img)
			ft_clear_images(data->img, data->var->mlx_ptr);
		if (data->wirefr)
			ft_clear_wireframe(data->wirefr);
		ft_clear_mlx(data);
		free(data);
	}
}
