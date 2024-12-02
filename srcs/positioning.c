/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:15 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 18:10:47 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_avg_height(t_wire **wire, float val)
{
	(*wire)->avg_h = val;
}

void	ft_avg_width(t_wire **wire, float val)
{
	(*wire)->avg_w = val;
}

void	ft_middle(t_wire **wire)
{
	int		i;
	int		j;
	int		total;
	float	sum_x;
	float	sum_y;

	i = 0;
	total = 0;
	sum_x = 0;
	sum_y = 0;
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			sum_x += (*wire)->transformed[i][j].x;
			sum_y += (*wire)->transformed[i][j].y;
			j++;
			total++;
		}
		i++;
	}
	ft_avg_width(wire, sum_x / total);
	ft_avg_height(wire, sum_y / total);
}
