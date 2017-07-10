/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:01:03 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/21 18:16:19 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ==================================================
**					PRESS_BUTTON
** ==================================================
*/

void	kf_3(int keycode, t_fdf *cd)
{
	if (keycode == 43)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].scale_all += 0.1;
		draw_map(cd);
	}
	if (keycode == 47)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].scale_all > 0.1 ? cd[0].scale_all -= 0.1 : 0;
		draw_map(cd);
	}
	if (keycode == 123)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].b += 3 * RAD;
		draw_map(cd);
	}
	if (keycode == 124)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].b -= 3 * RAD;
		draw_map(cd);
	}
}

void	kf_2(int keycode, t_fdf *cd)
{
	if (keycode == 125)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].a += 3 * RAD;
		draw_map(cd);
	}
	if (keycode == 126)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].a -= 3 * RAD;
		draw_map(cd);
	}
	if (keycode == 78)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].step_z -= 0.1;
		draw_map(cd);
	}
	if (keycode == 69)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].step_z += 0.1;
		draw_map(cd);
	}
}

void	kf_1(int keycode, t_fdf *cd)
{
	keycode == 53 ? exit(0) : 0;
	if (keycode == 13)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].map_pos_y -= 20;
		draw_map(cd);
	}
	if (keycode == 0)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].map_pos_x -= 20;
		draw_map(cd);
	}
	if (keycode == 1)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].map_pos_y += 20;
		draw_map(cd);
	}
	if (keycode == 2)
	{
		mlx_clear_window(cd[0].mlx, cd[0].win);
		cd[0].map_pos_x += 20;
		draw_map(cd);
	}
}

int		key_func(int keycode, t_fdf *cd)
{
	kf_1(keycode, cd);
	kf_2(keycode, cd);
	kf_3(keycode, cd);
	return (0);
}
