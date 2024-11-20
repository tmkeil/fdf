/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:56 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/20 21:44:29 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawline(t_data *data, t_line *line)
{
	int		e;
	t_img	*current;

	current = NULL;
	ft_arrangeline(line);
	ft_set_current(data, &current);
	ft_paint_buffer(current, BACKCOL);
	while (1)
	{
		ft_putpxl(current, line->p1->x, line->p1->y, line->p1->color);
		if (line->p1->x == line->p2->x && line->p1->y == line->p2->y)
			break ;
		e = 2 * line->error;
		if (e >= line->dy)
		{
			line->error += line->dy;
			line->p1->x += line->sx;
		}
		if (e <= line->dx)
		{
			line->error += line->dx;
			line->p1->y += line->sy;
		}
	}
	ft_put_buffer_to_window(data);
}

// void	ft_wireframe()
// {
	
// }
