/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:27:30 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/16 16:34:06 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * our global struct is used for getting and saving the information
 * about the bits that we are receiving and rebuild the entire char.
*/
static t_node	g_data;

static void	ft_hander(int sig, siginfo_t *info, void *context)
{
	(void) context;
	if (sig == SIGUSR2)
		g_data.letter |= (1 << g_data.bit);
	g_data.bit++;
	if (g_data.bit == 8)
	{
		if (g_data.letter == '\0')
			write (1, "\n", 1);
		else
			write(1, &g_data, 1);
		g_data.bit = 0;
		g_data.letter = 0;
	}
	if (info && info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	ssig;

	g_data.letter = 0;
	g_data.bit = 0;
	ft_putstr_fd("server ID: ", 1);
	ft_putnbr_dec(getpid());
	write(1, "\n", 1);
	sigemptyset(&ssig.sa_mask);
	ssig.sa_sigaction = ft_hander;
	ssig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &ssig, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &ssig, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
