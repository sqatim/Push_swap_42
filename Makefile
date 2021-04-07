NAME= push_swap
SRC_CHECKER_PATH= srcs_checker
SRC_PUSH_SWAP_PATH= srcs_push_swap
HDR_CHECKER_PATH= headers_checker
HDR_PUSH_SWAP_PATH= headers_push_swap
OBJ_CHECKER_PATH= obj_checker
OBJ_PUSH_SWAP_PATH= obj_push_swap
LIB_PATH= libft


SRC_CHECKER_NAME=checker.c\
			allocation.c\
			operation.c\
			check_affectation.c\
			print.c\
			read.c\
			free.c\

SRC_PUSH_SWAP_NAME=push_swap.c\
			allocation.c\
			operation.c\
			check_affectation.c\
			free.c\
			print.c\
			logic2.c\
			tools.c\

		

		

HDR_CHECKER_NAME=checker.h
HDR_PUSH_SWAP_NAME=push_swap.h 

OBJ_CHECKER_NAME= $(SRC_CHECKER_NAME:.c=.o)
OBJ_PUSH_SWAP_NAME= $(SRC_PUSH_SWAP_NAME:.c=.o)

OBJ_CHECKER= $(addprefix $(OBJ_CHECKER_PATH)/,$(OBJ_CHECKER_NAME))
SRC_CHECKER= $(addprefix $(SRC_CHECKER_PATH)/,$(SRC_CHECKER_NAME))
HDR_CHECKER= $(addprefix $(HDR_CHECKER_PATH)/,$(HDR_CHECKER_NAME))

OBJ_PUSH_SWAP= $(addprefix $(OBJ_PUSH_SWAP_PATH)/,$(OBJ_PUSH_SWAP_NAME))
SRC_PUSH_SWAP= $(addprefix $(SRC_PUSH_SWAP_PATH)/,$(SRC_PUSH_SWAP_NAME))
HDR_PUSH_SWAP= $(addprefix $(HDR_PUSH_SWAP_PATH)/,$(HDR_PUSH_SWAP_NAME))

LIB= libft.a
# FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_CHECKER_FLAG= -I $(HDR_CHECKER_PATH)

H_PUSH_SWAP_FLAG= -I $(HDR_PUSH_SWAP_PATH)

COMP= gcc

all: lib  $(NAME) 

$(NAME) : $(LIB_PATH)/$(LIB) $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)
	@rm -rf checker
	@rm -rf $(NAME)
	@$(COMP) -g $(H_CHECKER_FLAG) $(OBJ_CHECKER) $(LLIB_FLAG) -o checker
	@$(COMP) -g $(H_PUSH_SWAP_FLAG) $(OBJ_PUSH_SWAP) $(LLIB_FLAG) -o $@
	@echo "										    Made by : \033[1;91mSqatim\033[m"
	@echo "	                                                                                                      "  
	@echo ",-.----.                                                                                               " 
	@echo "\    /  \                             ,---,              .--.--.                                       " 
	@echo "|   :    \                          ,--.' |             /  /    '.                           ,-.----.  " 
	@echo "|   |  .\ :         ,--,            |  |  :            |  :  / . /          .---.            \    /  \ " 
	@echo ".   :  |: |       ,'_ /|   .--.--.  :  :  :            ;  |  |--'          /. ./|            |   :    |" 
	@echo "|   |   \ :  .--. |  | :  /  /    ' :  |  |,--.        |  :  ;_         .-'-. ' |  ,--.--.   |   | .\ :" 
	@echo "|   : .   /,'_ /| :  . | |  :  /'./ |  :  '   |         \  \    '.     /___/ \: | /       \  .   : |: |" 
	@echo ";   | |'-' |  ' | |  . . |  :  ;_   |  |   /' :          '----.   \ .-'.. '   ' ..--.  .-. | |   |  \ :" 
	@echo "|   | ;    |  | ' |  | |  \  \    '.'  :  | | |          __ \  \  |/___/ \:     ' \__\/: . . |   : .  |" 
	@echo ":   ' |    :  | : ;  ; |   '----.   \  |  ' | :         /  /'--'  /.   \  ' .\    ,\" .--.; | :     |'-'" 
	@echo ":   : :    '  :  '--'   \ /  /'--'  /  :  :_:,'        '--'.     /  \   \   ' \ |/  /  ,.  | :   : :   " 
	@echo "|   | :    :  ,      .-./'--'.     /|  | ,'              '--'---'    \   \  |--\";  :   .'   \|   | :   " 
	@echo "'---'.|     '--'----'      '--'---' '--''                             \   \ |   |  ,     .-./'---'.|   " 
	@echo "  '---'                                                                '---\"     '--'---'      '---'   " 
	@echo "                                                                                                       " 
	@echo "									 Compilation of $(NAME):  \033[1;32mOK\033[m"

lib:
	@make -sC $(LIB_PATH)

$(OBJ_CHECKER_PATH)/%.o:  $(SRC_CHECKER_PATH)/%.c $(HDR_CHECKER)
	@mkdir -p $(OBJ_CHECKER_PATH) 
	@$(COMP) -g $(FLAGS) $(H_CHECKER_FLAG) -g -o $@ -c $<

$(OBJ_PUSH_SWAP_PATH)/%.o:  $(SRC_PUSH_SWAP_PATH)/%.c $(HDR_PUSH_SWAP)
	@mkdir -p $(OBJ_PUSH_SWAP_PATH) 
	@$(COMP) -g $(FLAGS) $(H_PUSH_SWAP_FLAG) -g -o $@ -c $<

clean:
	@rm -rf $(OBJ_CHECKER_PATH)
	@rm -rf $(OBJ_PUSH_SWAP_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 

fclean: clean
	@rm -rf checker
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;31m>> checker & $(NAME) && all obbjects are deleted.\033[0m" 

re : fclean all