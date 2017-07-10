/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:38:14 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/30 16:28:13 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *string1, const char *string2, size_t n)
{
	int				res;
	unsigned int	i;

	i = 0;
	res = 0;
	while (string1[i] && !(res) && i < (unsigned int)n)
	{
		res = (int)((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
	}
	if (!res && i != n)
		res = (int)((unsigned char)string1[i] - (unsigned char)string2[i]);
	return (res);
}
