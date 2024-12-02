/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:49 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 19:53:58 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_mand(t_data *data)
{
	if (data)
		ft_cleardata(data);
	exit(0);
}

int	keyup_mand(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC || !data)
		destroy_mand(data);
	if (key == P)
	{
		if (!ft_wnd_resize_mand(&data, 100))
			return (ft_cleardata(data), 0);
	}
	else if (key == M)
	{
		if (!ft_wnd_resize_mand(&data, -100))
			return (ft_cleardata(data), 0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (argc != 2 || !*argv[1])
		return (1);
	if (!ft_init(&data))
		return (1);
	if (!ft_parsemap(&data, argv))
		return (ft_cleardata(data), 1);
	if (!ft_wire(data))
		return (ft_cleardata(data), 1);
	mlx_hook(data->var->mlx_win, 3, 1L << 1, keyup_mand, data);
	mlx_hook(data->var->mlx_win, 17, 0, destroy_mand, data);
	mlx_loop(data->var->mlx_ptr);
	return (ft_cleardata(data), 0);
}
