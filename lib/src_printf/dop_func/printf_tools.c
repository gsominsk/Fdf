/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:16:46 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:19:40 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** ==================================================
**				-=UNDEINED_BEHAVIOR=-
** ==================================================
*/

int		undef_beh(char *str, int *i, t_get_flag *descr)
{
	int j;

	j = *i;
	if (str[*i] == '}')
	{
		ft_putchar('}');
		descr->length++;
	}
	if (!str[*i])
		return (0);
	while (str[j] && str[j] == ' ')
		j++;
	if (str[j] == '\0')
		return (0);
	return (1);
}

/*
** ==================================================
**					-=RESET_OPTIONS=-
** ==================================================
*/

void	full_destruction(t_get_flag *p)
{
	p->zero = 0;
	p->sharp = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->p = -1;
	p->width = 0;
}

/*
** ==================================================
**			-=EXCEPTIONS_AND_FLAG COMPATABILITY=-
** ==================================================
*/

void	check_flag_compatability(t_get_flag *descr, char c)
{
	if (descr->minus == 1 && descr->zero == 1)
		descr->zero = 0;
	if (descr->plus == 1 && descr->space == 1)
		descr->space = 0;
	if (c == 'U' || c == 'u')
	{
		descr->plus = 0;
		descr->space = 0;
	}
}

void	std_space(int value, t_get_flag *descr, char **o_str)
{
	while (value > 0)
	{
		if (descr->zero == 1)
		{
			if (descr->plus == 1 || *o_str[0] == '-')
			{
				*o_str[0] == '-' ? ft_putstr("-") : ft_putstr("+");
				if (*o_str[0] == '-')
					*o_str = ft_strsub(*o_str, 1, ft_strlen(*o_str));
				descr->length++;
				descr->plus = 0;
			}
			ft_putstr("0");
			descr->length++;
		}
		else
		{
			ft_putstr(" ");
			descr->length++;
		}
		value--;
	}
}

int		std_str(char *o_str, t_get_flag *descr)
{
	int i;

	i = 0;
	if (descr->plus == 1 && o_str[0] != '-')
	{
		ft_putstr("+");
		i++;
	}
	if (descr->space == 1 && descr->width == 0 && o_str[0] != '-')
	{
		ft_putstr(" ");
		i++;
	}
	ft_putstr(o_str);
	descr->length += i + ft_strlen(o_str);
	return (i);
}
