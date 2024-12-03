/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:02 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/03 12:46:56 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_out(t_data **data, t_wire **wire)
{
	int		i;
	int		j;

	i = 0;
	ft_setorigin(&(*data)->wirefr);
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			(*wire)->transformed[i][j].x *= (1 - 0.1);
			(*wire)->transformed[i][j].y *= (1 - 0.1);
			(*wire)->transformed[i][j].z *= (1 - 0.1);
			j++;
		}
		i++;
	}
	ft_setdefault(&(*data)->wirefr);
	ft_draw_new(data);
}

void	ft_zoom_in(t_data **data, t_wire **wire)
{
	int		i;
	int		j;

	i = 0;
	ft_setorigin(&(*data)->wirefr);
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			(*wire)->transformed[i][j].x *= (1 + 0.1);
			(*wire)->transformed[i][j].y *= (1 + 0.1);
			(*wire)->transformed[i][j].z *= (1 + 0.1);
			j++;
		}
		i++;
	}
	ft_setdefault(&(*data)->wirefr);
	ft_draw_new(data);
}

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
	ft_middle(&(*data)->wirefr);
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
	ft_middle(&(*data)->wirefr);
	ft_draw_new(data);
}
