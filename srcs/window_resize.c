/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:04 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 19:54:57 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_reset_wnd(t_data **data, int w, int h)
{
	ft_clear_images(&(*data)->img, (*data)->var->mlx_ptr);
	if ((*data)->var->mlx_win)
	{
		mlx_destroy_window((*data)->var->mlx_ptr, (*data)->var->mlx_win);
		(*data)->var->mlx_win = NULL;
	}
	(*data)->var->mlx_win = mlx_new_window((*data)->var->mlx_ptr, w, h, "FdF");
	if (!(*data)->var->mlx_win)
		return (0);
	if (!ft_init_imgs(data))
		return (0);
	return (1);
}

int	ft_wnd_resize_mand(t_data **data, int size)
{
	t_img	*buffer;

	if (((*data)->wnd.wnd_w < 750 || (*data)->wnd.wnd_h < 750) && size <= 0)
		return (1);
	if (((*data)->wnd.wnd_w >= 1920 || (*data)->wnd.wnd_h >= 1280) && size >= 0)
		return (1);
	buffer = NULL;
	(*data)->wnd.wnd_h += size;
	(*data)->wnd.wnd_w += size;
	ft_reset_wnd(data, (*data)->wnd.wnd_w, (*data)->wnd.wnd_h);
	if (!ft_set_n_paint_buffer(*data, &buffer))
		return (0);
	ft_connect_points(*data, &buffer);
	mlx_hook((*data)->var->mlx_win, 3, 1L << 1, keyup_mand, *data);
	mlx_hook((*data)->var->mlx_win, 17, 0, destroy_mand, *data);
	return (ft_put_buffer_to_window(data, &buffer), 1);
}
