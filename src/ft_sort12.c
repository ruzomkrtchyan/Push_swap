/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:56 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/06/30 17:53:53 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_minnode(t_list *a)
{
	t_list	*gnacox;

	gnacox = a;
	a = a->next;
	while (a)
	{
		if (a->index < gnacox->index)
			gnacox = a;
		a = a->next;
	}
	return (gnacox);
}

int	ft_gettex(t_list *a, t_list *gnacox)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a == gnacox)
			break ;
		i ++;
		a = a->next;
	}
	return (i);
}

void	ft_karevor(t_list **a, t_list **b, t_list *gnacox)
{
	int		i;

	i = ft_gettex(*a, gnacox);
	if (i <= ft_lstsize(*a) / 2)
	{
		while (*a != gnacox)
			ft_ra(a, 1);
		ft_pb(a, b, 1);
	}
	else
	{
		while (*a != gnacox)
			ft_rra(a, 1);
		ft_pb(a, b, 1);
	}
}

void	ft_sort12(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		ft_karevor(a, b, ft_minnode(*a));
	}
	ft_sort3(a);
	while (*b)
	{
		ft_pa(a, b, 1);
	}
}
