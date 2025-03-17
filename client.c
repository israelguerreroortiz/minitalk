/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:22:39 by isrguerr          #+#    #+#             */
/*   Updated: 2025/03/17 18:15:20 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"

//Esta funcion manda cada bit de un string 
void send_bit(pid_t server_pid, char c)
{
    for (int i = 7; i >= 0; i--)
    {
        if ((c >> i) & 1)
            kill(server_pid, SIGUSR2);
        else
            kill(server_pid, SIGUSR1);
        usleep(100); //funcion para después de cada iteracion, espere 100 microsegundos para que le de tiempo a procesar cada numero
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putstr_fd("Put ./client, pid of server and a message\n", 1);
        return (1);
    }
    
    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];
    
    while (*message)
        send_bit(server_pid, *message++);
    send_bit(server_pid, '\0'); // Enviar terminador
    
    return 0;
}