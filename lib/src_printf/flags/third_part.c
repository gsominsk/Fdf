/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:12:33 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:21:33 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ==================================================
**					-=3_PART_PRECISION=-
** ==================================================
*/

static void	fp_1(int *temp, int *start, char *str, t_get_flag *descr)
{
	*temp += 1;
	while (str[*temp] >= '0' && str[*temp] <= '9')
		*temp += 1;
	descr->p = ft_atoi(ft_strsub(str, *start + 1, *temp));
	*start += *temp - *start;
}

int			find_precision(char *s, int *i, t_get_flag *descr)
{
	int temp;

	temp = *i;
	if (s[*i] == '.' && !(s[*i + 1] >= '0' && s[*i + 1] <= '9'))
	{
		descr->p = 0;
		*i += 1;
		while (s[*i] == '.')
		{
			if (s[*i] == '.' && (s[*i + 1] >= '0' && s[*i + 1] <= '9'))
				find_precision(s, i, descr);
			else
				*i += 1;
		}
		if ((s[*i] >= 'a' && s[*i] <= 'z') || (s[*i] >= 'A' && s[*i] <= 'Z'))
			return (0);
		return (1);
	}
	else if (s[*i] == '.')
	{
		fp_1(&temp, i, s, descr);
		s[*i] == '.' ? find_precision(s, i, descr) : 0;
		return (1);
	}
	return (0);
}

int			find_flag_precision(char *s, int *start, t_get_flag *descr)
{
	while (s[*start])
	{
		if (find_precision(s, start, descr) == 1)
			return (1);
		if (((s[*start] >= 'a' && s[*start] <= 'z')
			|| (s[*start] >= 'A' && s[*start] <= 'Z')) || s[*start] == '%')
			return (1);
		else
			return (-1);
	}
	return (0);
}
