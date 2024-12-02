/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 13:27:27 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	destroy_mand(t_data *data)
{
	if (data)
		ft_cleardata(data);
	exit(0);
}

static int	keyup_mand(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC || !data)
		destroy_mand(data);
	if (key == PLUS)
	{
		if (!ft_wnd_resize(data, 100))
			return (ft_cleardata(data), 0);
	}
	else if (key == MINUS)
	{
		if (!ft_wnd_resize(data, -100))
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
	if (!ft_wire(&data))
		return (ft_cleardata(data), 1);
	mlx_hook(data->var->mlx_win, 3, 1L << 1, keyup_mand, data);
	mlx_hook(data->var->mlx_win, 17, 0, destroy_mand, data);
	mlx_loop(data->var->mlx_ptr);
	return (ft_cleardata(data), 0);
}
