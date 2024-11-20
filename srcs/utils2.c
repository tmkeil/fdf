/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:11 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/20 15:49:12 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

size_t	ft_len(char **map_ln)
{
	size_t	i;

	i = 0;
	while (map_ln[i])
		i++;
	return (i);
}

int	ft_abs(int value)
{
	return ((((value) * ((value) >= 0)) - ((value) * ((value) < 0))));
}

int	ft_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}

size_t	ft_wordcount(char *line)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i] >= 9 && line[i] <= 13))
		{
			count++;
			while (line[i] && line[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}
