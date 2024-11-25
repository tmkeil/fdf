/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:50:50 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/25 03:52:56 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	destroy(t_data *data)
// {
// 	if (data)
// 	{
// 		mlx_destroy_image(data->var->mlx_ptr, data->img->current->img);
// 		mlx_destroy_window(data->var->mlx_ptr, data->var->mlx_win);
// 		// mlx_destroy_display(data->var->mlx_ptr);
// 	}
// 	return (0);
// }

// int	mouseclick_down(int button, int x, int y, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (button == 5)
// 		ft_zoom_out(&data, &data->wirefr);
// 	else if (button == 4)
// 		ft_zoom_in(&data, &data->wirefr);
// 	if (button == 1)
// 	{
// 		data->mouse.mouse_down = 1;
// 		data->mouse.mouse_x = x;
// 		data->mouse.mouse_y = y;
// 	}
// 	return (0);
// }

// int	mouseclick_up(int button, int x, int y, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (button == 1)
// 		data->mouse.mouse_down = 0;
// 	return (0);
// }

// int	mousemove(int x, int y, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (data->mouse.mouse_down)
// 	{
// 		if (x > data->mouse.mouse_x)
// 		{
// 			ft_move_right(&data, &data->wirefr);
// 			data->mouse.mouse_x = x;
// 		}
// 		else if (x < data->mouse.mouse_x)
// 		{
// 			ft_move_left(&data, &data->wirefr);
// 			data->mouse.mouse_y = y;
// 		}
// 		if (x > data->mouse.mouse_x)
// 		{
// 			ft_move_up(&data, &data->wirefr);
// 			data->mouse.mouse_x = x;
// 		}
// 		else if (x < data->mouse.mouse_x)
// 		{
// 			ft_move_down(&data, &data->wirefr);
// 			data->mouse.mouse_y = y;
// 		}
// 	}
// 	return (0);
// }

// int	keyup(int key, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (key == ESC || !data)
// 		destroy(data);
// 	printf("keyup: %i\n", key);
// 	return (0);
// }

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
	// mlx_hook(data->var->mlx_win, 17, 0, destroy, data);
	// mlx_hook(data->var->mlx_win, 4, 0, mouseclick_down, data);
	// mlx_hook(data->var->mlx_win, 5, 0, mouseclick_up, data);
	// mlx_hook(data->var->mlx_win, 6, 0, mousemove, data);
	// mlx_hook(data->var->mlx_win, 3, 0, keyup, data);
	mlx_loop(data->var->mlx_ptr);
	return (ft_cleardata(data), 0);
}
