/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:36:20 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/28 03:29:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(t_data **data, int val, int dir)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*data)->wirefr->transformed;
	while (i < (*data)->wirefr->height)
	{
		j = 0;
		while (j < (*data)->wirefr->widths[i])
		{
			if (dir == 0)
			{
				ft_translate(&p[i][j], val - (*data)->mouse.mouse_x, 0);
				(*data)->mouse.mouse_x = val;
			}
			if (dir == 1)
			{
                ft_translate(&p[i][j], 0, val - (*data)->mouse.mouse_y);
				(*data)->mouse.mouse_y = val;;
			}
			j++;
		}
		i++;
	}
    ft_draw_new(data);
}
