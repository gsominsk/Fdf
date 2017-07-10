/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:06:44 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/29 19:32:39 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int symbol)
{
	int str_len;

	str_len = -1;
	if ((unsigned char)symbol == '\0')
	{
		while (string[++str_len] != '\0')
			;
		return ((char*)&string[str_len]);
	}
	while (string[++str_len] != '\0')
	{
		if (string[str_len] == symbol)
			return ((char*)&string[str_len]);
	}
	return (0);
}
