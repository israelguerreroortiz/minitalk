# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 17:26:41 by isrguerr          #+#    #+#              #
#    Updated: 2025/03/18 17:58:14 by isrguerr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRCS = utils.c client.c server.c

SERVER_SRCS = utils.c server.c
CLIENT_SRCS = utils.c client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) -L $(PRINTF_DIR) -lftprintf

$(CLIENT): $(CLIENT_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) -L $(PRINTF_DIR) -lftprintf

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re