/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:15 by isrguerr          #+#    #+#             */
/*   Updated: 2025/03/18 18:40:59 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TALK_H
# define TALK_H

# include "limits.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	signal_handler(int sig);
void	send_bit(pid_t server_pid, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int nbr);

#endif
