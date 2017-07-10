/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:39:58 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/28 19:44:01 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	if (s == '\0')
		return ;
	i = 0;
	while (s[i] != '\0' && s != NULL)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
