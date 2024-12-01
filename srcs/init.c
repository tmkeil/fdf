/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:14:22 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 15:47:26 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_init_var(t_data **data)
{
	t_mlx	**mlx;

	(*data)->var = malloc(sizeof(t_mlx));
	if (!(*data)->var)
		return (0);
	mlx = &(*data)->var;
	(*mlx)->mlx_ptr = NULL;
	(*mlx)->mlx_win = NULL;
	(*mlx)->mlx_ptr = mlx_init();
	(*mlx)->mlx_win = mlx_new_window((*mlx)->mlx_ptr, WIDTH, HEIGHT, "fdf");
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
	return (1);
}

static void	ft_setnull(t_imgs **imgs)
{
	(*imgs)->buffer1 = NULL;
	(*imgs)->buffer2 = NULL;
	(*imgs)->current = NULL;
}

static int	ft_init_imgs(t_data **data)
{
	t_img	**a;
	t_img	**b;

	(*data)->img = malloc(sizeof(t_imgs));
	if (!(*data)->img)
		return (0);
	ft_setnull(&(*data)->img);
	(*data)->img->buffer1 = malloc(sizeof(t_img));
	(*data)->img->buffer2 = malloc(sizeof(t_img));
	(*data)->img->current = (*data)->img->buffer1;
	if (!(*data)->img->buffer1 || !(*data)->img->buffer2)
		return (0);
	a = &(*data)->img->buffer1;
	b = &(*data)->img->buffer2;
	(*a)->img = mlx_new_image((*data)->var->mlx_ptr, WIDTH, HEIGHT);
	(*b)->img = mlx_new_image((*data)->var->mlx_ptr, WIDTH, HEIGHT);
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
	if (!ft_init_var(data))
		return (ft_cleardata(*data), 0);
	if (!ft_init_imgs(data))
		return (ft_cleardata(*data), 0);
	if (!ft_init_wire(data))
		return (ft_cleardata(*data), 0);
	return (1);
}
