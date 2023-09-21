/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:15:13 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/05 21:25:08 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void	ft_check1(char **tver);
void	ft_check3(char **tver);
char	**ft_check(char *s);
int		ft_atoi(char *str);
void	ft_check2(long res, int minus);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_sort(t_list **a);
void	ft_sa(t_list **a, int flag);
void	ft_sb(t_list **b, int flag);
void	ft_ss(t_list **a, t_list **b, int flag);
void	ft_ra(t_list **a, int flag);
void	ft_rb(t_list **b, int flag);
void	ft_rr(t_list **a, t_list **b, int flag);
void	ft_pa(t_list **a, t_list **b, int flag);
void	ft_pb(t_list **a, t_list **b, int flag);
void	ft_rra(t_list **a, int flag);
void	ft_rrb(t_list **b, int flag);
void	ft_rrr(t_list **a, t_list **b, int flag);
void	ft_sort3(t_list	**a);
void	ft_karevor(t_list **a, t_list **b, t_list *gnacox);
t_list	*ft_minnode(t_list *a);
void	ft_sort12(t_list **a, t_list **b);
int		ft_n(int n);
void	ft_butterfly(t_list **a, t_list **b);
int		ft_gettex(t_list *a, t_list *gnacox);
int		ft_check5(char **tver);
char	*ft_strchr(char *s, int c);
void	check_valid_av(char **str);
void	ft_main(char **argv, t_list **a, char **tver, int flag);

#endif