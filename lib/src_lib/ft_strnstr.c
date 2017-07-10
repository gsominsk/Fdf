/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:37:41 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/22 14:56:46 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str_b, const char *str_a, size_t n)
{
	size_t len_a;
	size_t len_b;
	size_t lenb_buff;

	len_b = 0;
	len_a = ft_strlen(str_a);
	if (len_a == 0)
		return ((char *)str_b);
	while (str_b[len_b] && len_b < n)
	{
		len_a = 0;
		lenb_buff = len_b;
		while (str_b[len_b] == str_a[len_a] && len_b < n)
		{
			len_a++;
			len_b++;
			if (str_a[len_a] == '\0')
				return ((char *)&str_b[lenb_buff]);
		}
		len_b = lenb_buff;
		len_b++;
	}
	return (NULL);
}
