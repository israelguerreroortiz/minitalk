/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:23:22 by isrguerr          #+#    #+#             */
/*   Updated: 2025/03/18 18:40:16 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "talk.h"

void	signal_handler(int sig)
{
	static char	c = 0;
	static int	count_bits = 0;

	if (sig == SIGUSR2)
		c = c | (1 << (7 - count_bits));
	count_bits++;
	if (count_bits == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		count_bits = 0;
	}
}

int	main(void)
{
	ft_printf("Servidor en marcha. PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (42)
		pause();
	return (0);
}
