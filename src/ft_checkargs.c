/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:36:32 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 21:39:53 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check5(char **tver)
{
	int	i;

	i = 0;
	while (tver[i] && tver[i + 1])
	{
		if (ft_atoi(tver[i]) < ft_atoi(tver[i + 1]))
			i++;
		else
			return (1);
	}
	ft_atoi(tver[i]);
	return (0);
}

int	ft_check6(t_list *a)
{
	if (!a)
		return (-1);
	while (a->next)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return (1);
	}
	return (0);
}
