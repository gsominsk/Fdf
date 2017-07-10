/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:07:30 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:08:09 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ==================================================
**					-=2_PART_WIDTH=-
** ==================================================
*/

int		find_width(char *str, int *start, t_get_flag *descr)
{
	int temp;

	temp = *start;
	if (str[*start] >= '1' && str[*start] <= '9')
	{
		while (str[temp] >= '0' && str[temp] <= '9')
			temp++;
		descr->width = ft_atoi(ft_strsub(str, *start, temp));
		*start += temp - *start;
		return (1);
	}
	return (0);
}

int		find_flag_width(char *str, int *start, t_get_flag *descr)
{
	while (str[*start])
	{
		if (find_width(str, start, descr) == 1)
			return (1);
		if ((str[*start] >= 'a' && str[*start] <= 'z')
			|| (str[*start] >= 'A' && str[*start] <= 'Z'))
			return (1);
		else
			return (0);
	}
	return (0);
}
