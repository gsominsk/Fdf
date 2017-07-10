/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brazenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:58:53 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/21 18:30:42 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ==================================================
**					BRAZENHAM
** ==================================================
*/

void	find_path(int i, int x_1, int y_1, t_fdf *cd)
{
	int x_0;
	int y_0;

	x_0 = cd[i].start_x;
	y_0 = cd[i].start_y;
	(x_0 < x_1) ? (cd[0].sx = 1) : 1;
	(x_0 > x_1) ? (cd[0].sx = -1) : 1;
	(y_0 < y_1) ? (cd[0].sy = 1) : 1;
	(y_0 > y_1) ? (cd[0].sy = -1) : 1;
}

void	dl_1(int dy, int *err, int *x_0, t_fdf *cd)
{
	*err += dy;
	*x_0 += cd[0].sx;
}

void	dl_2(int dx, int *err, int *y_0, t_fdf *cd)
{
	*err += dx;
	*y_0 += cd[0].sy;
}

void	draw_line(int i, int x_1, int y_1, t_fdf *cd)
{
	int x_0;
	int y_0;
	int err;
	int dx;
	int dy;

	x_0 = cd[i].start_x;
	y_0 = cd[i].start_y;
	dx = abs(x_1 - x_0);
	dy = -abs(y_1 - y_0);
	err = dx + dy;
	find_path(i, x_1, y_1, cd);
	while (1)
	{
		mlx_pixel_put(cd[0].mlx, cd[0].win, x_0, y_0, cd[i].color);
		if (x_0 == x_1 && y_0 == y_1)
			break ;
		cd[0].e2 = 2 * err;
		cd[0].e2 > dy ? dl_1(dy, &err, &x_0, cd) : 0;
		cd[0].e2 < dx ? dl_2(dx, &err, &y_0, cd) : 0;
	}
}

void	brazzers(t_fdf *cd)
{
	register int i;
	register int k;

	i = -1;
	k = -1;
	while (cd[++i].end != 0 && cd[i + 1].end != 0)
	{
		if (cd[i].y == cd[i + 1].y)
			draw_line(i, cd[i + 1].start_x, cd[i + 1].start_y, cd);
		while (cd[++k].end != 0)
			if (cd[k].x == cd[i].x && cd[i].y + 1 == cd[k].y)
			{
				draw_line(i, cd[k].start_x, cd[k].start_y, cd);
				break ;
			}
	}
}
