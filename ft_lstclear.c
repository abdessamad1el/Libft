/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:08:15 by abel-all          #+#    #+#             */
/*   Updated: 2022/10/27 14:40:54 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *prev;
	t_list *curr;

	curr = *lst;
	while (curr)
	{
		prev = curr->next;
		del(curr->content);
		free(curr);
		curr = prev;
	}
	*lst = NULL;
}
