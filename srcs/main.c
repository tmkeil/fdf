/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 00:26:22 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy(t_data *data)
{
	if (data)
		ft_cleardata(data);
	exit(0);
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
	mlx_hook(data->var->mlx_win, 3, 1L << 1, keyup, data);
	mlx_hook(data->var->mlx_win, 17, 0, destroy, data);
	mlx_loop(data->var->mlx_ptr);
	return (ft_cleardata(data), 0);
}
