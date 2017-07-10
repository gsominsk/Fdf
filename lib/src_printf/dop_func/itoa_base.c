/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:20:16 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 16:22:12 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define A(x) ((x) < 0 ? -(x) : (x))

void	f_big(uintmax_t value, int base, char *str, int *i)
{
	if (value >= (uintmax_t)base)
		f_big(value / base, base, str, i);
	str[(*i)++] = "0123456789ABCDEF"[A(value % base)];
}

void	f_small(uintmax_t value, int base, char *str, int *i)
{
	if (value >= (uintmax_t)base)
		f_small(value / base, base, str, i);
	str[(*i)++] = "0123456789abcdef"[A(value % base)];
}

char	*i_b(uintmax_t value, int base, int size)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (base == 10)
		str[i++] = '-';
	if (size == 0)
		f_small(value, base, str, &i);
	else
		f_big(value, base, str, &i);
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_u(unsigned long long int n)
{
	char					*str;
	unsigned long long int	i;
	int						n_len;

	n_len = 1;
	i = n;
	while (i /= 10)
		n_len++;
	if (!(str = (char *)malloc(sizeof(char) * n_len)))
		return (NULL);
	str[n_len] = '\0';
	i = n;
	while (n_len--)
	{
		str[n_len] = i % 10 + '0';
		if ((i /= 10) == 0)
			break ;
	}
	return (str);
}

char	*ftoa_d(long double num, int precision)
{
	int		i;
	int		j;
	char	*str;
	char	*res;

	i = -1;
	while (++i <= precision)
	{
		num /= 0.1;
	}
	num < 0 ? num -= 2 : 0;
	str = ft_itoa((long long int)num + 1);
	res = (char *)malloc(sizeof(char) * ft_strlen(str));
	i = -1;
	j = 0;
	while ((unsigned long)++i < ft_strlen(str))
		if ((size_t)i == (ft_strlen(str) - precision - 1))
			res[i] = '.';
		else
		{
			res[i] = str[j];
			j++;
		}
	free(str);
	return (res);
}
