/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:13:24 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:15:00 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**==================================================
**					-=1_PART "#0+- " =-
**==================================================
*/

int		find_symb(char symb, t_get_flag *descr)
{
	if (symb == '0')
		descr->zero = 1;
	if (symb == '-')
		descr->minus = 1;
	if (symb == '+')
		descr->plus = 1;
	if (symb == '#')
		descr->sharp = 1;
	if (symb == ' ')
		descr->space = 1;
	if (symb == '0' || symb == '-' || symb == '+' || symb == '#' || symb == ' ')
		return (1);
	return (0);
}

int		find_flag_symbol(char *str, int *start, t_get_flag *descr)
{
	while (str[*start])
	{
		if ((find_symb(str[*start], descr) == 0)
			&& !((str[*start] >= 'a' && str[*start] <= 'z')
			|| (str[*start] >= 'A' && str[*start] <= 'Z')))
			return (0);
		*start += 1;
		if ((str[*start] >= 'a' && str[*start] <= 'z')
			|| (str[*start] >= 'A' && str[*start] <= 'Z'))
			return (1);
	}
	return (0);
}
