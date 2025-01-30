/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:47:02 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/30 00:39:52 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	proc_bit_count_8(unsigned char *c, int *bit_count, pid_t *client_pid)
{
	if (*c == 0)
	{
		kill(*client_pid, SIGUSR1);
		*c = 0;
		*bit_count = 0;
		*client_pid = 0;
	}
	else
	{
		write(1, c, 1);
		*c = 0;
		*bit_count = 0;
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_count;
	static pid_t			client_pid;
	// When the client does not terminate correctly, client_pid is not reset,
	// so the server cannot accept bits from the new client.

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	else if (client_pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		// if (client_pid != 0)
		// 	kill(client_pid, SIGUSR1);
		return ;
	}
	if (signum == SIGUSR2)
		c = c | (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
		proc_bit_count_8(&c, &bit_count, &client_pid);
	if (client_pid != 0)
		kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					usleep_count;

	if (ft_dprintf(1, "Server PID: %d\n", getpid()) == -1)
		proc_err(ERR_WRITE);
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (usleep(100) == 0)
		{
			usleep_count++;
			if (usleep_count >= 300000)
				proc_err(ERR_CLIENT_RESP_TIMEOUT);
		}
	}
	return (EXIT_SUCCESS);
}
