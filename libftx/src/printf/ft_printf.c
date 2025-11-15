/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:58:15 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/15 17:16:15 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char speci, va_list ap)
{
	if (speci == '%')
		return (ft_putchar(speci));
	else if (speci == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (speci == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (speci == 'p')
		return (ft_address_hex(va_arg(ap, void *)));
	else if ((speci == 'd') || (speci == 'i'))
		return (ft_putnbr_dec(va_arg(ap, int)));
	else if (speci == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if ((speci == 'x') || (speci == 'X'))
		return (ft_putnbr_hex((unsigned long)va_arg(ap, unsigned int), speci));
	else
		return (ft_putchar(speci));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	i = 0;
	va_start(ap, format);
	count = 0;
	if (!format)
		return (count);
	while (format[i] != '\0')
	{
		if ((format[i] == '%') && (ft_strchr("cspdiuxX%", format[++i])))
			count += print_format((format[i]), ap);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
