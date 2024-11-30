/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:58:12 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/01 00:25:44 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_matrix(t_wire **wire, char **split, int i, int j)
{
	long	val;

	val = ft_atol(split[0]);
	if (val > INT_MAX || val < INT_MIN)
		return (0);
	(*wire)->transformed[i][j].x = (float)j;
	(*wire)->transformed[i][j].y = (float)i;
	(*wire)->transformed[i][j].z = (float)val;
	return (1);
}

int	ft_colors(t_wire **wire, char **split, int i, int j)
{
	long	val;

	if (!split[1])
		(*wire)->transformed[i][j].color = (uint32_t)PKTCOL;
	else
	{
		val = ft_atol_base(split[1], 16);
		if (val > UINT32_MAX || val < 0)
			return (0);
		(*wire)->transformed[i][j].color = (uint32_t)val;
	}
	return (1);
}

int	ft_map_matrix(t_wire **wire, char *line, int i)
{
	int		j;
	char	**split;
	char	**split2;

	split = ft_split(line, ' ');
	(*wire)->transformed[i] = malloc(sizeof(t_point) * (*wire)->widths[i]);
	if (!split || !(*wire)->transformed[i])
		return (ft_clrptr((void **) split), 0);
	j = 0;
	while (split[j])
	{
		split2 = ft_split(split[j], ',');
		if (!split2)
			return (ft_clrptr((void **) split), 0);
		if (!ft_matrix(wire, split2, i, j) || !ft_colors(wire, split2, i, j))
			return (ft_clrptr((void **) split), ft_clrptr((void **) split2), 0);
		ft_clrptr((void **) split2);
		j++;
	}
	ft_clrptr((void **) split);
	return (1);
}

static int	ft_init_map(t_wire *wire, int fd, char *filename)
{
	int		height;
	char	*line;
	int		i;

	height = ft_map_height(filename);
	wire->height = height;
	wire->widths = malloc(sizeof(int) * height);
	wire->transformed = malloc(sizeof(t_point *) * height);
	if (!wire->widths || !wire->transformed)
		return (0);
	i = 0;
	while (i < wire->height)
		wire->transformed[i++] = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		wire->widths[i] = ft_wordcount(line);
		if (!ft_map_matrix(&wire, line, i++))
			return (free(line), 0);
	}
	ft_set_max_width(wire);
	return (free(line), 1);
}

int	ft_parsemap(t_data **data, char **argv)
{
	int		fd;
	char	*filename;
	t_wire	*wire;

	wire = (*data)->wirefr;
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
	if (!ft_init_map(wire, fd, filename))
		return (close(fd), 0);
	return (close(fd), 1);
}
