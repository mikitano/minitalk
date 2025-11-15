/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:43:00 by mkitano           #+#    #+#             */
/*   Updated: 2025/07/31 17:43:02 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptrs;
	unsigned char		char_c;

	i = 0;
	ptrs = (const unsigned char *)s;
	char_c = (unsigned char)c;
	while (i < n)
	{
		if (ptrs[i] == (char_c))
			return ((void *)&ptrs[i]);
		i++;
	}
	return (NULL);
}
