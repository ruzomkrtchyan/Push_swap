/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:57:24 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 21:42:09 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*head;

	if (!a || !*a)
		return (0);
	head = (*a);
	temp = (*a)->next;
	if (temp)
		temp->prev = NULL;
	if (*b)
		(*b)->prev = head;
	head->next = (*b);
	*b = head;
	*a = temp;
	return (1);
}

void	ft_pa(t_list **a, t_list **b, int flag)
{
	if (ft_push(b, a) && flag == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b, int flag)
{
	if (ft_push(a, b) && flag == 1)
		write(1, "pb\n", 3);
}
