/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:23:21 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/22 12:37:56 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (character);
	else if (character >= 'a' && character <= 'z')
		return (character - 32);
	else
		return (character);
}
