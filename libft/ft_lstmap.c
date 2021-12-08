/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:12:03 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/08 21:12:04 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnewnode(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

static void	ft_lstclearnode(t_list **lst, void (*del)(void *))
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

static void	ft_lstaddnode_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*cur_node;

	if (lst == NULL || f == NULL)
		return (NULL);
	cur_node = ft_lstnewnode(f(lst->content));
	if (cur_node == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new_node = ft_lstnewnode(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclearnode(&cur_node, del);
			return (NULL);
		}
		ft_lstaddnode_back(&cur_node, new_node);
		lst = lst->next;
	}
	return (cur_node);
}
