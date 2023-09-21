/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:37:40 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/04 16:12:35 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **a)
{
	t_list	*temp;
	t_list	*h;

	if (!a || !*a || !(*a)->next)
		return (0);
	temp = *a;
	h = (*a)->next;
	h->prev = NULL;
	while ((*a)->next)
		(*a) = (*a)->next;
	(*a)->next = temp;
	temp->prev = *a;
	temp->next = NULL;
	*a = h;
	return (1);
}

void	ft_ra(t_list **a, int flag)
{
	if (ft_rotate(a) && flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **b, int flag)
{
	if (ft_rotate(b) && flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b, int flag)
{
	if (ft_rotate(a) && ft_rotate(b) && flag == 1)
		write(1, "rr\n", 3);
}
