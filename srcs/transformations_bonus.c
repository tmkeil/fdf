/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:02 by tkeil             #+#    #+#             */
/*   Updated: 2024/12/02 19:47:22 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_out(t_data **data, t_wire **wire)
{
	int		i;
	int		j;

	i = 0;
	ft_setorigin(&(*data)->wirefr);
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			(*wire)->transformed[i][j].x *= (1 - 0.1);
			(*wire)->transformed[i][j].y *= (1 - 0.1);
			(*wire)->transformed[i][j].z *= (1 - 0.1);
			j++;
		}
		i++;
	}
	ft_setdefault(&(*data)->wirefr);
	ft_draw_new(data);
}

void	ft_zoom_in(t_data **data, t_wire **wire)
{
	int		i;
	int		j;

	i = 0;
	ft_setorigin(&(*data)->wirefr);
	while (i < (*wire)->height)
	{
		j = 0;
		while (j < (*wire)->widths[i])
		{
			(*wire)->transformed[i][j].x *= (1 + 0.1);
			(*wire)->transformed[i][j].y *= (1 + 0.1);
			(*wire)->transformed[i][j].z *= (1 + 0.1);
			j++;
		}
		i++;
	}
	ft_setdefault(&(*data)->wirefr);
	ft_draw_new(data);
}

void	ft_move_x(t_data **data, int val)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*data)->wirefr->transformed;
	while (i < (*data)->wirefr->height)
	{
		j = 0;
		while (j < (*data)->wirefr->widths[i])
		{
			ft_translate(&p[i][j], val - (*data)->mouse.mouse_x, 0);
			j++;
		}
		i++;
	}
	(*data)->mouse.mouse_x = val;
	ft_middle(&(*data)->wirefr);
	ft_draw_new(data);
}

void	ft_move_y(t_data **data, int val)
{
	int		i;
	int		j;
	t_point	**p;

	i = 0;
	p = (*data)->wirefr->transformed;
	while (i < (*data)->wirefr->height)
	{
		j = 0;
		while (j < (*data)->wirefr->widths[i])
		{
			ft_translate(&p[i][j], 0, val - (*data)->mouse.mouse_y);
			j++;
		}
		i++;
	}
	(*data)->mouse.mouse_y = val;
	ft_middle(&(*data)->wirefr);
	ft_draw_new(data);
}

// void	ft_z(t_data *data, t_wire **wire, int pm)
// {
// 	int		i;
// 	int		j;
// 	t_point	**p;

// 	i = 0;
// 	p = (*wire)->transformed;
// 	while (i < (*wire)->height)
// 	{
// 		j = 0;
// 		printf("reihe %i\n", i);
// 		while (j < (*wire)->widths[i])
// 		{
// 			printf("spalte %i\n", j);
// 			if (pm == 0)
// 			{
// 				printf("z davor %f\n", p[i][j].z);
// 				p[i][j].z *= 1.2;
// 				printf("z ist nun %f\n", p[i][j].z);
// 			}
// 			printf("\n");
// 			if (pm == 1)
// 				p[i][j].z *= 0.8;
// 			j++;
// 		}
// 		i++;
// 	}
// 	printf("die echten z sind 1: %f 2: %f\n", data->wirefr->transformed[1][0].z, data->wirefr->transformed[1][1].z);
// 	printf("hjsdjsjfhjsfsf\n");
// 	ft_draw_new(&data);
// }
