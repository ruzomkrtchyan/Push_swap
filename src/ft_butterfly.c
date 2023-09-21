/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butterfly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:51:30 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/06/30 18:14:22 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_maxnode(t_list *b)
{
	t_list	*gnacox;
	int		i;

	i = ft_lstsize(b) - 1;
	gnacox = b;
	while (b)
	{
		if (b->index == i)
		{
			gnacox = b;
			break ;
		}
		b = b->next;
	}
	return (gnacox);
}

void	ft_karevor2(t_list **a, t_list **b, t_list *gnacox)
{
	int		i;

	i = ft_gettex(*b, gnacox);
	if (i <= ft_lstsize(*b) / 2)
	{
		while (*b != gnacox)
			ft_rb(b, 1);
		ft_pa(a, b, 1);
	}
	else
	{
		while (*b != gnacox)
			ft_rrb(b, 1);
		ft_pa(a, b, 1);
	}
}

int	ft_n(int n)
{
	int	root;
	int	log;
	int	step;

	root = 1;
	log = 1;
	step = 0;
	while (root * root <= n)
	{
		root++;
		step++;
	}
	while (log * 2 <= n)
	{
		log *= 2;
		step++;
	}
	return (step);
}

void	ft_butterfly(t_list **a, t_list **b)
{
	int	count;
	int	n;

	count = 0;
	while (*a)
	{
		n = ft_n(ft_lstsize(*a) - 1);
		if ((*a)->index <= count)
		{
			ft_pb(a, b, 1);
			ft_rb(b, 1);
			count++;
		}
		else if ((*a)->index <= count + n)
		{
			ft_pb(a, b, 1);
			count++;
		}
		else
			ft_ra(a, 1);
	}
	while (ft_lstsize(*b))
		ft_karevor2(a, b, ft_maxnode(*b));
}
