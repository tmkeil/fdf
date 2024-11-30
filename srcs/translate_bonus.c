/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 02:36:20 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 00:47:35 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_x(t_data **data, int val)
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
			ft_translate(&p[i][j], val - (*data)->mouse.mouse_x, 0);
			j++;
		}
		i++;
	}
	(*data)->mouse.mouse_x = val;
	ft_draw_new(data);
}

void	ft_move_y(t_data **data, int val)
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
			ft_translate(&p[i][j], 0, val - (*data)->mouse.mouse_y);
			j++;
		}
		i++;
	}
	(*data)->mouse.mouse_y = val;
	ft_draw_new(data);
}
