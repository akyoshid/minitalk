/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:47:02 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/28 21:16:27 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	proc_err(t_err_code err_code)
{
	if (err_code == ERR_WRITE)
		ft_dprintf(2, "minitalk: write: Failed to write(2) to standard output");
	exit(EXIT_FAILURE);
}

int	main(void)
{
	if (ft_dprintf(1, "Server PID: %d\n", getpid()) == -1)
		proc_err(ERR_WRITE);
	while (1)
		usleep(400);
	return (EXIT_SUCCESS);
}
