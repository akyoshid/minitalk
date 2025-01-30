/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:47:03 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/30 00:37:07 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	proc_err(t_err_code err_code)
{
	if (err_code == ERR_ARGC)
	{
		ft_dprintf(2, "minitalk: Invalid number of arguments\n"
			"Usage: ./client SERVER_PID STRING\n");
		exit(2);
	}
	else if (err_code == ERR_SERVER_PID)
		ft_dprintf(2, "minitalk: Invalid server PID\n");
	else if (err_code == ERR_SERVER_IS_UNAVAILABLE)
		ft_dprintf(2, "minitalk: Server is not available "
				"due to dealing with a another client\n");
	else if (err_code == ERR_SERVER_BECAME_UNAVAILABLE)
		ft_dprintf(2, "minitalk: Server was terminated "
				"and became no longer available.\n");
	else if (err_code == ERR_SERVER_RESP_TIMEOUT)
		ft_dprintf(2, "minitalk: Server did not respond "
				"within the expected time\n");
	else if (err_code == ERR_CLIENT_RESP_TIMEOUT)
		ft_dprintf(2, "minitalk: No signal received from the client "
				"within the expected time\n");
	else if (err_code == ERR_WRITE)
		ft_dprintf(2, "minitalk: write: Failed to write to standard output\n");
	exit(EXIT_FAILURE);
}
