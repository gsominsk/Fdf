/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:35:01 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:38:12 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ==================================================
**					-=PRINTF=-
** 	==================================================
*/

void	sranaja_norma(t_get_flag *descr, char *format, int i)
{
	ft_putchar(format[i]);
	descr->length++;
}

size_t	ft_printf(char *format, ...)
{
	t_get_flag	descr;
	va_list		arg;
	int			i;
	int			p;

	i = -1;
	va_start(arg, format);
	descr.arg = &arg;
	descr.length = 0;
	while ((size_t)++i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			i++;
			if (undef_beh(format, &i, &descr) == 0)
				return (descr.length);
			full_destruction(&descr);
			if ((p = validation(format, &i, &descr)) == -1)
				return (descr.length);
		}
		else if (format[i] != '\0')
			sranaja_norma(&descr, format, i);
	}
	va_end(arg);
	return (descr.length);
}
