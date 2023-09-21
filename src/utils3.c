/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:09:29 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/07/03 20:16:41 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) + start)
		len = ft_strlen(s) + start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*ptr;
	char	a;

	i = 0;
	a = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == a)
		{
			ptr = s + i;
			return (ptr);
		}
		i++;
	}
	if (a == '\0')
	{
		ptr = s + i;
		return (ptr);
	}
	return (NULL);
}
