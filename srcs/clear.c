/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:46:14 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/03 17:30:27 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clrptr(void **ptr)
{
	int	i;

	if (!ptr || !*ptr)
		return ;
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	ptr = NULL;
}

static void	ft_clear_wireframe(t_wire *wirefr)
{
	int	i;

	i = 0;
	if (wirefr->transformed)
	{
		while (i < wirefr->height)
		{
			if (wirefr->transformed[i])
				free(wirefr->transformed[i]);
			i++;
		}
		free(wirefr->transformed);
		wirefr->transformed = NULL;
	}
	if (wirefr->widths)
	{
		free(wirefr->widths);
		wirefr->widths = NULL;
	}
	free(wirefr);
	wirefr = NULL;
}

void	ft_clear_mlx(t_data **data)
{
	if ((*data) && (*data)->var)
	{
		if ((*data)->var->mlx_win)
		{
			mlx_destroy_window((*data)->var->mlx_ptr, (*data)->var->mlx_win);
			(*data)->var->mlx_ptr = NULL;
			(*data)->var->mlx_win = NULL;
		}
		free((*data)->var);
		(*data)->var = NULL;
	}
}

void	ft_cleardata(t_data *data)
{
	if (data)
	{
		if (data->img)
			ft_clear_images(&data->img, data->var->mlx_ptr);
		if (data->wirefr)
			ft_clear_wireframe(data->wirefr);
		ft_clear_mlx(&data);
		free(data);
		data = NULL;
	}
}
