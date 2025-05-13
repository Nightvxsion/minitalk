# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 17:57:41 by marcgar2          #+#    #+#              #
#    Updated: 2025/05/13 18:01:56 by marcgar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS =	-Wextra -Werror -Wall
RM = rm -f

NAME_SERVER = server
SERVER_SRC = src/server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

NAME_CLIENT	= client
CLIENT_SRC = src/client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

UTILS_SRC = src/libft_utils.c
UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(SERVER_OBJ) $(UTILS_OBJ)
	@echo "Preparing $(NAME_SERVER)...:"
	@$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(NAME_SERVER)
	@echo "$(NAME_SERVER) created :)!"
	
$(NAME_CLIENT):	$(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "Preparing $(NAME_CLIENT)...:"
	@$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(NAME_CLIENT)
	@echo "$(NAME_CLIENT) created :)!"
	
clean:
	@echo "Removing files ***.o:"
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "Done :D!"
fclean: clean
	@echo "Removing execute files:"
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo ":Done :D!"
re: fclean all

.PHONY: all clean fclean re