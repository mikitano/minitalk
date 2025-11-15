/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:07:51 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/15 17:16:13 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_address_hex(void *ptr)
{
	int				count;
	unsigned long	ptr_long;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	ptr_long = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_putnbr_hex(ptr_long, 'x');
	return (count);
}
