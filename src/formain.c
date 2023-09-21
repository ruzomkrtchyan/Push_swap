/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:54:57 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 21:24:45 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_args(char **new, char **argv)
{
	char	*tmp;
	int		i;

	i = 1;
	while (argv[i] && argv)
	{
		tmp = *new;
		*new = ft_strjoin(*new, argv[i]);
		free(tmp);
		tmp = *new;
		*new = ft_strjoin(*new, " ");
		free(tmp);
		i++;
	}
}

void	ft_main(char **argv, t_list **a, char **tver, int flag)
{
	int		j;
	char	*new;
	t_list	*ban;

	new = NULL;
	join_args(&new, argv);
	tver = ft_check(new);
	if (flag == 1 && ft_check5(tver) == 0)
		exit (0);
	j = 0;
	while (tver[j])
	{
		ban = ft_lstnew(ft_atoi(tver[j]));
		free(tver[j]);
		ft_lstadd_back(a, ban);
		j++;
	}
	free (new);
	free (tver);
}
