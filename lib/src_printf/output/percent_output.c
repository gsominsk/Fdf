/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:49:01 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:51:56 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		fp_2_2(t_get_flag *descr, char *temp, int *i)
{
	while ((size_t)descr->width > ft_strlen(temp) + 2)
	{
		descr->zero == 1 ? ft_putstr("0") : ft_putstr(" ");
		descr->length++;
		descr->width--;
	}
	ft_putstr("0x");
	descr->length += 2;
	while (*i < (int)ft_strlen(temp))
	{
		ft_putchar(temp[*i]);
		descr->length++;
		++(*i);
	}
}

void			fp_2(t_get_flag *descr, char *temp, int *i)
{
	if (descr->minus == 1)
	{
		ft_putstr("0x");
		descr->length += 2;
		while (*i < (int)ft_strlen(temp))
		{
			ft_putchar(temp[*i]);
			descr->length++;
			++(*i);
		}
		while ((size_t)descr->width > ft_strlen(temp) + 2)
		{
			ft_putstr(" ");
			descr->length++;
			descr->width--;
		}
	}
	else
		fp_2_2(descr, temp, i);
}

static void		fp_1_1(t_get_flag *descr, char *temp, int *i)
{
	ft_putstr("0x");
	descr->length += 2;
	if (!(temp[0] == '0' && descr->p != -1))
		while (*i < (int)ft_strlen(temp))
		{
			ft_putchar(temp[*i]);
			descr->length++;
			++(*i);
		}
	while (descr->p > (int)ft_strlen(temp) + 2)
	{
		descr->zero == 1 ? ft_putstr("0") : ft_putstr(" ");
		descr->p--;
		descr->width--;
	}
}

static void		fp_1(t_get_flag *descr, char *temp, int *i)
{
	int j;

	j = 0;
	if (descr->p > (int)ft_strlen(temp))
	{
		ft_putstr("0x");
		descr->length += 2;
		while ((unsigned long)j < descr->p - ft_strlen(temp))
		{
			ft_putstr("0");
			descr->length++;
			descr->width--;
			j++;
		}
		while (*i < (int)ft_strlen(temp))
		{
			ft_putchar(temp[*i]);
			descr->length++;
			++(*i);
		}
	}
	else
		fp_1_1(descr, temp, i);
}

int				func_pointer(t_get_flag *d)
{
	size_t	num;
	char	*s;
	char	*t;
	int		i;

	num = (size_t)va_arg(*d->arg, void *);
	s = (char *)malloc(sizeof(num) * 2 + 1);
	i = 2 * sizeof(num);
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = "0123456789abcdef"[num & 0x0F];
		num >>= 4;
	}
	i = -1;
	while (s[++i] == '0')
		if (s[i] == '0' && s[i + 1] == '\0')
			break ;
	free(s);
	t = ft_strsub(s, i, ft_strlen(s));
	i = 0;
	(size_t)d->width > ft_strlen(t) ? fp_2(d, t, &i) : fp_1(d, t, &i);
	return (1);
}
