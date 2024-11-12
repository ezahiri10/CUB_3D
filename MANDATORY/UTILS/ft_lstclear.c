/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 04:23:26 by ezahiri           #+#    #+#             */
/*   Updated: 2023/11/23 00:51:33 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst -> content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next ;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
	*lst = NULL;
}
