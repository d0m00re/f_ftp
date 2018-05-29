#################################################
### OPTION
##################################################

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
NAME_TEST = testouille
SRC_PATH = srcs

SRC_M_DISPLAY_PATH = ft_display
SRC_M_STRING_PATH = ft_string
SRC_M_STDLIB_PATH = ft_stdlib
SRC_M_LINKED_LIST_PATH = ft_linked_list
#SRC_M_GRAPH_PATH = ft_graph_interface
SRC_M_FILE_PATH = ft_file
SRC_M_INPUT_PATH = mtf_input

# lib perso
SRC_M_STRING_RESIZE_PATH = string_resize

# tab manage
SRC_M_TAB2D_PATH = ft_2d_tab
SRC_M_TAB2D_INT_PATH = $(SRC_M_TAB2D_PATH)/ft_2dtab_int

OBJ_PATH = objs
INC_PATH = includes
LIB_PATH = libft
INC=libft/includes
INC_2DTAB=$(INC_PATH)/ft_2d_tab

#################################################
### COLOR
##################################################

COL_BLACK		= \033[1;30m
COL_RED			= \033[1;31m
COL_GREEN		= \033[1;32m
COL_YELLOW		= \033[1;33m
COL_BLUE		= \033[1;34m
COL_PURPLE		= \033[1;35m
COL_WHITE		= \033[1;37m

#################################################
### SOURCES
##################################################

SRC_M_DISPLAY = ft_putchar.c ft_putstr.c
SRC_M_STRING =  ft_strlen.c ft_strcmp.c ft_strdup.c ft_strcpy.c ft_strcat.c replace.c\
		ft_strsplit.c\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isseparator.c ft_memset.c
SRC_M_STDLIB = ft_atoi.c
SRC_M_LINKED_LIST = ft_lstcreate_elem.c ft_lstpush_back.c   ft_lstpush_front.c ft_lstdestroy.c ft_lstdisplay.c
#SRC_M_GRAPH = ft_make_graph.c ft_destroy_graph.c ft_display_graph.c ft_graph_exist.c
SRC_M_FILE = ft_file_exist.c       ft_file_return_data.c ft_file_size.c ft_file_write.c ft_file_read.c

SRC_M_TAB2D_INT = make_2dtab_int.c destroy_2dtab_int.c get_value_2dtab_int.c set_value_2dtab_int.c

#SRC_M_STRING_RESIZE = string_resize_make.c string_resize_destroy.c string_resize_add_char.c string_resize_del_char.c

SRC_M_INPUT = mtf_input.c

#################################################
### OBJECT
##################################################

OBJ_M_DISPLAY =     $(patsubst %.c, %.o, $(SRC_M_DISPLAY))
OBJ_M_STRING =      $(patsubst %.c, %.o, $(SRC_M_STRING))
OBJ_M_STDLIB =      $(patsubst %.c, %.o, $(SRC_M_STDLIB))
OBJ_M_LINKED_LIST = $(patsubst %.c, %.o, $(SRC_M_LINKED_LIST))
#OBJ_M_GRAPH =       $(patsubst %.c, %.o, $(SRC_M_GRAPH))
OBJ_M_TAB2D_INT = $(patsubst %.c, %.o, $(SRC_M_TAB2D_INT))
OBJ_M_STRING_RESIZE = $(patsubst %.c, %.o, $(SRC_M_STRING_RESIZE))
OBJ_M_INPUT = $(patsubst %.c, %.o, $(SRC_M_INPUT))

OBJ_M_FILE = $(patsubst %.c, %.o, $(SRC_M_FILE))

#################################################
### FORMAT PATH
##################################################

SRC_DISPLAY = $(addprefix ./$(SRC_M_DISPLAY_PATH)/, $(SRC_M_DISPLAY))
OBJ_DISPLAY = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_DISPLAY))

SRC_STRING = $(addprefix ./$(SRC_M_STRING_PATH)/, $(SRC_M_STRING))
OBJ_STRING = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_STRING))

SRC_STDLIB = $(addprefix ./$(SRC_M_STDLIB_PATH)/, $(SRC_M_STDLIB))
OBJ_STDLIB = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_STDLIB))

SRC_LINKED_LIST = $(addprefix ./$(SRC_M_LINKED_LIST_PATH)/, $(SRC_M_LINKED_LIST))
OBJ_LINKED_LIST = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_LINKED_LIST))

#SRC_GRAPH = $(addprefix ./$(SRC_M_GRAPH_PATH)/, $(SRC_M_GRAPH))
#OBJ_GRAPH = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_GRAPH))

SRC_FILE = $(addprefix ./$(SRC_M_FILE_PATH)/, $(SRC_M_FILE))
OBJ_FILE = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_FILE))

SRC_TAB2D_INT = $(addprefix ./$(OBJ_PATH)/, $(SRC_M_TAB2D_INT))
OBJ_TAB2D_INT = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_TAB2D_INT))

#SRC_STRING_RESIZE = $(addprefix ./$(OBJ_PATH)/, $(SRC_M_STRING_RESIZE))
#OBJ_STRING_RESIZE = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_STRING_RESIZE))

SRC_INPUT = $(addprefix ./$(SRC_M_INPUT_PATH)/, $(SRC_M_INPUT))
OBJ_INPUT = $(addprefix ./$(OBJ_PATH)/, $(OBJ_M_INPUT))

OBJS =  $(OBJ_FILE) $(OBJ_DISPLAY) $(OBJ_STRING) $(OBJ_STDLIB) $(OBJ_LINKED_LIST) $(OBJ_GRAPH) $(OBJ_INPUT) $(OBJ_TAB2D_INT) #$(OBJ_STRING_RESIZE)

#################################################
### RULES
##################################################

all: $(NAME)

$(NAME) : $(OBJ_DISPLAY) $(OBJ_STRING) $(OBJ_STDLIB) $(OBJ_LINKED_LIST) $(OBJ_FILE) $(OBJ_TAB2D_INT) $(OBJ_INPUT)#$(OBJ_STRING_RESIZE)
	ar rc $(NAME) $(OBJS)

$(OBJ_DISPLAY): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_DISPLAY_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : DISPLAY ] \n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_STRING): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_STRING_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : STRING ] \n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_STDLIB): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_STDLIB_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : STDLIB ] \n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_LINKED_LIST): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_LINKED_LIST_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : LINKED LIST ] \n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_FILE): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_FILE_PATH)%.c
	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : FILE LIST ] \n"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

#$(OBJ_GRAPH): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_GRAPH_PATH)%.c
#	@echo "$(COL_BLUE)[ COMPILE & ASSEMBLE STEPS : GRAPH ] \n"
#	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(INC) -c $< -o $@

$(OBJ_TAB2D_INT): $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_TAB2D_INT_PATH)%.c
	echo  $(SRC_PATH)/$(SRC_M_TAB2D_INT_PATH)
	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -I $(INC_2DTAB) -c $< -o $@

#$(OBJ_STRING_RESIZE) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_STRING_RESIZE_PATH)%.c
#	echo  $(SRC_PATH)/$(SRC_M_STRING_RESIZE_PATH)
#	@$(CC) $(CFLAGS) -I $(INC_PATH) -I $(INC) -c $< -o $@

$(OBJ_INPUT) : $(OBJ_PATH)%.o : $(SRC_PATH)/$(SRC_M_INPUT_PATH)%.c
	echo  $(SRC_PATH)/$(SRC_M_INPUT_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

test_bitch :
	echo "fuck of"
	@$(CC) $(CFLAGS) main.c -I $(INC_PATH) -L . -lft -o $(NAME_TEST)

test_linkedlist :
	echo "miaou"
	@$(CC) $(CFLAGS) test_linked_list.c -I $(INC_PATH) -L . -lft -o SALOPE_DE_LINKED_LIST

clean:
	@echo "$(COL_YELLOW)[ CLEAN DIRECTORY ]\n"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(COL_YELLOW)[ CLEAN DIRECTORY AND $(NAME) ]\n"
	@rm -f $(NAME)

re : fclean all
