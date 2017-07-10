/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstring_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:27:07 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:27:07 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	zero_choice(t_get_flag *d)
{
	d->zero == 1 ? ft_putchar('0') : ft_putchar(' ');
	d->length++;
}

static void	fs_2(wchar_t *str, t_get_flag *d, unsigned long *i)
{
	int l;

	l = (int)ft_strlen_w(str);
	if (l == 0)
		while (++(*i) < (unsigned long)d->width)
			zero_choice(d);
	else
	{
		if (d->p >= l)
			while (++(*i) < (unsigned long)(d->width - l))
				zero_choice(d);
		else if (d->p < l && d->p != -1)
			while (++(*i) < (unsigned long)d->width - d->p)
				zero_choice(d);
		else
			while (++(*i) < (unsigned long)(d->width - l))
				zero_choice(d);
	}
	d->p != -1 ? ft_putnwstr(str, d) : ft_putwstr(str);
	d->p == -1 ? (d->length += l) : 0;
}

static void	fs_1(wchar_t *str, t_get_flag *d, unsigned long *i, size_t l)
{
	if ((size_t)d->width > l)
	{
		if (d->minus == 1)
		{
			d->p != -1 ? ft_putnwstr(str, d) : ft_putwstr(str);
			d->p == -1 ? (d->length += l) : 0;
			if (l == 0)
				while (++(*i) < (unsigned long)d->width)
					zero_choice(d);
			else
				while (++(*i) < d->width - l + (d->p == -1 ? 0 : d->p))
					zero_choice(d);
		}
		else
			fs_2(str, d, i);
	}
	else
	{
		if (d->width != 0 && d->width > d->p)
			while (++(*i) < (unsigned long)(d->width - d->p))
				zero_choice(d);
		d->p != -1 ? ft_putnwstr(str, d) : ft_putwstr(str);
		d->p == -1 ? (d->length += l) : 0;
	}
}

int			func_wstring(t_get_flag *d)
{
	unsigned long	i;
	wchar_t			*str;

	str = va_arg(*d->arg, wchar_t *);
	i = -1;
	if (str == NULL)
	{
		if (d->width == 0)
		{
			ft_putstr("(null)");
			d->length += 6;
		}
		else
			while (--d->width != -1)
			{
				ft_putchar('0');
				d->length++;
			}
	}
	else
		fs_1(str, d, &i, ft_strlen_w(str));
	return (1);
}
