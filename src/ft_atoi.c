/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:51:35 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 20:42:15 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check2(long res, int minus)
{
	if (res * minus > 2147483647 || res * minus < -2147483648)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

int	ft_atoi(char *str)
{
	int		i;
	int		minus;
	long	res;

	i = 0;
	res = 0;
	minus = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13 && str[i]) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		ft_check2(res, minus);
		i++;
	}
	return (res * minus);
}
