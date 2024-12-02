/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:58 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 18:10:09 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_var(t_data **data)
{
	int		w;
	int		h;
	t_mlx	**mlx;

	(*data)->var = malloc(sizeof(t_mlx));
	if (!(*data)->var)
		return (0);
	if ((*data)->wnd.wnd_w > 0)
		w = (*data)->wnd.wnd_w;
	else
		w = WIDTH;
	if ((*data)->wnd.wnd_h > 0)
		h = (*data)->wnd.wnd_h;
	else
		h = HEIGHT;
	mlx = &(*data)->var;
	(*mlx)->mlx_ptr = NULL;
	(*mlx)->mlx_win = NULL;
	(*mlx)->mlx_ptr = mlx_init();
	(*mlx)->mlx_win = mlx_new_window((*mlx)->mlx_ptr, w, h, "FdF");
	if (!(*mlx)->mlx_ptr || !(*mlx)->mlx_win)
		return (0);
	return (1);
}

static int	ft_init_wire(t_data **data)
{
	(*data)->wirefr = malloc(sizeof(t_wire));
	if (!(*data)->wirefr)
		return (0);
	(*data)->wirefr->transformed = NULL;
	(*data)->wirefr->widths = NULL;
	(*data)->wnd.wnd_h = 0;
	(*data)->wnd.wnd_w = 0;
	(*data)->mouse.ctrl_down = false;
	(*data)->mouse.mouse_down = false;
	return (1);
}

static int	ft_set_n_alloc(t_data **data, int *width, int *height)
{
	(*data)->img->buffer1 = NULL;
	(*data)->img->buffer2 = NULL;
	(*data)->img->current = NULL;
	(*data)->img->buffer1 = malloc(sizeof(t_img));
	(*data)->img->buffer2 = malloc(sizeof(t_img));
	(*data)->img->current = (*data)->img->buffer1;
	if (!(*data)->img->buffer1 || !(*data)->img->buffer2)
		return (0);
	if ((*data)->wnd.wnd_w > 0)
		*width = (*data)->wnd.wnd_w;
	else
	{
		(*data)->wnd.wnd_w = WIDTH;
		*width = WIDTH;
	}
	if ((*data)->wnd.wnd_h > 0)
		*height = (*data)->wnd.wnd_h;
	else
	{
		(*data)->wnd.wnd_h = HEIGHT;
		*height = HEIGHT;
	}
	return (1);
}

int	ft_init_imgs(t_data **data)
{
	t_img	**a;
	t_img	**b;
	int		width;
	int		height;

	(*data)->img = malloc(sizeof(t_imgs));
	if (!(*data)->img)
		return (0);
	if (!ft_set_n_alloc(&(*data), &width, &height))
		return (0);
	a = &(*data)->img->buffer1;
	b = &(*data)->img->buffer2;
	(*a)->img = mlx_new_image((*data)->var->mlx_ptr, width, height);
	(*b)->img = mlx_new_image((*data)->var->mlx_ptr, width, height);
	if (!(*a)->img || !(*b)->img)
		return (0);
	(*a)->data = mlx_get_data_addr((*a)->img, &(*a)->bpp, &(*a)->linelen,
			&(*a)->endian);
	(*b)->data = mlx_get_data_addr((*b)->img, &(*b)->bpp, &(*b)->linelen,
			&(*b)->endian);
	if (!(*a)->data || !(*b)->data)
		return (0);
	return (1);
}

int	ft_init(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	(*data)->img = NULL;
	(*data)->var = NULL;
	(*data)->wirefr = NULL;
	if (!ft_init_wire(data))
		return (ft_cleardata(*data), 0);
	if (!ft_init_var(data))
		return (ft_cleardata(*data), 0);
	if (!ft_init_imgs(data))
		return (ft_cleardata(*data), 0);
	return (1);
}
