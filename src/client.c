/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:47:05 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/28 21:11:18 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

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
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
		proc_client_error((ERR_ARGC));
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 1 || kill(server_pid, 0) == -1)
		proc_client_error(ERR_SERVER_PID);
	(void)argv;
	return (EXIT_SUCCESS);
}
