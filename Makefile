# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alhelson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 00:44:24 by alhelson          #+#    #+#              #
#    Updated: 2018/06/07 22:35:33 by alhelson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra
INC=includes
INC_LIB=libft/includes

SRC_PATH = srcs
OBJ_PATH = srcs

NAME = vital
NAME_CLIENT = client
NAME_SERVER = server

INCLUDES = ./includes/server.h ./includes/client.h
INCLUDES_GCH = ./includes/server.h.gch ./includes/client.h.gch

LIB_PATH = libft

SRC_M_SERVER_PATH		= server
SRC_M_CLIENT_PATH		= client

#################################################
### COLOR
##################################################
COL_BLACK       = \033[1;30m
COL_RED         = \033[1;31m
COL_GREEN       = \033[1;32m
COL_YELLOW      = \033[1;33m
COL_BLUE        = \033[1;34m
COL_PURPLE      = \033[1;35m
COL_WHITE       = \033[1;37m

################################################
### SOURCES
###############################################

SRC_M_CLIENT		= client.c main_client.c manage_put_client.c manage_get_client.c create_client.c usage_builtin.c make_client.c remaster_prompt.c my_send_and_recv.c
SRC_M_SERVER		= server.c main_server.c  manage_builtin.c ft_put.c create_server.c server_make.c ft_cd.c ft_mkdir.c ft_ls.c ft_pwd.c ft_quit.c ft_get.c network.c get_server_make.c

SRC_M_C = $(addprefix ./$(SRC_M_CLIENT_PATH)/,         $(SRC_M_CLIENT))
SRC_M_S = $(addprefix ./$(SRC_M_SERVER_PATH)/,         $(SRC_M_SERVER))

###############################################
### OBJECT
##############################################

OBJ_M_CLIENT = $(patsubst %.c, %.o, $(SRC_M_CLIENT))
OBJ_M_SERVER = $(patsubst %.c, %.o, $(SRC_M_SERVER))

OBJ_M_C  = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_CLIENT))
OBJ_M_S =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_SERVER))

OBJ_ALL = $(OBJ_M_C) $(OBJ_M_S)

####################################################
#################### RULES ########################
.PHONY: all libft clean fclean re

all: lib $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_M_C) $(OBJ_M_S)
	$(CC) $(OBJ_M_C) $(OBJ_M_U) -L ./libft -lft -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_M_C) $(OBJ_M_S)
	$(CC) $(OBJ_M_S) $(OBJ_M_U) -L ./libft -lft -o $(NAME_SERVER)

$(OBJ_M_C): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_CLIENT_PATH)%.c
	$(CC) $(CFLAGS) -I$(INC) -I $(INC_LIB) -c $< -o $@

$(OBJ_M_S) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_SERVER_PATH)%.c
	$(CC) $(CFLAGS) -I$(INC) -I $(INC_LIB) -c $< -o $@

lib:
	@cd $(LIB_PATH) && make

cleanlib:
	@cd $(LIB_PATH) && make clean
	@echo "$(COL_WHITE)[ CLEAN LIBFT ]\n"

fcleanlib: cleanlib
	@cd $(LIB_PATH) && make fclean
	@echo "$(COL_WHITE)[ FCLEAN LIBFT ]\n"

clean: cleanlib
	rm -rf $(OBJ_ALL) $(OBJ_M_M) $(INCLUDES_GCH)

fclean: fcleanlib clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re : fclean all
