/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:16:08 by ezahiri           #+#    #+#             */
/*   Updated: 2023/11/22 16:00:47 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		sz;
	t_list	*tmp;

	if (!lst)
		return (0);
	sz = 0;
	tmp = lst;
	while (tmp)
	{
		sz++;
		tmp = tmp -> next;
	}
	return (sz);
}
