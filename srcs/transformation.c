/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:27:00 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 20:30:06 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(t_data **data, float x, float y, float z)
{
	int		i;
	int		j;
	t_point	**ordinates;

	i = 0;
	ordinates = (*data)->wirefr->transformed;
	while (i < (*data)->map->height)
	{
		j = 0;
		while (j < (*data)->map->widths[i])
		{
			ordinates[i][j].x += x;
			ordinates[i][j].y += y;
			ordinates[i][j].z += z;
			j++;
		}
		i++;
	}
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

void	ft_rotate(t_data **d, float p, void (*f)(t_point *, float))
{
	int		i;
	int		j;
	t_point	**ordinates;

	i = 0;
	ordinates = (*d)->wirefr->transformed;
	while (i < (*d)->map->height)
	{
		j = 0;
		while (j < (*d)->map->widths[i])
		{
			f(&ordinates[i][j], p * M_PI / 180);
			j++;
		}
		i++;
	}
}
