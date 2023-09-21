/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:22:39 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/06 20:49:34 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_erro(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_kes(char *instr, t_list **a, t_list **b)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		ft_sa(a, 0);
	else if (ft_strcmp(instr, "sb\n") == 0)
		ft_sb(b, 0);
	else if (ft_strcmp(instr, "ss\n") == 0)
		ft_ss(a, b, 0);
	else if (ft_strcmp(instr, "pa\n") == 0)
		ft_pa(a, b, 0);
	else if (ft_strcmp(instr, "pb\n") == 0)
		ft_pb(a, b, 0);
	else if (ft_strcmp(instr, "ra\n") == 0)
		ft_ra(a, 0);
	else if (ft_strcmp(instr, "rb\n") == 0)
		ft_rb(b, 0);
	else if (ft_strcmp(instr, "rr\n") == 0)
		ft_rr(a, b, 0);
	else if (ft_strcmp(instr, "rra\n") == 0)
		ft_rra(a, 0);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		ft_rrb(b, 0);
	else if (ft_strcmp(instr, "rrr\n") == 0)
		ft_rrr(a, b, 0);
	else
		ft_erro();
}

void	ft_verj(t_list *a, t_list *b)
{
	if (ft_check6(a) == 0 && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**tver;
	char	*instr;

	a = NULL;
	b = NULL;
	tver = NULL;
	if (argc < 2)
		return (0);
	check_valid_av(argv);
	ft_main(argv, &a, tver, 0);
	while (1)
	{
		instr = get_next_line(0);
		if (!instr)
			break ;
		ft_kes(instr, &a, &b);
		free(instr);
	}
	ft_verj(a, b);
}
