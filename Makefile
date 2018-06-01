CC = gcc -g -fsanitize=address#-Wall -Werror -Wextra
INC=includes
INC_LIB=libft/includes

SRC_PATH = srcs
OBJ_PATH = srcs

LIBFT = libft/libft.a

NAME = salope
NAME_CLIENT = client
NAME_SERVER = server

INCLUDES = ./includes/utilities.h ./includes/server.h ./includes/client.h
INCLUDES_GCH = ./includes/utilities.h.gch

LIB_PATH = libft

SRC_M_SERVER_PATH		= server
SRC_M_CLIENT_PATH		= client
SRC_M_UTILITIES_PATH         = utilities

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

SRC_M_CLIENT		= client.c main_client.c manage_put_client.c create_client.c usage_builtin.c
SRC_M_SERVER		= server.c main_server.c  manage_builtin.c ft_put.c create_server.c check_good_path.c server_make.c ft_cd.c ft_mkdir.c ft_ls.c ft_pwd.c ft_quit.c
SRC_M_UTILITIES         =


SRC_M_C = $(addprefix ./$(SRC_M_CLIENT_PATH)/,         $(SRC_M_CLIENT))
SRC_M_S = $(addprefix ./$(SRC_M_SERVER_PATH)/,         $(SRC_M_SERVER))
SRC_M_U = $(addprefix ./$(SRC_M_UTILITIES_PATH)/,         $(SRC_M_UTILITIES))

###############################################
### OBJECT
##############################################

OBJ_M_CLIENT = $(patsubst %.c, %.o, $(SRC_M_CLIENT))
OBJ_M_SERVER = $(patsubst %.c, %.o, $(SRC_M_SERVER))
OBJ_M_UTILITIES = $(patsubst %.c, %.o, $(SRC_M_UTILITIES))

OBJ_M_C  = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_CLIENT))
OBJ_M_S =  $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_SERVER))
OBJ_M_U  = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_UTILITIES))

OBJ_ALL = $(OBJ_M_C) $(OBJ_M_S) $(OBJ_M_U)

####################################################
#################### RULES ########################
all: $(NAME)

$(NAME): lib $(OBJ_M_C) $(OBJ_M_S) $(OBJ_M_U)
	$(CC) $(OBJ_M_C) $(OBJ_M_U) $(LIBFT) -I $(INC) -I $(INC_LIB) -o $(NAME_CLIENT)
	$(CC) $(OBJ_M_S) $(OBJ_M_U) $(LIBFT) -I $(INC) -I $(INC_LIB) -o $(NAME_SERVER)

$(OBJ_M_C): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_CLIENT_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -I $(INC_LIB) -c $< -o $@

$(OBJ_M_S) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_SERVER_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -I $(INC_LIB) -c $< -o $@

$(OBJ_M_U) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_UTILITIES_PATH)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INC) -I $(INC_LIB) -c $< -o $@

lib:
	@cd $(LIB_PATH)

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

re : fclean $(NAME)
