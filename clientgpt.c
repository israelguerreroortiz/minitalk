/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientgpt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:22:39 by isrguerr          #+#    #+#             */
/*   Updated: 2025/03/13 18:00:54 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void send_bit(pid_t server_pid, char c)
{
    for (int i = 7; i >= 0; i--)
    {
        if ((c >> i) & 1)
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
        usleep(100);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Uso: %s <PID> <mensaje>\n", argv[0]);
        return 1;
    }
    
    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];
    
    while (*message)
        send_bit(server_pid, *message++);
    send_bit(server_pid, '\0'); // Enviar terminador
    
    return 0;
}