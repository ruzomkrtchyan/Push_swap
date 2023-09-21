/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:14:45 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 21:30:32 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**tver;

	a = NULL;
	b = NULL;
	tver = NULL;
	if (argc < 2)
		return (0);
	check_valid_av(argv);
	ft_main(argv, &a, tver, 1);
	ft_sort(&a);
	if (ft_lstsize(a) <= 3)
		ft_sort3(&a);
	if (ft_lstsize(a) >= 4 && ft_lstsize(a) <= 12)
		ft_sort12(&a, &b);
	if (ft_lstsize(a) > 12)
		ft_butterfly(&a, &b);
}
