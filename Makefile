NAME= push_swap
SRC_PATH= srcs
HDR_PATH= headers
OBJ_PATH= obj
LIB_PATH= libft


SRC_NAME=main.c\
		

HDR_NAME=push_swap.h 

OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB= libft.a
FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_FLAG= -I $(HDR_PATH)

COMP= gcc

all: lib  $(NAME) 

$(NAME) : $(LIB_PATH)/$(LIB) $(OBJ)
	@rm -rf push_swap
	@$(COMP) -g $(H_FLAG) $(OBJ) $(LLIB_FLAG) -o $@
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

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) -g $(FLAGS) $(H_FLAG) -g -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;31m>> $(NAME) && all obbjects are deleted.\033[0m" 

re : fclean all