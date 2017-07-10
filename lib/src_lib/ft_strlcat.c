/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:11:24 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/29 19:19:12 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned long	dst_len;
	unsigned long	src_len;
	int				i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	if (n == 0)
		return (src_len);
	dest += dst_len;
	i = n - MIN(dst_len, n);
	while (--i > 0 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (src_len + MIN(dst_len, n));
}
