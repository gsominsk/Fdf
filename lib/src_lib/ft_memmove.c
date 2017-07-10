/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:51:39 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/25 14:51:40 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;

	i = 0;
	if ((unsigned long)dst < (unsigned long)src)
	{
		i = 0;
		while (len-- > 0)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
		while (len-- > 0)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}
