/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:01:48 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/22 10:33:14 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *string)
{
	int i;
	int number;
	int sign;

	i = 0;
	number = 0;
	sign = 1;
	while (string[i] == ' ' || string[i] == '\n' || string[i] == '\t'
			|| string[i] == '\f' || string[i] == '\r' || string[i] == '\v')
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		number *= 10;
		number += (int)string[i] - '0';
		i++;
	}
	return (number * sign);
}
