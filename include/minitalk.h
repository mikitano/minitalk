/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:22:50 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/15 17:33:09 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H	

# define _DEFAULT_SOURCE

# include "libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_node
{
	unsigned int	letter;
	int				bit;
}	t_node;

#endif