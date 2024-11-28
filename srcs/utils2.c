/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:16:11 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/28 00:50:37 by tkeil            ###   ########.fr       */
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

void	ft_set_line(t_line_vars *line, t_point *p1, t_point *p2, int *len)
{
	line->dx = p2->x - p1->x;
	line->dy = p2->y - p1->y;
	line->len = sqrtf(powf(line->dx, 2) + powf(line->dy, 2));
	// printf("x1 = %f, x2 = %f, y1 = %f, y2 = %f\n", p1->x, p2->x, p1->y, p2->y);
	printf("line->dx = %f, und line->dy = %f\n", line->dx, line->dy);
	printf("line->len = %i\n", line->len);
	*len = line->len;
	if (!*len)
		return ;
	line->sx = line->dx / line->len;
	line->sy = line->dy / line->len;
}

uint32_t	ft_interpol_color(t_point *p1, t_point *p2, int small, int big)
{
	uint8_t r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	col1;
	uint8_t	col2;

	if (big == 0)
		return (p1->color);
	col1 = (p1->color >> 16) & 0xFF;
	col2 = (p2->color >> 16) & 0xFF;
	r = (uint8_t)((col1) + (col2 - col1) * (small / big));
	col1 = (p1->color >> 8) & 0xFF;
	col2 = (p2->color >> 8) & 0xFF;
	g = (uint8_t)((col1) + (col2 - col1) * (small / big));
	col1 = (p1->color) & 0xFF;
	col2 = (p2->color) & 0xFF;
	b = (uint8_t)((col1) + (col2 - col1) * (small / big));
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
