/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:22:04 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/22 14:47:51 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *str_b, const char *str_a)
{
	int len_a;
	int len_b;
	int lenb_buff;

	len_b = 0;
	len_a = ft_strlen(str_a);
	if (len_a == 0)
		return ((char *)str_b);
	while (str_b[len_b] != '\0')
	{
		len_a = 0;
		lenb_buff = len_b;
		while (str_b[len_b] == str_a[len_a])
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
