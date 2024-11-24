/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:11 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/24 21:01:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

uint32_t	ft_interpol_color(t_point *p1, t_point *p2, t_point cur)
{
	float	ratio;
	float	big;
	float	small;

	big = sqrtf(powf(p2->x - p1->x, 2) + powf(p2->y - p1->y, 2));
	small = sqrtf(powf(cur.x - p1->x, 2) + powf(cur.y - p1->y, 2));
	uint8_t r, g, b;
	if (big == 0.0f)
		return (p1->color);
	ratio = small / big;
	r = (uint8_t)(((p1->color >> 16) & 0xFF) + (((p2->color >> 16) & 0xFF)
				- ((p1->color >> 16) & 0xFF)) * ratio);
	g = (uint8_t)(((p1->color >> 8) & 0xFF) + (((p2->color >> 8) & 0xFF) - ((p1->color >> 8) & 0xFF))
			* ratio);
	b = (uint8_t)((p1->color & 0xFF) + ((p2->color & 0xFF) - (p1->color & 0xFF)) * ratio);
	return ((r << 16) | (g << 8) | b);
}

void	ft_putpxl(t_img **img, int x, int y, uint32_t color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	offset = x * ((*img)->bpp / 8) + y * (*img)->linelen;
	*(unsigned int *)((*img)->data + offset) = color;
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
