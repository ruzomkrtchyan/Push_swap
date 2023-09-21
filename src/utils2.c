/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:28:51 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/06/30 16:23:08 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len1;
	char		*ptr;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] && s2)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	free_malloc(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (0);
}

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	if (s[0] == '\0')
		count = 1;
	return (count);
}

int	fill(char **tmp, char *s, char c)
{
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i] && ++j)
			i++;
		if (s[i - 1] != c)
			tmp[m++] = ft_substr(s, i - j, j);
		if (m != 0 && !tmp[m - 1])
			return (free_malloc(tmp));
		j = 0;
	}
	tmp[m] = NULL;
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**tmp;

	if (!s)
		return (NULL);
	tmp = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (tmp == NULL)
		return (NULL);
	if (fill(tmp, s, c) == 0)
		return (NULL);
	return (tmp);
}
