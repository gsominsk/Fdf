/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:59:28 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/21 18:26:23 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ==================================================
**					DRAWING_MAP
** ==================================================
*/

void	sin_cos_init(t_fdf *cd)
{
	cd[0].cos_a = cos(cd[0].a);
	cd[0].cos_b = cos(cd[0].b);
	cd[0].cos_g = cos(cd[0].g);
	cd[0].sin_a = sin(cd[0].a);
	cd[0].sin_b = sin(cd[0].b);
	cd[0].sin_g = sin(cd[0].g);
}

double	multiply_x_matrix(int i, t_fdf *cd)
{
	return ((cd[i].x * cd[0].scale_all * cd[0].cos_b +
	(-cd[i].y * cd[0].scale_all * cd[0].sin_a +
	cd[i].z * cd[0].scale_all * cd[0].cos_a * cd[0].step_z)
	* cd[0].sin_b) * cd[0].cos_g +
	(cd[i].y * cd[0].scale_all * cd[0].cos_a
	+ cd[i].z * cd[0].scale_all * cd[0].sin_a * cd[0].step_z)
	* cd[0].sin_g);
}

double	multiply_y_matrix(int i, t_fdf *cd)
{
	return (-(cd[i].x * cd[0].scale_all * cd[0].cos_b +
	(-cd[i].y * cd[0].scale_all * cd[0].sin_a + cd[i].z *
	cd[0].scale_all * cd[0].cos_a * cd[0].step_z) * cd[0].sin_b) *
	cd[0].sin_g + (cd[i].y * cd[0].scale_all * cd[0].cos_a
	+ cd[i].z * cd[0].scale_all * cd[0].sin_a * cd[0].step_z)
	* cd[0].cos_g);
}

void	write_instructions(t_fdf *cd)
{
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 10, 0x99ff33, "zoom :");
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 30, 0x99ff33, "\" < , > \"");
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 50, 0x99ff33, "change");
	mlx_string_put(cd[0].mlx, cd[0].win, 80, 50, 0x99ff33, "figure height :");
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 70, 0x99ff33, "\" +, - \"");
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 90, 0x99ff33, "change");
	mlx_string_put(cd[0].mlx, cd[0].win, 80, 90, 0x99ff33, "map position  :");
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 110, 0x99ff33, "\" w, a, s, d \"");
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 130, 0x99ff33, "change");
	mlx_string_put(cd[0].mlx, cd[0].win, 80, 130, 0x99ff33, "figure angle :");
	mlx_string_put(cd[0].mlx, cd[0].win, 10, 150, 0x99ff33, "\" up, down,");
	mlx_string_put(cd[0].mlx, cd[0].win, 125, 150, 0x99ff33, "right, left \"");
}

void	draw_map(t_fdf *cd)
{
	double			x;
	double			y;
	register int	i;

	i = -1;
	sin_cos_init(cd);
	while (cd[++i].end)
	{
		x = multiply_x_matrix(i, cd);
		y = multiply_y_matrix(i, cd);
		cd[i].start_x = cd[0].map_pos_x + x * cd[0].step_x;
		cd[i].start_y = cd[0].map_pos_y + y * cd[0].step_y;
		mlx_pixel_put(cd[0].mlx, cd[0].win, cd[0].start_x,
					cd[0].start_y, cd[i].color);
	}
	write_instructions(cd);
	brazzers(cd);
}
