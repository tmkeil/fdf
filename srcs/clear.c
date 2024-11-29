/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:32 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/29 12:40:58 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clrptr(void **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

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

void	ft_clear_mlx(t_data *data)
{
    if (data && data->var)
    {
        if (data->img && data->img->current && data->img->current->img)
        {
            mlx_destroy_image(data->var->mlx_ptr, data->img->current->img);
            data->img->current->img = NULL;
        }
        if (data->var->mlx_win)
            mlx_destroy_window(data->var->mlx_ptr, data->var->mlx_win);
        free(data->var);
    }
}

void	ft_cleardata(t_data *data)
{
	if (data)
	{
		ft_clear_mlx(data);
		ft_clear_images(data->img);
		ft_clear_wireframe(data->wirefr);
		free(data);
	}
}
