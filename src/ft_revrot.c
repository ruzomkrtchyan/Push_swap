/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:14:33 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/04 16:13:37 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse(t_list **a)
{
	t_list	*head;

	if (!a || !*a || !(*a)->next)
		return (0);
	head = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->prev->next = NULL;
	(*a)->prev = NULL;
	(*a)->next = head;
	head->prev = *a;
	return (1);
}

void	ft_rra(t_list **a, int flag)
{
	if (ft_reverse(a) && flag == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b, int flag)
{
	if (ft_reverse(b) && flag == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b, int flag)
{
	if (ft_reverse(a) && ft_reverse(b) && flag == 1)
		write(1, "rrr\n", 4);
}
