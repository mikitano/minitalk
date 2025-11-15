/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mkitano <marvin@42.fr>                     +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/07/31 16:40:11 by mkitano           #+#    #+#             */
/*   Updated: 2025/07/31 16:40:19 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str_dst;
	const char	*str_src;

	i = n;
	str_dst = (char *)dest;
	str_src = (const char *)src;
	if (dest == NULL && src == NULL && n != 0)
		return (NULL);
	if (n == 0)
		return (dest);
	if (str_dst > str_src)
	{
		while (i > 0)
		{
			str_dst[i - 1] = str_src[i - 1];
			i--;
		}
		return (dest);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
