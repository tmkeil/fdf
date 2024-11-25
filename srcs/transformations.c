/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:27:00 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/25 03:50:41 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(t_point *point, float x, float y)
{
	point->x += (int)(x / 2);
	point->y += (int)(y / 2);
}

void	ft_rotate(t_point *p, float w, void (*f)(t_point *, float))
{
	f(p, w * M_PI / 180);
}

void	ft_scale(t_wire *wire, t_point *point, float fac, int pad)
{
	float	auto_scale;
	float	f_x;
	float	f_y;

	f_x = (WIDTH - pad) / wire->max_w;
	f_y = (HEIGHT - pad) / wire->height;
	auto_scale = (f_x * (f_x <= f_y) + f_y * (f_y < f_x));
	point->x = (int)round(point->x * auto_scale * fac);
	point->y = (int)round(point->y * auto_scale * fac);
	point->z = (int)round(point->z * auto_scale * fac);
}
