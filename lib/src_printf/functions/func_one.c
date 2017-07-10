/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:24:26 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:34:44 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		func_int(t_get_flag *descr, int type)
{
	if (type == 0)
		o_l_s(descr, ft_itoa(va_arg(*descr->arg, int)));
	else if (type == 1)
		o_l_s(descr, ft_itoa(va_arg(*descr->arg, long long int)));
	else if (type == 3)
		o_l_s(descr, ft_itoa(va_arg(*descr->arg, long int)));
	else if (type == 2)
		o_l_s(descr, ft_itoa((char)va_arg(*descr->arg, int)));
	else if (type == 4)
		o_l_s(descr, ft_itoa((short int)va_arg(*descr->arg, int)));
	else if (type == 5)
		o_l_s(descr, ft_itoa(va_arg(*descr->arg, intmax_t)));
	else if (type == 6)
		o_l_s(descr, ft_itoa(va_arg(*descr->arg, size_t)));
	else if (type == 7)
		o_l_s(descr, ft_itoa(va_arg(*descr->arg, ptrdiff_t)));
	else if (type == 8)
		o_l_s(descr, ft_itoa(va_arg(*descr->arg, size_t)));
	return (1);
}

int		func_float_small(t_get_flag *d)
{
	int precision;

	if (d->p == -1)
		precision = 6;
	else
		precision = d->p;
	o_l_s(d, ftoa_d((float)va_arg(*d->arg, double), precision));
	return (1);
}

int		func_float_big(t_get_flag *descr, int type)
{
	int p;

	if (descr->p == -1)
		p = 6;
	else
		p = descr->p;
	if (type == 8)
		o_l_s(descr, ftoa_d(va_arg(*descr->arg, long double), p));
	else
		o_l_s(descr, ftoa_d(va_arg(*descr->arg, double), p));
	return (1);
}

int		func_long_decimal(t_get_flag *descr)
{
	o_l_s(descr, ft_itoa(va_arg(*descr->arg, intmax_t)));
	return (1);
}

int		func_unsigned(t_get_flag *d, int type)
{
	if (type == 0)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, unsigned int)));
	else if (type == 1)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, t_ulli)));
	else if (type == 3)
		o_l_s(d, ft_itoa_u(va_arg(*d->arg, t_ulli)));
	else if (type == 2)
		o_l_s(d, ft_itoa_u((unsigned char)va_arg(*d->arg, unsigned int)));
	else if (type == 4)
		o_l_s(d, ft_itoa_u((unsigned short int)va_arg(*d->arg, unsigned int)));
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
