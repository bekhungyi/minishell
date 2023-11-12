/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:14:33 by bhung-yi          #+#    #+#             */
/*   Updated: 2022/09/21 18:28:14 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	p = (void *)malloc(count * size);
	if (!p)
		return (0);
	ft_bzero (p, count * size);
	return (p);
}
