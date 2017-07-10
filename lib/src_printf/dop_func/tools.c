/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:22:28 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:23:14 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putwchar(wchar_t w)
{
	write(1, &w, sizeof(w));
}

size_t	ft_strlen_w(const wchar_t *s)
{
	int		length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

void	ft_putwstr(wchar_t *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putwchar(str[i]);
}

int		ft_putnstr(char *str, t_get_flag *descr)
{
	int i;

	i = -1;
	while (str[++i] && i < descr->p)
	{
		ft_putchar(str[i]);
		descr->length++;
	}
	return (1);
}

int		ft_putnwstr(wchar_t *str, t_get_flag *descr)
{
	int i;

	i = -1;
	while (str[++i] && i < descr->p)
	{
		ft_putwchar(str[i]);
		descr->length++;
	}
	return (1);
}
