/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:47:05 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/28 22:54:05 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

volatile sig_atomic_t	g_flag = 0;

void	handler(int signum)
{
	(void)signum;
	return ;
}

void	proc_client_error(t_err_code err_code)
{
	if (err_code == ERR_ARGC)
	{
		ft_dprintf(2, "minitalk: Invalid number of arguments\n"
			"Usage: ./client SERVER_PID STRING\n");
		exit(2);
	}
	else if (err_code == ERR_SERVER_PID)
		ft_dprintf(2, "minitalk: Invalid server PID\n");
	else if (err_code == ERR_SIGEMPTY_SET)
		ft_dprintf(2, "minitalk: sigemptyset: Failed to sigemptyset(3)");
	else if (err_code == ERR_SIGEMPTY_SET)
		ft_dprintf(2, "minitalk: sigemptyset: Failed to sigemptyset(3)");
	else if (err_code == ERR_SIGACTION)
		ft_dprintf(2, "minitalk: sigaction: Failed to sigaction(2)");
	exit(EXIT_FAILURE);
}

void	send_string(pid_t server_pid, char *str)
{
	(void)server_pid;
	ft_printf("%s\n", str);
}

int	main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3)
		proc_client_error((ERR_ARGC));
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 1 || kill(server_pid, 0) == -1)
		proc_client_error(ERR_SERVER_PID);
	sa.sa_handler = handler;
	if (sigemptyset(&sa.sa_mask) == -1)
		proc_client_error(ERR_SIGEMPTY_SET);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		proc_client_error(ERR_SIGACTION);
	send_string(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
