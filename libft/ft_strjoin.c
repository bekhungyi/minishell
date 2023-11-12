/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:36:47 by bhung-yi          #+#    #+#             */
/*   Updated: 2022/09/15 23:32:45 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			l1;
	int			l2;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = malloc((l1 + l2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy (str, s1, l1 + l2 + 1);
	ft_strlcat (str, s2, l1 + l2 + 1);
	return (str);
}
