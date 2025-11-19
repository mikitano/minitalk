/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:27:58 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/18 21:47:26 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** Global variable g_ack is used to synchronize the client with the server.
** It is updated inside the signal handler when an ACK is received.
** the client only sends the next bit after the server's confirmation.
*/
static volatile sig_atomic_t	g_ack = 0;

static void	ft_ack_on(int signal)
{
	if (signal == SIGUSR1)
		g_ack = 1;
	else if (signal == SIGUSR2)
	{
		ft_putstr_fd("Message received!\n", 1);
		exit(0);
	}
}

static void	ft_send_bit_to_server(pid_t pid, unsigned char c)
{
	int	bit;
	int	bit_index;

	bit = 0;
	bit_index = 0;
	if (pid <= 0 || kill(pid, 0) == -1)
		return ;
	while (bit_index < 8)
	{
		bit = (c >> bit_index) & 1;
		g_ack = 0;
		if (bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_ack == 0)
			pause();
		bit_index++;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	int					i;
	unsigned char		c;
	struct sigaction	ssig;

	if (ac != 3)
		return (1);
	pid = (pid_t)ft_atoi(av[1]);
	sigemptyset(&ssig.sa_mask);
	ssig.sa_flags = 0;
	ssig.sa_handler = ft_ack_on;
	if ((sigaction(SIGUSR1, &ssig, NULL) == -1) || (sigaction(SIGUSR2, &ssig,
				NULL) == -1))
		return (1);
	i = 0;
	while (1)
	{
		c = (unsigned char)av[2][i++];
		ft_send_bit_to_server(pid, c);
		if (c == '\0')
			break ;
	}
	while (1)
		pause();
	return (0);
}
