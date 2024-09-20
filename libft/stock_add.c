/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:27:15 by ezahiri           #+#    #+#             */
/*   Updated: 2024/08/26 15:29:59 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stock_addr(void *addr, int mode)
{
	static t_list	*buffer;
	static void		*tmp;
	t_list			*new;

	if (mode == 1)
	{
		new = ft_lstnew(addr);
		if (!new)
			handle_error(addr);
		ft_lstadd_back(&buffer, new);
	}
	else if (mode == 2)
	{
		free(tmp);
		tmp = addr;
	}
	else
	{
		free(tmp);
		ft_lstclear(&buffer, free);
	}
}
