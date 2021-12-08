/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:08:51 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/08 21:08:51 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur_node;

	if (lst == NULL || f == NULL)
		return ;
	cur_node = lst;
	while (cur_node != NULL)
	{
		f(cur_node->content);
		cur_node = cur_node->next;
	}
}
