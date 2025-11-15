/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:01:43 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/04 17:01:47 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*convert(char *str, long numb, unsigned int len_s)
{
	while (len_s-- > 0)
	{
		str[len_s] = ((numb % 10) + '0');
		numb = numb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;
	long	numb;

	numb = n;
	len = count_numbers(numb);
	is_negative = 0;
	if (numb < 0)
	{
		numb = -numb;
		is_negative = 1;
	}
	str = malloc((len + is_negative + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + is_negative] = '\0';
	if (numb == 0)
		str[0] = '0';
	else
		str = convert(str, numb, (len + is_negative));
	if (is_negative == 1)
		str[0] = '-';
	return (str);
}
