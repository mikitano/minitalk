/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:59:00 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/01 18:59:03 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	initial;
	size_t	final;

	initial = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while ((s1[initial]) && (ft_strchr(set, s1[initial])))
		initial++;
	if (s1[initial] == '\0')
		return (ft_strdup(""));
	final = ft_strlen(s1) - 1;
	while ((final > initial) && (ft_strchr(set, s1[final])))
		final--;
	str = ft_substr(s1, initial, (final - initial) + 1);
	return (str);
}
