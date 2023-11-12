/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:47:44 by bhung-yi          #+#    #+#             */
/*   Updated: 2022/08/04 18:06:15 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	i = ft_strlen(s);
	if ((unsigned char) c == '\0')
		return ((char *) s + i);
	while (i-- > 0)
	{
		if (*(s + i) == (unsigned char) c)
			return ((char *) s + i);
	}
	return ((char *) NULL);
}
