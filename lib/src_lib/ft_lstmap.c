/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:12:20 by gsominsk          #+#    #+#             */
/*   Updated: 2016/11/30 15:56:22 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	p = f(lst);
	tmp = p;
	while ((lst = lst->next))
	{
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (p);
}
