/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_output_line_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:36:55 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:37:22 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ==================================================
**					-=OUTPUT=-
** ==================================================
*/

void	o_4(t_get_flag *d, char *o_str, size_t l)
{
	if (d->space == 1)
	{
		ft_putstr(" ");
		d->length++;
	}
	if (d->plus == 1 || o_str[0] == '-')
	{
		o_str[0] == '-' ? ft_putstr("-") : ft_putstr("+");
		o_str[0] == '-' ? o_str = ft_strsub(o_str, 1, l) : 0;
		l = ft_strlen(o_str);
		d->width--;
		d->length++;
	}
	if (d->p != -1)
		while ((unsigned long)d->p > l)
		{
			ft_putstr("0");
			d->length++;
			d->p--;
		}
	if (o_str[0] != '0')
	{
		ft_putstr(o_str);
		d->length += l;
	}
}

void	o_3(t_get_flag *d, char *o_str, size_t l)
{
	if (d->p != -1 && (d->plus == 1 || o_str[0] == '-'))
	{
		o_str[0] == '-' ? ft_putstr("-") : ft_putstr("+");
		if (o_str[0] == '-')
			o_str = ft_strsub(o_str, 1, l);
		l = ft_strlen(o_str);
	}
	while ((unsigned long)d->p > l)
	{
		ft_putstr("0");
		d->width--;
		d->length++;
		d->p--;
	}
	if (o_str[0] != '0' | d->p != 0)
	{
		ft_putstr(o_str);
		d->length += l;
	}
}

void	o_2(t_get_flag *d, char *o_str, size_t l)
{
	if (d->plus == 1 || o_str[0] == '-' || d->space == 1)
	{
		d->space == 1 ? ft_putstr(" ") : 0;
		d->width--;
		d->length++;
	}
	if (d->p == -1 && (d->plus == 1 || o_str[0] == '-'))
	{
		o_str[0] == '-' ? ft_putstr("-") : ft_putstr("+");
		if (o_str[0] == '-')
			o_str = ft_strsub(o_str, 1, l);
		l = ft_strlen(o_str);
	}
	if (d->p < d->width)
	{
		if (d->p < (int)l && o_str[0] == '-')
			d->width++;
		while ((unsigned long)d->p < d->width - (((size_t)d->p <
				l && o_str[0] != '0') ? l - d->p : 0))
		{
			ft_putstr(" ");
			d->length++;
			d->width--;
		}
	}
}

void	o_1(t_get_flag *d, char *o_str, size_t l, int i)
{
	if (d->space == 1)
	{
		ft_putstr(" ");
		d->length++;
	}
	if (d->plus == 1)
	{
		ft_putstr("+");
		d->length++;
		d->width--;
	}
	while (d->p != 0 && (unsigned long)--d->p > l - 1)
	{
		ft_putstr("0");
		d->length++;
		d->width--;
	}
	ft_putstr(o_str);
	d->length += l;
	std_space(d->width - l - i, d, &o_str);
}

void	output_1(t_get_flag *d, char *o_str)
{
	int		i;
	size_t	l;

	i = 0;
	l = ft_strlen(o_str);
	if ((size_t)d->width > l)
	{
		if (d->minus == 1)
			o_1(d, o_str, l, i);
		else
		{
			o_2(d, o_str, l);
			o_3(d, o_str, l);
		}
	}
	else
		o_4(d, o_str, l);
}
