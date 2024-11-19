/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:58:12 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/18 22:54:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	ft_atol(char *s)
{
	size_t	i;
	int		p;
	long	val;
	bool	valid;

	i = 0;
	p = 1;
	val = 0;
	valid = false;
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			p = -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		valid = true;
		val = val * 10 + (s[i++] - '0');
	}
	if (!valid || s[i] != '\0')
		return (LONG_MIN);
	return (val * p);
}

size_t	ft_len(char **map_ln)
{
	size_t	i;

	i = 0;
	while (map_ln[i])
		i++;
	return (i);
}

int	ft_fill_map(t_map **map, t_nested *nested, size_t count)
{
	long	val;
	int		*values;
	int		i;

	values = (int *)malloc(sizeof(int) * count);
	if (!values)
		return (0);
	i = 0;
	while (i < count)
	{
		val = ft_atol(str[i]);
		if (val > INT_MAX || val < INT_MIN || val == LONG_MIN)
			return (free(values), 0);
		values[i++] = (int)val;
	}
	i = 0;
	while (i < count)
		ft_lstadd_back(map, ft_lstnew(values[i++]));
	return (free(values), 1);
}

int	ft_parseline(t_map *map, char **map_ln)
{
	
}

int	ft_calloc_widths(t_map *map, int fd)
{
	int	fd2;
	int	*line;
	int	i;

	i = 0;
	fd2 = fd;
	while (1)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		map->widths[i] = ft_linelength(line);
	}
}

int	ft_calloc_map(t_map *map, int fd)
{
	int		fd2;
	int		height;
	char	**splitted;
	char	*line;

	fd2 = fd;
	height = 0;
	while (get_next_line(fd2))
		height++;
	map->height = height;
	map->widths = malloc(sizeof(int) * height);
	map->matrix = malloc(sizeof(t_point *) * (map->height));
	ft_calloc_widths(map, fd);
	if (!map->widths || !map->matrix)
		return (0);
	return (1);
}

int	ft_parsemap(t_map *map, char **argv)
{
	char	*line;
	char	**map_ln;
	int		fd;
	int		height;

	fd = open(argv[0], O_RDONLY);
	if (fd == -1)
		return (0);
	if (!ft_calloc_map(map, fd))
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_ln = ft_split(line, ' ');
		if (!map_ln)
			return (free(line), free(map_ln), ft_clear(map), 0);
		if (!ft_parseline(map, map_ln))
			return (free(line), free(map_ln), ft_clear(map), 0);
	}
	return (free(line), free(map_ln), 1);
}
