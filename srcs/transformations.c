/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:27:00 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/28 01:40:57 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(t_point *point, float x, float y)
{
	point->x += x;
	point->y += y;
}

void	ft_rotate(t_point *p, float w, void (*f)(t_point *, float))
{
	f(p, w * M_PI / 180);
}

void	ft_scale(t_wire **wire, float fac, float pad)
{
	int		i;
	int		j;
	float	f_x;
	float	f_y;
	t_point	**p;

	i = 0;
	p = (*wire)->transformed;
	f_x = (WIDTH - pad) / (*wire)->max_w;
	f_y = (HEIGHT - pad) / (*wire)->height;
	(*wire)->auto_scale = (f_x * (f_x <= f_y) + f_y * (f_y < f_x));
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			p[i][j].x = p[i][j].x * (*wire)->auto_scale * fac;
			p[i][j].y = p[i][j].y * (*wire)->auto_scale * fac;
			p[i][j].z = p[i][j].z * (*wire)->auto_scale * fac;
			j++;
		}
		i++;
	}
}
