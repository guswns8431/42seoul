/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:28:40 by hyson             #+#    #+#             */
/*   Updated: 2021/01/12 01:18:12 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*buf;
	t_list	*new;

	ret = NULL;
	buf = NULL;
	new = NULL;
	if (!f || !lst || !(ret = ft_lstnew(f(lst->content))))
		return (NULL);
	buf = ret;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		buf->next = new;
		buf = new;
		lst = lst->next;
	}
	return (ret);
}
