/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:52:50 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/21 15:52:51 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*dst_buff;

	dst_buff = dst;
	while (*src && len > 0)
	{
		*dst_buff = *src;
		len--;
		dst_buff++;
		src++;
	}
	while (len > 0)
	{
		*dst_buff = 0;
		dst_buff++;
		len--;
	}
	return (dst);
}
