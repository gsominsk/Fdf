/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:20:15 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/22 15:58:13 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *string, int symbol)
{
	int str_len;

	str_len = -1;
	while (string[++str_len] != '\0')
		;
	while (str_len != 0)
	{
		if (string[str_len] == symbol)
			return ((char*)&string[str_len]);
		str_len--;
	}
	return (NULL);
}
