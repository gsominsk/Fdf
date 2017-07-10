/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:08:32 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/28 19:09:15 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	if (size == 0 || size)
		if ((str = malloc(size)) == NULL)
			return (NULL);
	i = -1;
	while (++i < size)
		(*((unsigned char *)(str + i))) = 0;
	return (str);
}
