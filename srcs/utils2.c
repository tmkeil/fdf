/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:11 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/19 19:18:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del(void *content)
{
	free(content);
}

void	ft_clear(t_data *data)
{
	if (data->img)
	{
		free(data->img->buffer1);
		free(data->img->buffer2);
		free(data->img);
	}
	if (data->var)
		free(data->var);
	free(data);
}

void	ft_set_current(t_data *data, t_image_data **current)
{
	if (data->img->current == data->img->buffer1)
		*current = data->img->buffer2;
	else
		*current = data->img->buffer1;
}
