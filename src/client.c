/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:47:05 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/30 12:08:45 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

volatile sig_atomic_t	g_flag;

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_flag = 1;
	else if (signum == SIGUSR2)
		g_flag = -1;
}

void	send_bit(pid_t server_pid, int bit)
{
	int	sig;
	int	usleep_count;

	if (bit == 0)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	g_flag = 0;
	usleep_count = 0;
	kill(server_pid, sig);
	while (g_flag == 0)
	{
		if (usleep(100) == 0)
		{
			if (kill(server_pid, 0) == -1)
				proc_err(ERR_SERVER_TERMINATED);
			if (++usleep_count >= 10000)
				proc_err(ERR_SERVER_RESP_TIMEOUT);
		}
	}
	if (g_flag == -1)
		proc_err(ERR_MULT_CLIENTS);
}

void	send_char(pid_t server_pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = c >> i;
		bit = bit & 1;
		send_bit(server_pid, bit);
		i--;
	}
}

void	send_string(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		proc_err((ERR_ARGC));
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 1 || kill(server_pid, 0) == -1)
		proc_err(ERR_SERVER_PID);
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_string(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
