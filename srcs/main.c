/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/28 02:41:37 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy(t_data *data)
{
	if (data)
	{
		mlx_destroy_image(data->var->mlx_ptr, data->img->current->img);
		mlx_destroy_window(data->var->mlx_ptr, data->var->mlx_win);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (argc != 2)
		return (1);
	if (argc != 2 || !*argv[1])
		return (1);
	if (!ft_init(&data))
		return (1);
	if (!ft_parsemap(&data, argv))
		return (ft_cleardata(data), 1);
	if (!ft_wire(&data))
		return (ft_cleardata(data), 1);
	mlx_hook(data->var->mlx_win, 17, 0, destroy, data);
	mlx_hook(data->var->mlx_win, 3, 1L << 1, keyup, data);
	mlx_hook(data->var->mlx_win, 4, 1L << 2, mouseclick_down, data);
	mlx_hook(data->var->mlx_win, 5, 1L << 3, mouseclick_up, data);
	mlx_hook(data->var->mlx_win, 6, 1L << 6, mousemove, data);
	mlx_loop(data->var->mlx_ptr);
	return (ft_cleardata(data), 0);
}
