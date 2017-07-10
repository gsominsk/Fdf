/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:51:55 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/28 14:36:50 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*dest2;

	dest1 = (unsigned char*)s1;
	dest2 = (unsigned char*)s2;
	while (n--)
	{
		if (*dest1 - *dest2)
			return ((int)(*dest1 - *dest2));
		else
		{
			dest1++;
			dest2++;
		}
	}
	return (0);
}
