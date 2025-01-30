/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:47:03 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/30 02:15:59 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	proc_err(t_err_code err_code)
{
	if (err_code == ERR_ARGC)
	{
		ft_dprintf(2, "\033[31mminitalk: Invalid number of arguments\n"
			"Usage: ./client SERVER_PID STRING\n\033[0m");
		exit(2);
	}
	else if (err_code == ERR_SERVER_PID)
		ft_dprintf(2, "\033[31mminitalk: Invalid server PID\n\033[0m");
	else if (err_code == ERR_MULT_CLIENTS)
		ft_dprintf(2, "\033[31mminitalk: Server stopped responding "
				"due to multiple clients requesting communication\n\033[0m");
	else if (err_code == ERR_SERVER_TERMINATED)
		ft_dprintf(2, "\033[31mminitalk: Server was terminated "
				"and became no longer available.\n\033[0m");
	else if (err_code == ERR_SERVER_RESP_TIMEOUT)
		ft_dprintf(2, "\033[31mminitalk: Server did not respond "
				"within the expected time\n\033[0m");
	else if (err_code == ERR_CLIENT_RESP_TIMEOUT)
		ft_dprintf(2, "\033[31mminitalk: No signal received from the client "
				"within the expected time\n\033[0m");
	else if (err_code == ERR_WRITE)
		ft_dprintf(2, "\033[31mminitalk: write: "
				"Failed to write to standard output\n\033[0m");
	exit(EXIT_FAILURE);
}
