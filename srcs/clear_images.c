/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:00:34 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 18:02:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_clear_single_image(t_img *img, void *mlx_ptr)
{
	if (img)
	{
		if (img->data)
		{
			mlx_destroy_image(mlx_ptr, img->img);
			img->img = NULL;
			img->data = NULL;
		}
		free(img);
	}
}

static void	ft_clear_current_image(t_imgs **imgs, void *mlx_ptr)
{
	if ((*imgs)->current)
	{
		if ((*imgs)->current == (*imgs)->buffer1)
			(*imgs)->buffer1 = NULL;
		else if ((*imgs)->current == (*imgs)->buffer2)
			(*imgs)->buffer2 = NULL;
		ft_clear_single_image((*imgs)->current, mlx_ptr);
		(*imgs)->current = NULL;
	}
}

static void	ft_clear_buffer_images(t_imgs **imgs, void *mlx_ptr)
{
	if ((*imgs)->buffer1)
	{
		ft_clear_single_image((*imgs)->buffer1, mlx_ptr);
		(*imgs)->buffer1 = NULL;
	}
	if ((*imgs)->buffer2)
	{
		ft_clear_single_image((*imgs)->buffer2, mlx_ptr);
		(*imgs)->buffer2 = NULL;
	}
}

void	ft_clear_images(t_imgs **imgs, void *mlx_ptr)
{
	if (!imgs || !*imgs)
		return ;
	ft_clear_current_image(imgs, mlx_ptr);
	ft_clear_buffer_images(imgs, mlx_ptr);
	free(*imgs);
	*imgs = NULL;
}
