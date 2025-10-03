/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:52:28 by mvassall          #+#    #+#             */
/*   Updated: 2024/12/11 11:45:43 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p_node;
	t_list	*p_node_next;

	if (lst == NULL || del == NULL)
		return ;
	p_node = *lst;
	while (p_node != NULL)
	{
		del(p_node->content);
		p_node_next = p_node->next;
		free(p_node);
		p_node = p_node_next;
	}
	*lst = NULL;
}

void	ft_lstclean(t_list **lst, void (*del)(void *))
{
	t_list	*p_node;
	t_list	*p_node_next;

	if (lst == NULL)
		return ;
	p_node = *lst;
	while (p_node != NULL)
	{
		if (del != NULL)
			del(p_node->content);
		p_node_next = p_node->next;
		free(p_node);
		p_node = p_node_next;
	}
	*lst = NULL;
}
