/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:27:00 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/26 02:05:56 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(t_point *point, float x, float y)
{
	point->x += (int)(x);
	point->y += (int)(y);
}

void	ft_rotate(t_point *p, float w, void (*f)(t_point *, float))
{
	f(p, w * M_PI / 180);
}

// void	ft_scale(t_wire *wire, t_point *point, float fac, int pad)
// {
// 	float	auto_scale;
// 	float	f_x;
// 	float	f_y;

// 	f_x = (WIDTH - pad) / wire->max_w;
// 	f_y = (HEIGHT - pad) / wire->height;
// 	auto_scale = (f_x * (f_x <= f_y) + f_y * (f_y < f_x));
// 	point->x = (int)round(point->x * auto_scale * fac);
// 	point->y = (int)round(point->y * auto_scale * fac);
// 	point->z = (int)round(point->z * auto_scale * fac);
// }

void	ft_scale(t_wire **wire, float fac, int pad)
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
			p[i][j].x = (int)(p[i][j].x * (*wire)->auto_scale * fac);
			p[i][j].y = (int)(p[i][j].y * (*wire)->auto_scale * fac);
			p[i][j].z = (int)(p[i][j].z * (*wire)->auto_scale * fac);
			j++;
		}
		i++;
	}
	ft_set_max_height(*wire);
	ft_set_max_width(*wire);
}
