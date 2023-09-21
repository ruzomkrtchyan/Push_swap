/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:20:50 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/06/05 19:00:27 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_lstclear(t_list *lst)
{
	t_list	*node;

	while (lst != NULL)
	{
		node = lst->next;
		free(lst);
		lst = node;
	}
	lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst ->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}
