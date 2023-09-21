/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:47:10 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 20:50:01 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_check(char *s)
{
	int		i;
	char	**tver;

	tver = NULL;
	i = 0;
	tver = ft_split(s, ' ');
	ft_check1(tver);
	return (tver);
}

void	ft_ex(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_check1(char **tver)
{
	int	i;
	int	j;

	i = 0;
	while (tver[i])
	{
		j = 0;
		if (tver[i][j] == '-' || tver[i][j] == '+')
		j++;
		if (tver[i][j] == '\0')
			ft_ex();
		while (tver[i][j])
		{
			if (tver[i][j] > 57 || tver[i][j] < 48)
				ft_ex();
			j++;
		}
		i++;
	}
	ft_check3(tver);
}

void	ft_check3(char **tver)
{
	int	i;
	int	j;

	i = 0;
	while (tver[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(tver[j]) == ft_atoi(tver[i]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}	
		i++;
	}	
}

void	check_valid_av(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == ' ' && str[i][j] != '\0')
			j++;
		if (str[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
