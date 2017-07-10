/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:46:46 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/29 19:22:25 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_buff;
	char	*src_buff;

	dst_buff = dst;
	src_buff = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_buff[i] = (unsigned char)src_buff[i];
		i++;
	}
	return (dst);
}
