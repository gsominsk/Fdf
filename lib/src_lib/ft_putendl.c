/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:31:35 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/29 19:22:57 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int i;

	if (s == '\0')
		return ;
	i = 0;
	while (s[i] != '\0' && s != NULL)
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}
