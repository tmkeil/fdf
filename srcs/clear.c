/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:13:32 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/20 21:34:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clrptr(void **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	ft_clearmap(t_map *map)
{
	if (!map)
		return ;
	if (map->profile)
		ft_clrptr((void **)map->profile);
	if (map->colors)
		ft_clrptr((void **)map->colors);
	if (map->widths)
		free(map->widths);
	free(map);
}

static void	ft_clear_images(t_imgs *img)
{
	if (!img)
		return ;
	if (img->current)
	{
		ft_clrptr((void **)img->current->data);
		free(img->current);
	}
	if (img->buffer1)
	{
		ft_clrptr((void **)img->buffer1->data);
		free(img->buffer1);
	}
	if (img->buffer2)
	{
		ft_clrptr((void **)img->buffer2->data);
		free(img->buffer2);
	}
	free(img);
}

static void	ft_clear_lines(t_wireframe *wirefr)
{
	int	i;

	if (!wirefr || !wirefr->lines)
		return ;
	i = 0;
	while (i < wirefr->num_lines)
	{
		free(wirefr->lines[i].p1);
		free(wirefr->lines[i].p2);
		i++;
	}
	free(wirefr->lines);
	free(wirefr);
}

void	ft_cleardata(t_data *data)
{
	if (!data)
		return ;
	if (data->var)
		free(data->var);
	ft_clear_images(data->img);
	ft_clear_lines(data->wirefr);
	free(data);
}
