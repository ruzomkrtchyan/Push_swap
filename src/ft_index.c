/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:44:29 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 20:34:41 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap0(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	pivot_finder(int *nums, int l, int h)
{
	int	i;
	int	j;
	int	pivot;

	i = l + 1;
	j = h;
	pivot = nums[l];
	while (1)
	{
		while (i < h && pivot > nums[i])
			i++;
		while (j >= 0 && pivot < nums[j])
			j--;
		if (i >= j)
			break ;
		ft_swap0(&nums[i], &nums[j]);
	}
	ft_swap0(&nums[j], &nums[l]);
	return (j);
}

void	ft_quick(int *num, int l, int h)
{
	int	pivot;

	if (l < h)
	{
		pivot = pivot_finder(num, l, h);
		ft_quick(num, l, pivot);
		ft_quick(num, pivot + 1, h);
	}
}

void	ft_index(int *nums, t_list	**a, int n)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < n)
		{
			if (nums[i] == tmp->data)
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_sort(t_list **a)
{
	int		n;
	int		i;
	t_list	*tmp;
	int		*nums;

	tmp = *a;
	i = 0;
	n = ft_lstsize(tmp);
	nums = malloc(sizeof(int) * n);
	if (!nums)
		return ;
	while (tmp)
	{
		nums[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	ft_quick(nums, 0, n - 1);
	ft_index(nums, a, n);
	free(nums);
}
