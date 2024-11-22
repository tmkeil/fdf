/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:14:22 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 16:11:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_init_var(t_data **data)
{
	t_mlx	**mlx;

	mlx = &(*data)->var;
	(*data)->var = malloc(sizeof(t_mlx));
	if (!(*data)->var)
		return (0);
	(*mlx)->mlx_ptr = mlx_init();
	(*mlx)->mlx_win = mlx_new_window((*mlx)->mlx_ptr, WIDTH, HEIGHT, "tkeil");
	if (!(*mlx)->mlx_ptr || !(*mlx)->mlx_win)
		return (0);
	return (1);
}

static int	ft_init_imgs(t_data **data)
{
	t_img	**a;
	t_img	**b;

	(*data)->img = malloc(sizeof(t_imgs));
	if (!(*data)->img)
		return (0);
	(*data)->img->buffer1 = malloc(sizeof(t_img));
	(*data)->img->buffer2 = malloc(sizeof(t_img));
	if (!(*data)->img->buffer1 || !(*data)->img->buffer2)
		return (0);
	(*data)->img->current = (*data)->img->buffer1;
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
	(*data)->img->current = (*a);
	return (1);
}

static int	ft_init_map(t_data **data)
{
	(*data)->map = malloc(sizeof(t_map));
	if (!(*data)->map)
		return (0);
	return (1);
}

static int	ft_init_wireframe(t_data **data)
{
	t_wireframe	**wire;

	wire = &(*data)->wirefr;
	*wire = malloc(sizeof(t_wireframe));
	if (!*wire)
		return (0);
	return (1);
}

int	ft_init(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	if (!ft_init_var(data))
		return (ft_cleardata(*data), 0);
	if (!ft_init_imgs(data))
		return (ft_cleardata(*data), 0);
	if (!ft_init_map(data))
		return (ft_cleardata(*data), 0);
	if (!ft_init_wireframe(data))
		return (ft_cleardata(*data), 0);
	return (1);
}
