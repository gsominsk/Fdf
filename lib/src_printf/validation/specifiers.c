/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:16:04 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:16:28 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ==================================================
**		-= 5_PART "l, hh, h, ll, j, z, t, L" =-
** ==================================================
*/

void	css_2(int *start, char *str, int *temp, int *sign)
{
	if (str[*start] == 'l' && str[*start + 1] == 'l')
	{
		*start += 2;
		*sign = 1;
		*temp < *sign ? *temp = *sign : 0;
	}
	else if (str[*start] == 'h' && str[*start + 1] == 'h')
	{
		*start += 2;
		*sign = 2;
		*temp < *sign ? *temp = *sign : 0;
	}
	else if (str[*start] == 'l')
	{
		*start += 1;
		*sign = 3;
		*temp < *sign ? *temp = *sign : 0;
	}
	else if (str[*start] == 'h')
	{
		*start += 1;
		*sign = 4;
		*temp < *sign ? *temp = *sign : 0;
	}
}

void	css_1(int *start, char *str, int *temp, int *sign)
{
	if (str[*start] == 'j')
	{
		*start += 1;
		*sign = 5;
		*temp < *sign ? *temp = *sign : 0;
	}
	else if (str[*start] == 'z')
	{
		*start += 1;
		*sign = 6;
		*temp < *sign ? *temp = *sign : 0;
	}
	else if (str[*start] == 't')
	{
		*start += 1;
		*sign = 7;
		*temp < *sign ? *temp = *sign : 0;
	}
	else if (str[*start] == 'L')
	{
		*start += 1;
		*sign = 8;
		*temp < *sign ? *temp = *sign : 0;
	}
}

int		check_size_specifier(char *str, int *start)
{
	int i;
	int temp;
	int sign;

	i = -1;
	sign = 0;
	temp = 0;
	while ((str[*start] == 'l' && str[*start + 1] == 'l')
			|| (str[*start] == 'h' && str[*start + 1] == 'h')
			|| str[*start] == 'l' || str[*start] == 'h'
			|| str[*start] == 'j' || str[*start] == 'z'
			|| str[*start] == 't' || str[*start] == 'L')
	{
		css_1(start, str, &temp, &sign);
		css_2(start, str, &temp, &sign);
	}
	sign = temp;
	return (sign);
}
