/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrollzoom_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:17:35 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/28 03:27:10 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_out(t_data **data, t_wire **wire)
{
	int		i;
	int		j;

	i = 0;
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
	ft_draw_new(data);
}

void	ft_zoom_in(t_data **data, t_wire **wire)
{
	int		i;
	int		j;

	i = 0;
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
	ft_draw_new(data);
}
