/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_output_line_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:36:07 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:36:08 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ==================================================
**					-=OUTPUT=-
** ==================================================
*/

void	output_2(t_get_flag *d, char *o_str)
{
	int i;
	int num;

	if ((size_t)d->width > ft_strlen(o_str))
		if (d->minus == 1)
		{
			i = std_str(o_str, d);
			std_space(d->width - ft_strlen(o_str) - i, d, &o_str);
		}
		else
		{
			d->width -= ft_strlen(o_str) - (o_str[0] == '-' ? 1 : 0);
			(d->plus == 1 || o_str[0] == '-') ? d->width -= 1 : 0;
			if (d->space == 1)
			{
				d->width--;
				d->length++;
				ft_putchar(' ');
			}
			num = (d->p != -1 ? d->width - d->p : d->width) - d->minus;
			std_space(num, d, &o_str);
			std_str(o_str, d);
		}
	else
		std_str(o_str, d);
}

void	o_l_s(t_get_flag *descr, char *o_str)
{
	if (descr->p == -1)
		output_2(descr, o_str);
	else
		output_1(descr, o_str);
	ft_strdel(&o_str);
}
