/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:46:47 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/30 01:39:29 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

typedef enum e_err_code
{
	ERR_ARGC,
	ERR_SERVER_PID,
	ERR_MULT_CLIENTS,
	ERR_SERVER_TERMINATED,
	ERR_SERVER_RESP_TIMEOUT,
	ERR_CLIENT_RESP_TIMEOUT,
	ERR_WRITE,
}	t_err_code;

void	proc_err(t_err_code err_code);

#endif
