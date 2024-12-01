/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobke <tobke@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:00:30 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 18:24:22 by tobke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_project_isometric(t_point *point, float rad)
{
	float	x;
	float	y;
	float	z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = (x - y) * cos(rad);
	point->y = -z + (x + y) * sin(rad);
}

void	ft_rotate_x(t_point *point, float rad)
{
	float	y;
	float	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(rad) - z * sin(rad);
	point->z = y * sin(rad) + z * cos(rad);
}

void	ft_rotate_y(t_point *point, float rad)
{
	float	x;
	float	z;

	x = point->x;
	z = point->z;
	point->x = x * cos(rad) + z * sin(rad);
	point->z = -x * sin(rad) + z * cos(rad);
}

void	ft_rotate_z(t_point *point, float rad)
{
	float	x;
	float	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(rad) - y * sin(rad);
	point->y = x * sin(rad) + y * cos(rad);
}
