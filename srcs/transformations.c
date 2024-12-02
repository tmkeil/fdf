/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:57 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 18:13:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setdefault(t_wire **wire)
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
			ft_translate(&p[i][j], (*wire)->avg_w, (*wire)->avg_h);
			j++;
		}
		i++;
	}
}

void	ft_setorigin(t_wire **wire)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*wire)->transformed;
	ft_middle(wire);
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			ft_translate(&p[i][j], -(*wire)->avg_w, -(*wire)->avg_h);
			j++;
		}
		i++;
	}
}

void	ft_translate(t_point *point, float x, float y)
{
	point->x += x;
	point->y += y;
}

void	ft_rotate(t_wire **a, float w, void (*f)(t_point *, float))
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	ft_setorigin(a);
	p = (*a)->transformed;
	while (i < (*a)->height)
	{
		j = 0;
		while (j < (*a)->widths[i])
		{
			f(&p[i][j], w * M_PI / 180);
			j++;
		}
		i++;
	}
	ft_setorigin(a);
}

void	ft_autoscale(t_wire **wire, float fac, float pad)
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
