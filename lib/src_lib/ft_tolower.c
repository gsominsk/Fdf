/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:42:03 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/22 12:47:21 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int character)
{
	if (character >= 'a' && character <= 'z')
		return (character);
	else if (character >= 'A' && character <= 'Z')
		return (character + 32);
	else
		return (character);
}
