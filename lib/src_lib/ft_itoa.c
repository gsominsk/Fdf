/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:17:19 by gsominsk          #+#    #+#             */
/*   Updated: 2017/03/09 15:33:16 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long int n)
{
	char			*str;
	long long int	i;
	int				n_len;

	n_len = (n < 0) ? 2 : 1;
	i = n;
	while (i /= 10)
		n_len++;
	if (!(str = (char *)malloc(sizeof(char) * n_len)))
		return (NULL);
	(n < 0) ? str[0] = '-' : 0;
	str[n_len] = '\0';
	i = n;
	(n < 0) ? i = -i : 0;
	while (n_len--)
	{
		n = (i % 10);
		n < 0 ? n *= -1 : 0;
		str[n_len] = n % 10 + '0';
		if ((i /= 10) == 0)
			break ;
	}
	return (str);
}
