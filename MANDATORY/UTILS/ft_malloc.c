/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:19:41 by ezahiri           #+#    #+#             */
/*   Updated: 2024/11/03 15:21:55 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	*get_add(void *ptr)
{
	static void	*new;

	if (!ptr)
		return (new);
	else
	{
		new = ptr;
		return (new);
	}
}

void	handle_error(void *to_free)
{
	free(to_free);
	ft_putendl_fd("Mallloc failed", 2);
	ft_exit(1);
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
