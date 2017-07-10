/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:52:38 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/22 09:34:36 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	count;

	count = -1;
	while (src[++count] != '\0')
	{
		dst[count] = src[count];
	}
	dst[count] = '\0';
	return (dst);
}
