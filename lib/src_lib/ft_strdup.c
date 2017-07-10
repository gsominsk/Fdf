/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:51:20 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/29 19:24:19 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		count;
	char	*str_buff;

	if ((str_buff = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1)))
		== NULL)
		return (NULL);
	count = -1;
	while (str[++count])
		str_buff[count] = str[count];
	str_buff[count] = '\0';
	return (str_buff);
}
