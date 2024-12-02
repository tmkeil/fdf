/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:54 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 19:50:15 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_instructions(void *ptr, void *win)
{
	mlx_string_put(ptr, win, 0, 20, WHITE, "move: drag and drop");
	mlx_string_put(ptr, win, 0, 40, WHITE, "rotate x: w/s");
	mlx_string_put(ptr, win, 0, 60, WHITE, "rotate y: a/d");
	mlx_string_put(ptr, win, 0, 80, WHITE, "rotate z: CTRL + a/d");
	mlx_string_put(ptr, win, 0, 100, WHITE, "zoom: scroll");
	mlx_string_put(ptr, win, 0, 120, WHITE, "resize wnd: p/m");
}

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
	if (argc != 2 || !*argv[1])
		return (1);
	if (!ft_init(&data))
		return (1);
	if (!ft_parsemap(&data, argv))
		return (ft_cleardata(data), 1);
	if (!ft_wire(data))
		return (ft_cleardata(data), 1);
	mlx_hook(data->var->mlx_win, 17, 0, destroy, data);
	mlx_hook(data->var->mlx_win, 2, 1L << 0, keydown, data);
	mlx_hook(data->var->mlx_win, 3, 1L << 1, keyup, data);
	mlx_hook(data->var->mlx_win, 4, 1L << 2, mouse_down, data);
	mlx_hook(data->var->mlx_win, 5, 1L << 3, mouse_up, data);
	mlx_hook(data->var->mlx_win, 6, 1L << 6, mousemove, data);
	ft_instructions(data->var->mlx_ptr, data->var->mlx_win);
	mlx_loop(data->var->mlx_ptr);
	return (ft_cleardata(data), 0);
}
