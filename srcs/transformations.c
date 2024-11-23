/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:27:00 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/23 21:45:59 by tkeil            ###   ########.fr       */
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

void	ft_scale(t_point *point, float scale)
{
	point->x = (int)round(point->x * scale);
	point->y = (int)round(point->y * scale);
}
