/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:46:47 by akyoshid          #+#    #+#             */
/*   Updated: 2025/01/28 22:52:59 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <aarch64-linux-gnu/bits/sigaction.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line_bonus.h"

typedef enum e_err_code
{
	ERR_ARGC,
	ERR_SERVER_PID,
	ERR_WRITE,
	ERR_SIGEMPTY_SET,
	ERR_SIGACTION,
}	t_err_code;

#endif
