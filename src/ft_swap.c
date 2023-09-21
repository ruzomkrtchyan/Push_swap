/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:11:38 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/06/30 17:51:53 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list	*a)
{
	int	temp;

	if (a == NULL || a->next == NULL)
		return (0);
	temp = a->data;
	a->data = a->next->data;
	a->next->data = temp;
	temp = a->index;
	a->index = a->next->index;
	a->next->index = temp;
	return (1);
}

void	ft_sa(t_list **a, int flag)
{
	if (ft_swap(*a) && flag == 1)
		write (1, "sa\n", 3);
}

void	ft_sb(t_list **b, int flag)
{
	if (ft_swap(*b) && flag == 1)
		write (1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b, int flag)
{
	if (ft_swap(*a) && ft_swap(*b) && flag == 1)
		write(1, "ss\n", 3);
}
