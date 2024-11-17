/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:59:27 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/17 22:34:46 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_mlx;

typedef struct s_image_data
{
	void	*img;
	char	*data;
	int		linelen;
	int		bpp;
	int		endian;
}			t_image_data;

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

#endif
