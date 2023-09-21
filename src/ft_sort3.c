/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:32:00 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/06/30 17:53:10 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list	**a)
{
	if (ft_lstsize(*a) > 2)
	{
		if ((*a)->data > (*a)->next->data
			&& (*a)->data > (*a)->next->next->data)
			ft_ra(a, 1);
		if ((*a)->next->data > (*a)->data
			&& (*a)->next->data > (*a)->next->next->data)
			ft_rra(a, 1);
	}
	if ((*a)->data > (*a)->next->data)
		ft_sa(a, 1);
}
