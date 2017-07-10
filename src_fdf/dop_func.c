/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:58:15 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/22 17:06:55 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ==================================================
**					DOP_FUNC
** ==================================================
*/

int		line_len(char *str, int *j)
{
	register int i;
	register int counter;

	*j += 1;
	i = -1;
	counter = 0;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9')
		{
			counter++;
			while (str[i] != ' ' && str[i + 1] != '\0')
				i++;
		}
	return (counter);
}

void	find_max_z(t_fdf *cd)
{
	register int i;

	i = -1;
	cd[0].max_z = 0;
	while (cd[++i].end != 0)
		cd[i].z < cd[0].max_z ? cd[0].max_z = cd[i].z * (-1) : 0;
}

void	write_coord(t_fdf *cd, char *str, int *len, int row)
{
	register int	i;
	char			**splitted;
	char			**splitted_param;

	i = -1;
	splitted = ft_strsplit(str, ' ');
	while (splitted[++i] && i < cd[0].len_x)
	{
		splitted_param = ft_strsplit(splitted[i], ',');
		cd[*len].z = -ft_atoi(splitted_param[0]);
		if (splitted_param[1])
			cd[*len].color = ft_atoi_base(splitted_param[1] + 2, 16);
		else
			cd[*len].color = 0xFFFFFF;
		cd[*len].x = i;
		cd[*len].y = row;
		cd[*len].end = 1;
		cd[0].a = 45 * RAD;
		cd[0].b = 45 * RAD;
		cd[0].g = 0 * RAD;
		*len += 1;
	}
}
