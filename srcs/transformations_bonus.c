/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:17:35 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 14:25:03 by tobke            ###   ########.fr       */
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

void	ft_z(t_wire **wire, int pm)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*wire)->transformed;
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			if (pm == 0)
				p[i][j].z += 1;
			if (pm == 1)
				p[i][j].z -= 1;
			j++;
		}
		i++;
	}
}
