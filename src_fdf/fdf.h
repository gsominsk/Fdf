/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:01:47 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/22 17:20:43 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <math.h>
# include "../lib/src_lib/libft.h"
# include "../lib/src_printf/ft_printf.h"
# include "../lib/src_gnl/get_next_line.h"
# include "mlx.h"

# define KNRM	"\x1B[0m"
# define KRED	"\x1B[91m"
# define KGRN	"\x1B[92m"
# define KYEL	"\x1B[93m"
# define KBLU	"\x1B[94m"
# define KMAG	"\x1B[95m"
# define KCYN	"\x1B[96m"
# define KWHT	"\x1B[97m"

# define RAD	0.0174533

typedef struct		s_fdf
{
	double		scale_all;
	double		start_x;
	double		start_y;
	double		step_x;
	double		step_y;
	double		step_z;
	double		max_z;
	double		cos_a;
	double		cos_b;
	double		cos_g;
	double		sin_a;
	double		sin_b;
	double		sin_g;
	double		z;
	double		x;
	double		y;
	double		a;
	double		b;
	double		g;
	void		*mlx;
	void		*win;
	int			color_num;
	int			map_pos_y;
	int			map_pos_x;
	int			len_x;
	int			len_y;
	int			color;
	int			end;
	int			sx;
	int			sy;
	int			e2;
	int			fp;
}					t_fdf;

int					ft_atoi_base(char *str, int b);
void				brazzers(t_fdf *cd);
int					key_func(int keycode, t_fdf *cd);
void				draw_map(t_fdf *cd);
void				write_coord(t_fdf *cd, char *str, int *len, int row);
void				find_max_z(t_fdf *cd);
int					line_len(char *str, int *j);

#endif
