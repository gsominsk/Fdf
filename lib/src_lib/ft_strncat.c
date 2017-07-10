/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:51:45 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/28 14:19:18 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strncat(char *destination, const char *append, size_t n)
{
	size_t	dest_length;
	size_t	app_length;

	dest_length = ft_strlen(destination);
	app_length = 0;
	while (((append[app_length] != '\0')
			|| (destination[dest_length] != '\0'))
			&& (app_length < n))
	{
		destination[dest_length] = append[app_length];
		dest_length++;
		app_length++;
	}
	destination[dest_length] = '\0';
	return (destination);
}
