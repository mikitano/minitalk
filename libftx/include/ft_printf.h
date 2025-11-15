/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:31:44 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/15 17:19:00 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_dec(int nbr);
int		ft_putnbr_u(unsigned int nbr);
int		ft_putnbr_hex(unsigned long nbr, char specifier);
int		ft_address_hex(void *ptr);

int		ft_printf(const char *format, ...);

#endif
