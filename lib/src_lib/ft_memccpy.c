/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:52:20 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/29 19:28:49 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		ch_buff;

	i = 0;
	while (n-- > 0)
	{
		ch_buff = ((unsigned char *)src)[i];
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		if (ch_buff == (unsigned char)c)
			return (&dst[i]);
	}
	return (NULL);
}
