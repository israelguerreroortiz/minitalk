/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:22:39 by isrguerr          #+#    #+#             */
/*   Updated: 2025/03/19 19:03:20 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "talk.h"

void	send_bit(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Put ./client, pid of server and a string\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
		send_bit(server_pid, *message++);
	send_bit(server_pid, '\0');
	return (0);
}
