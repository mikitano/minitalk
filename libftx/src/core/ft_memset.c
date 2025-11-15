/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:35:40 by mkitano           #+#    #+#             */
/*   Updated: 2025/07/31 17:35:43 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*strb;
	int				i;

	i = 0;
	strb = (unsigned char *) b;
	while (len > 0)
	{
		strb[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
