/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:11 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/23 21:53:19 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	ft_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
	}
	return (free(line), close(fd), height);
}

void	ft_set_line(t_line_vars *line, t_point *p1, t_point *p2)
{
	line->dx = abs(p2->x - p1->x);
	line->dy = -abs(p2->y - p1->y);
	line->sx = (p1->x < p2->x) - (p1->x >= p2->x);
	line->sy = (p1->y < p2->y) - (p1->y >= p2->y);
	line->error = line->dx + line->dy;
}
