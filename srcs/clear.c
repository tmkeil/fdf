/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:32 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/28 03:46:10 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_images(t_imgs *imgs)
{
	if (imgs)
	{
		if (imgs->current)
		{
			if (imgs->current->data)
				free(imgs->current->data);
			free(imgs->current);
		}
		if (imgs->buffer1)
		{
			if (imgs->buffer1->data)
				free(imgs->buffer1->data);
			free(imgs->buffer1);
		}
		if (imgs->buffer2)
		{
			if (imgs->buffer2->data)
				free(imgs->buffer2->data);
			free(imgs->buffer2);
		}
		free(imgs);
	}
}

void	ft_clear_wireframe(t_wire *wirefr)
{
	int	i;

	i = 0;
	if (wirefr)
	{
		if (wirefr->transformed)
		{
			while (i < wirefr->height)
				free(wirefr->transformed[i++]);
			free(wirefr->transformed);
		}
		if (wirefr->widths)
			free(wirefr->widths);
		free(wirefr);
	}
}

void	ft_clear_mlx(t_mlx *var)
{
	if (var)
	{
		if (var->mlx_win)
			mlx_destroy_window(var->mlx_ptr, var->mlx_win);
		free(var);
	}
}

void	ft_cleardata(t_data *data)
{
	if (data)
	{
		ft_clear_mlx(data->var);
		ft_clear_images(data->img);
		ft_clear_wireframe(data->wirefr);
		free(data);
	}
}
