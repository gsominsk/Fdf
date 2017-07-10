/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:46:26 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/24 17:46:27 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*buff;

	i = 0;
	buff = s;
	if ((unsigned char)c == '\0')
	{
		while (buff[i] != '\0' && i < n)
			i++;
		return ((char*)&buff[i]);
	}
	while (buff[i] != '\0' && i < n)
	{
		if (buff[i] == c)
			return ((unsigned char *)&buff[i]);
		i++;
	}
	return (NULL);
}
