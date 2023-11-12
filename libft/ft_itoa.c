/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:37:57 by bhung-yi          #+#    #+#             */
/*   Updated: 2022/09/15 23:22:50 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*ptr;
	long	num;

	size = get_len(n);
	num = n;
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	if (n == 0)
	{
		ptr[0] = '0';
	}
	ptr[size--] = '\0';
	while (num)
	{
		ptr[size--] = (num % 10) + 48;
		num /= 10;
	}
	return (ptr);
}
