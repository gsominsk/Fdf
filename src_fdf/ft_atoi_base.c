/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:55:11 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/11 11:55:12 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_inbase(char c, int b, char l)
{
	if (b <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= l && c <= (l + b - 10)));
}

int		check_case(char *str, int b)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'A' + b)
			return (1);
		if (str[i] >= 'a' && str[i] <= 'a' + b)
			return (0);
	}
	return (1);
}

int		ft_atoi_base(char *str, int b)
{
	int		value;
	int		sign;
	char	let;

	value = 0;
	if (b < 2 || b > 16)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	let = check_case(str, b) ? 'A' : 'a';
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, b, let))
	{
		if (*str - let >= 0)
			value = value * b + (*str - let + 10);
		else
			value = value * b + (*str - '0');
		str++;
	}
	return (value * sign);
}
