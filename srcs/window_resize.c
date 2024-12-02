/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:42:09 by tobke             #+#    #+#             */
/*   Updated: 2024/12/02 13:28:37 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void    ft_scale(t_wire **wire)
// {
//     int		i;
// 	int		j;
// 	t_point	**p;

// 	i = 0;
// 	p = (*wire)->transformed;
// 	while (i < (*wire)->height)
// 	{
// 		j = 0;
// 		while (j < (*wire)->widths[i])
// 		{
// 			p[i][j].x = p[i][j].x * (*wire)->scale;
// 			p[i][j].y = p[i][j].y * (*wire)->scale;
// 			p[i][j].z = p[i][j].z * (*wire)->scale;
// 			j++;
// 		}
// 		i++;
// 	}
// }

int    ft_wnd_resize(t_data *data, int size)
{
    t_img	*buffer;

	buffer = NULL;
    data->wnd.wnd_w += size;
    data->wnd.wnd_h += size;
    ft_clear_images(data->img, data->var->mlx_ptr);
    ft_clear_mlx(data);
	if (!ft_init_var(data))
		return (0);
	if (!ft_init_imgs(data))
		return (0);
    if (!ft_set_n_paint_buffer(data, &buffer))
		return (0);
	ft_connect_points(data, &buffer);
	return (ft_put_buffer_to_window(data, &buffer), 1);
}
