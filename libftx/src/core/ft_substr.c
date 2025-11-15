/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:01:17 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/01 16:01:19 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str2;

	i = 0;
	if (!s)
		return (NULL);
	if ((start >= ft_strlen(s)) || (len == 0))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	str2 = malloc((len + 1) * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	while ((s[i + start]) && (i < len))
	{
		str2[i] = s[i + start];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
