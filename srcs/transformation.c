/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:27:00 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/22 13:28:12 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate(t_data **data, float x, float y, float z)
{
	int		i;
	int		j;
	t_point	**ordinates;

	i = 0;
	ordinates = &(*data)->wirefr->transformed;
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

void	ft_rotate_x(t_data **data, float phi)
{
	int		i;
	int		j;
	float	y;
	float	z;
	t_point	**ordinates;

	i = 0;
	ordinates = &(*data)->wirefr->transformed;
	while (i < (*data)->map->height)
	{
		j = 0;
		while (j < (*data)->map->widths[i])
		{
			y = ordinates[i][j].y;
			z = ordinates[i][j].z;
			ordinates[i][j].y = y * cos(phi) - z * sin(phi);
			ordinates[i][j].z = y * sin(phi) + z * cos(phi);
			j++;
		}
		i++;
	}
}

void	ft_rotate_y(t_data **data, float phi)
{
	int		i;
	int		j;
	float	x;
	float	z;
	t_point	**ordinates;

	i = 0;
	ordinates = &(*data)->wirefr->transformed;
	while (i < (*data)->map->height)
	{
		j = 0;
		while (j < (*data)->map->widths[i])
		{
			x = ordinates[i][j].x;
			z = ordinates[i][j].z;
			ordinates[i][j].x = x * cos(phi) + z * sin(phi);
			ordinates[i][j].z = -x * sin(phi) + z * cos(phi);
			j++;
		}
		i++;
	}
}

void	ft_rotate_z(t_data **data, float phi)
{
	int		i;
	int		j;
	float	x;
	float	y;
	t_point	**ordinates;

	i = 0;
	ordinates = &(*data)->wirefr->transformed;
	while (i < (*data)->map->height)
	{
		j = 0;
		while (j < (*data)->map->widths[i])
		{
			x = ordinates[i][j].x;
			y = ordinates[i][j].y;
			ordinates[i][j].x = x * cos(phi) - y * sin(phi);
			ordinates[i][j].y = x * sin(phi) + y * cos(phi);
			j++;
		}
		i++;
	}
}
