/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:04:30 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/08 21:04:31 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;

	current_node = *lst;
	while (1)
	{
		*lst = current_node->next;
		del(current_node->content);
		free(current_node);
		if (*lst == NULL)
			break ;
		current_node = *lst;
	}
}
