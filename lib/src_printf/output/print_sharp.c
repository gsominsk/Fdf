/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sharp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:16:46 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:30:26 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_sharp(int value, char *o_str, t_get_flag *descr)
{
	if (value == 8 && o_str[0] != '0')
	{
		ft_putchar('0');
		descr->length += 1;
	}
	else if (value == 16 && o_str[0] != '0')
	{
		ft_putstr("0x");
		descr->length += 2;
	}
	else if (value == 17 && o_str[0] != '0')
	{
		ft_putstr("0X");
		descr->length += 2;
	}
}

void	shs_3(t_get_flag *d, char *o, int value, int *i)
{
	size_t	l;
	int		t;

	l = ft_strlen(o);
	d->width -= l;
	d->plus == 1 ? d->width -= 1 : 0;
	(d->sharp == 1 && (value == 16 || value == 17)) ? d->width -= 2 : 0;
	(d->sharp == 1 && value == 8) ? d->width -= 1 : 0;
	if (d->zero != 1)
	{
		t = d->width - (d->p > (int)l ? d->p - l : 0);
		std_space(t, d, &o);
	}
	d->sharp == 1 ? print_sharp(value, o, d) : 0;
	d->zero == 1 ? std_space(d->width, d, &o) : 0;
	if (d->p > (int)l)
		while ((unsigned long)++(*i) < (d->p - l))
		{
			ft_putstr("0");
			d->width--;
			d->length++;
		}
	std_str(o, d);
}

void	shs_2(t_get_flag *descr, char *o_str, int value, int *i)
{
	size_t l;

	l = ft_strlen(o_str);
	descr->sharp == 1 ? print_sharp(value, o_str, descr) : 0;
	if ((size_t)descr->p > l)
		while (++(*i) < (int)(descr->p - l))
		{
			ft_putstr("0");
			descr->width--;
			descr->length++;
		}
	*i = std_str(o_str, descr);
	if (descr->sharp == 1)
		std_space(descr->width - l - *i - (value == 8 ? 1 : 2), descr, &o_str);
	else
		std_space(descr->width - l - *i, descr, &o_str);
}

void	shs_1(t_get_flag *descr, char *o_str, int value, int *i)
{
	if ((size_t)descr->width > ft_strlen(o_str))
	{
		if (descr->minus == 1)
			shs_2(descr, o_str, value, i);
		else
			shs_3(descr, o_str, value, i);
	}
	else
	{
		if (descr->sharp == 1)
		{
			print_sharp(value, o_str, descr);
			(descr->sharp == 1 && value == 8) ? descr->p -= 1 : 0;
		}
		if ((size_t)descr->p > ft_strlen(o_str))
			while (++(*i) < (int)(descr->p - ft_strlen(o_str)))
			{
				ft_putstr("0");
				descr->width--;
				descr->length++;
			}
		std_str(o_str, descr);
	}
}

void	shs(t_get_flag *descr, char *o_str, int value)
{
	int		i;

	i = -1;
	if (descr->p != -1 && o_str[0] == '0')
	{
		while (++i < descr->width)
			if (descr->zero == 1)
			{
				ft_putstr("0");
				descr->length++;
			}
			else
			{
				ft_putstr(" ");
				descr->length++;
			}
		if (descr->sharp == 1 && value != 16)
		{
			ft_putstr(o_str);
			descr->length++;
		}
	}
	else
		shs_1(descr, o_str, value, &i);
	ft_strdel(&o_str);
}
