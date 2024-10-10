/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hasn <sel-hasn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:19:41 by ezahiri           #+#    #+#             */
/*   Updated: 2024/10/04 15:55:48 by sel-hasn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_error(void *to_free)
{
	free(to_free);
	ft_malloc(0, 0);
	ft_putendl_fd("Mallloc failed", 2);
	exit(1);
}

void	*ft_malloc(size_t size, int mod)
{
	static t_list	*head;
	void			*ptr;
	t_list			*new;

	ptr = NULL;
	if (mod == 1)
	{
		ptr = malloc(size);
		if (!ptr)
			handle_error(ptr);
		new = ft_lstnew(ptr);
		if (!new)
			handle_error(ptr);
		ft_lstadd_back(&head, new);
		return (ptr);
	}
	else
		ft_lstclear(&head, free);
	return (NULL);
}