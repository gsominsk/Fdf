/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:54:05 by gsominsk          #+#    #+#             */
/*   Updated: 2017/01/03 15:54:36 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../src_lib/libft.h"

char	*ft_strjoin_s(char *s1, char const *s2)
{
	size_t	s1_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	str = ft_strnew(s1_len + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	str = ft_strcat(str, s1);
	ft_strcat(str + s1_len, s2);
	free(s1);
	return (str);
}

int		check_static(char **str, char **line)
{
	int		i;
	char	*temp;

	i = -1;
	if (*str)
	{
		temp = ft_strdup(*str);
		while (temp[++i])
			if (temp[i] == '\n')
			{
				*line = ft_strsub(*str, 0, i);
				free(temp);
				temp = (char *)malloc(sizeof(char) * ft_strlen(*str));
				ft_strcpy(temp, ft_strsub(*str, i + 1, ft_strlen(*str)));
				ft_strdel(str);
				*str = ft_strdup(temp);
				free(temp);
				return (1);
			}
		free(temp);
	}
	return (0);
}

int		check_end(char **str, char **line)
{
	if (check_static(str, line) == 1)
		return (1);
	if (*str != NULL && *str[0] != '\n' && *str[0] != '\0')
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (1);
	}
	*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*fd_arr[4096];
	char		str[BUFF_SIZE + 1];
	int			fp_1;

	if ((fd < 0) || ((fp_1 = read(fd, &str, 0)) < 0))
		return (-1);
	if (check_static(&fd_arr[fd], line) == 1)
		return (1);
	while ((fp_1 = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[fp_1] = '\0';
		if (!fd_arr[fd])
			fd_arr[fd] = ft_strdup(str);
		else
			fd_arr[fd] = ft_strjoin_s(fd_arr[fd], str);
		if (check_static(&fd_arr[fd], line) == 1)
			return (1);
	}
	if (fp_1 < BUFF_SIZE && check_end(&fd_arr[fd], line) == 0)
		return (0);
	return (1);
}
