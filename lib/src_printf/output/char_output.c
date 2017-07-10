/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:54:13 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:57:22 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fc(t_get_flag *descr, char symb, int *i)
{
	if (descr->minus == 1)
	{
		ft_putchar(symb);
		descr->length++;
		while (++(*i) < descr->width - 1)
		{
			descr->zero == 1 ? ft_putchar('0') : ft_putchar(' ');
			descr->length++;
		}
	}
	else
	{
		while (++(*i) < descr->width - 1)
		{
			descr->zero == 1 ? ft_putchar('0') : ft_putchar(' ');
			descr->length++;
		}
		ft_putchar(symb);
		descr->length++;
	}
}

int		func_char(t_get_flag *descr)
{
	int		i;
	char	symb;

	i = -1;
	symb = (char)va_arg(*descr->arg, int);
	if ((size_t)descr->width > 1)
		fc(descr, symb, &i);
	else
	{
		ft_putchar(symb);
		descr->length++;
	}
	return (1);
}

void	fw(t_get_flag *descr, char symb, int *i)
{
	if (descr->minus == 1)
	{
		ft_putwchar(symb);
		descr->length++;
		while (++(*i) < descr->width - 1)
		{
			ft_putchar(' ');
			descr->length++;
		}
	}
	else
	{
		while (++(*i) < descr->width - 1)
		{
			ft_putchar(' ');
			descr->length++;
		}
		ft_putwchar(symb);
		descr->length++;
	}
}

int		func_wchar(t_get_flag *descr)
{
	int		i;
	wchar_t	symb;

	i = -1;
	symb = (wchar_t)va_arg(*descr->arg, int);
	if ((size_t)descr->width > 1)
		fw(descr, symb, &i);
	else
	{
		ft_putwchar(symb);
		descr->length++;
	}
	return (1);
}
