/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:23:44 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:33:37 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		func_percent(t_get_flag *descr)
{
	int i;

	i = -1;
	if (descr->width != 0)
	{
		descr->minus == 1 ? ft_putstr("%") : 0;
		while (++i < descr->width - 1)
		{
			descr->zero == 1 ? ft_putstr("0") : ft_putstr(" ");
			descr->length++;
		}
		descr->minus != 1 ? ft_putstr("%") : 0;
		descr->length++;
	}
	else
	{
		ft_putchar('%');
		descr->length++;
	}
	return (1);
}

int		func_binary(t_get_flag *descr, int type)
{
	descr->plus = 0;
	if (type == 0)
		o_l_s(descr, i_b(va_arg(*descr->arg, int), 2, 0));
	else if (type == 1)
		o_l_s(descr, i_b(va_arg(*descr->arg, long long int), 2, 0));
	else if (type == 3)
		o_l_s(descr, i_b(va_arg(*descr->arg, long int), 2, 0));
	else if (type == 2)
		o_l_s(descr, i_b((char)va_arg(*descr->arg, int), 2, 0));
	else if (type == 4)
		o_l_s(descr, i_b((short int)va_arg(*descr->arg, int), 2, 0));
	else if (type == 5)
		o_l_s(descr, i_b(va_arg(*descr->arg, intmax_t), 2, 0));
	else if (type == 6)
		o_l_s(descr, i_b(va_arg(*descr->arg, size_t), 2, 0));
	else if (type == 7)
		o_l_s(descr, i_b(va_arg(*descr->arg, ptrdiff_t), 2, 0));
	else if (type == 8)
		o_l_s(descr, i_b(va_arg(*descr->arg, size_t), 2, 0));
	return (1);
}
