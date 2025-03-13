/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:25:25 by isrguerr          #+#    #+#             */
/*   Updated: 2025/03/13 17:20:32 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "talk.h"
#include <sys/types.h>

int main(int argc, char **argv)
{
    pid_t  server_pid;
    char   *message;
    
    if (argc != 3)
    {
        ft_putstr_fd("Use ./client, pid of server and a string\n", 1);
        return (1);
    }
    return (0);
}