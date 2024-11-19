/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:58:12 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/19 21:47:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_map_profile(t_map **map, char **split, int size, int i)
{
	long	val;

	val = ft_atol(split[0]);
	if (val >= INT_MAX || val <= INT_MIN)
		return (0);
	(*map)->profile[i] = (int) val;
	return (1);
}

int	ft_map_colors(t_map **map, char **split, int size, int i)
{
	long	val;

	if (!split[1])
		(*map)->colors[i] = PKTCOL;
	else
	{
		val = ft_atol(split[1]);
		if (val >= INT_MAX || val <= INT_MIN)
			return (0);
		(*map)->colors[i] = (int) val;
	}
	return (1);
}

int	ft_map_matrix(t_map **map, char *line, int i)
{
	int		i;
	long	val;
	char	**split;
	char	**split2;

	split = ft_split(line, ' ');
	(*map)->profile[i] = malloc(sizeof(int) * (*map)->widths[i]);
	(*map)->colors[i] = malloc(sizeof(int) * (*map)->widths[i]);
	if (!split || (*map)->profile[i++] || !(*map)->colors[i])
		return (ft_clear(split), 0);
	i = 0;
	while (split[i])
	{
		split2 = ft_split(split[i], ',');
		if (!split2)
			return (ft_clear(split), 0);
		if (!ft_map_profile(map, split2, (*map)->widths[i], i))
			return (ft_clear(split), ft_clear(split2), 0);
		if (!ft_map_colors(map, split2, (*map)->widths[i], i))
			return (ft_clear(split), ft_clear(split2), 0);
		i++;
	}
	return (ft_clear(split), ft_clear(split2), 1);
}

int	ft_init_map(t_map **map, int fd)
{
	int		height;
	char	*line;
	int		i;

	*map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	height = ft_map_height(fd);
	(*map)->height = height;
	(*map)->widths = malloc(sizeof(int) * height);
	(*map)->profile = malloc(sizeof(int *) * height);
	(*map)->colors = malloc(sizeof(int *) * height);
	if (!(*map)->widths || !(*map)->profile || !(*map)->colors)
		return (0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*map)->widths[i] = ft_wordcount(line);
		if (!ft_map_matrix(map, line, i++))
			return (free(line), 0);
	}
	return (free(line), 1);
}

int	ft_parsemap(t_map **map, char **argv)
{
	char	*line;
	char	**map_ln;
	int		fd;
	int		height;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
	if (!ft_init_map(&map, fd))
		return (close(fd), 0);
	return (close(fd), 1);
}
