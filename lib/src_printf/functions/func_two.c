/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:27:24 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:29:26 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		func_hex_small(t_get_flag *d, int type)
{
	d->plus = 0;
	d->space = 0;
	if (type == 0)
		shs(d, i_b(va_arg(*d->arg, unsigned int), 16, 0), 16);
	else if (type == 1)
		shs(d, i_b(va_arg(*d->arg, t_ulli), 16, 0), 16);
	else if (type == 3)
		shs(d, i_b(va_arg(*d->arg, unsigned long int), 16, 0), 16);
	else if (type == 2)
		shs(d, i_b((unsigned char)va_arg(*d->arg, unsigned int), 16, 0), 16);
	else if (type == 4)
		shs(d, i_b((unsigned short int)va_arg(*d->arg, int), 16, 0), 16);
	else if (type == 5)
		shs(d, i_b(va_arg(*d->arg, uintmax_t), 16, 0), 16);
	else if (type == 6)
		shs(d, i_b(va_arg(*d->arg, size_t), 16, 0), 16);
	else if (type == 7)
		shs(d, i_b(va_arg(*d->arg, ptrdiff_t), 16, 0), 16);
	else if (type == 8)
		shs(d, i_b(va_arg(*d->arg, size_t), 16, 0), 16);
	return (1);
}

int		func_hex_big(t_get_flag *d, int type)
{
	d->plus = 0;
	d->space = 0;
	if (type == 0)
		shs(d, i_b(va_arg(*d->arg, unsigned int), 16, 1), 17);
	else if (type == 1)
		shs(d, i_b(va_arg(*d->arg, t_ulli), 16, 1), 17);
	else if (type == 3)
		shs(d, i_b(va_arg(*d->arg, unsigned long int), 16, 1), 17);
	else if (type == 2)
		shs(d, i_b((unsigned char)va_arg(*d->arg, unsigned int), 16, 1), 17);
	else if (type == 4)
		shs(d, i_b((unsigned short int)va_arg(*d->arg, int), 16, 1), 17);
	else if (type == 5)
		shs(d, i_b(va_arg(*d->arg, uintmax_t), 16, 1), 17);
	else if (type == 6)
		shs(d, i_b(va_arg(*d->arg, size_t), 16, 1), 17);
	else if (type == 7)
		shs(d, i_b(va_arg(*d->arg, ptrdiff_t), 16, 1), 17);
	else if (type == 8)
		shs(d, i_b(va_arg(*d->arg, size_t), 16, 1), 17);
	return (1);
}

int		func_octa(t_get_flag *d, int type)
{
	d->plus = 0;
	d->space = 0;
	if (type == 0)
		shs(d, i_b(va_arg(*d->arg, unsigned int), 8, 0), 8);
	else if (type == 1)
		shs(d, i_b(va_arg(*d->arg, t_ulli), 8, 0), 8);
	else if (type == 3)
		shs(d, i_b(va_arg(*d->arg, unsigned long int), 8, 0), 8);
	else if (type == 2)
		shs(d, i_b((unsigned char)va_arg(*d->arg, unsigned int), 8, 0), 8);
	else if (type == 4)
		shs(d, i_b((unsigned short int)va_arg(*d->arg, unsigned int), 8, 0), 8);
	else if (type == 5)
		shs(d, i_b(va_arg(*d->arg, uintmax_t), 8, 0), 8);
	else if (type == 6)
		shs(d, i_b(va_arg(*d->arg, size_t), 8, 0), 8);
	else if (type == 7)
		shs(d, i_b(va_arg(*d->arg, ptrdiff_t), 8, 0), 8);
	else if (type == 8)
		shs(d, i_b(va_arg(*d->arg, size_t), 8, 0), 8);
	return (1);
}

int		func_unsigned_big(t_get_flag *d, int type)
{
	if (type == 0)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, t_ulli)));
	else if (type == 1)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, t_ulli)));
	else if (type == 3)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, t_ulli)));
	else if (type == 2)
		o_l_s(d, ft_itoa_u((unsigned short)va_arg(*d->arg, t_ulli)));
	else if (type == 4)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, t_ulli)));
	else if (type == 5)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, intmax_t)));
	else if (type == 6)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, size_t)));
	else if (type == 7)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, ptrdiff_t)));
	else if (type == 8)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, size_t)));
	return (1);
}

int		func_octa_big(t_get_flag *d, int type)
{
	d->plus = 0;
	d->space = 0;
	if (type == 0)
		shs(d, i_b(va_arg(*d->arg, t_ulli), 8, 0), 8);
	else if (type == 1)
		shs(d, i_b(va_arg(*d->arg, t_ulli), 8, 0), 8);
	else if (type == 3)
		shs(d, i_b(va_arg(*d->arg, unsigned long int), 8, 0), 8);
	else if (type == 2)
		shs(d, i_b((unsigned short)va_arg(*d->arg, unsigned int), 8, 0), 8);
	else if (type == 4)
		shs(d, i_b((unsigned short int)va_arg(*d->arg, unsigned int), 8, 0), 8);
	else if (type == 5)
		shs(d, i_b(va_arg(*d->arg, uintmax_t), 8, 0), 8);
	else if (type == 6)
		shs(d, i_b(va_arg(*d->arg, size_t), 8, 0), 8);
	else if (type == 7)
		shs(d, i_b(va_arg(*d->arg, ptrdiff_t), 8, 0), 8);
	else if (type == 8)
		shs(d, i_b(va_arg(*d->arg, size_t), 8, 0), 8);
	return (1);
}
