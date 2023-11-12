/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:37:42 by bhung-yi          #+#    #+#             */
/*   Updated: 2022/09/15 23:21:07 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			count++;
		else if (s[i] != c && i == 0)
			count++;
		i++;
	}
	return (count);
}

static char	**free_lst(char **lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
	return (NULL);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && n)
	{
		str[i] = s1[i];
		i++;
		n--;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	**lst;

	if (s == NULL)
		return (NULL);
	lst = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (lst == NULL)
		return (NULL);
	end = 0;
	i = 0;
	while (i < (wordcount(s, c)))
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		lst[i] = ft_strndup(s + start, end - start);
		if (lst[i++] == NULL)
			return (free_lst(lst));
	}
	lst[i] = NULL;
	return (lst);
}
