/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:48:14 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/30 16:43:57 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *memptr, int value, size_t mem_len)
{
	char *s;

	s = memptr;
	while (mem_len-- != 0)
		s[mem_len] = (unsigned char)value;
	return (memptr);
}
