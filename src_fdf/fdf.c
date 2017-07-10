/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:57:53 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/22 18:56:56 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ==================================================
**					CREATNG_WINDOW
** ==================================================
*/

void	create_wrath(t_fdf *cd)
{
	cd[0].mlx = mlx_init();
	cd[0].win = mlx_new_window(cd[0].mlx, 1024, 800, "mlx 42");
	cd[0].color_num = 0;
	cd[0].map_pos_x = 350;
	cd[0].map_pos_y = 350;
	cd[0].step_x = 700 / (cd[0].len_x * 1.5);
	cd[0].step_y = 700 / (cd[0].len_y * 1.5);
	find_max_z(cd);
	cd[0].step_z = (cd[0].max_z / 5) / cd[0].max_z;
	cd[0].scale_all = 1;
	if (cd[0].max_z == 0)
		cd[0].step_z = 1;
	if (cd[0].max_z < 30 && cd[0].max_z > 10)
		cd[0].step_z = (cd[0].max_z / 20) / cd[0].max_z;
	draw_map(cd);
	mlx_key_hook(cd[0].win, key_func, cd);
	mlx_loop(cd[0].mlx);
}

void	fdf_1(t_fdf *cd, int *len, int *i)
{
	cd[0].len_x = *len;
	cd[0].len_y = *i;
	*len = 0;
	*i = -1;
}

int		fdf(char *file_name, t_fdf *cd)
{
	char	*str;
	int		fd;
	int		i;
	int		fp;
	int		len;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (2);
	i = 0;
	while ((fp = get_next_line(fd, &str)) > 0)
		len = line_len(str, &i);
	cd = (t_fdf *)malloc(sizeof(t_fdf) * ((++i) * len));
	fdf_1(cd, &len, &i);
	close(fd);
	fd = open(file_name, O_RDONLY);
	while ((fp = get_next_line(fd, &str)) > 0)
		if (cd[0].len_x > line_len(str, &i))
			return (1);
		else
			write_coord(cd, str, &len, i);
	create_wrath(cd);
	cd[len].end = 0;
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*cd;
	int		i;

	if (argc == 2)
	{
		cd = NULL;
		if ((i = fdf(argv[1], cd)) == 1)
			ft_putstr("Found wrong line length. Exiting.");
		else if (i == 2)
			ft_putstr("Not valid file.");
		return (0);
	}
	else
		ft_putstr("invalid number of arguments");
	return (0);
}
