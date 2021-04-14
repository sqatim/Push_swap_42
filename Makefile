NAME= push_swap

SRC_CHECKER_PATH= srcs_checker
SRC_PUSH_SWAP_PATH= srcs_push_swap

SRC_B_CHECKER_PATH= bonus_srcs_checker
SRC_B_PUSH_SWAP_PATH= bonus_srcs_push_swap

HDR_CHECKER_PATH= headers_checker
HDR_PUSH_SWAP_PATH= headers_push_swap

HDR_B_CHECKER_PATH= bonus_headers_checker
HDR_B_PUSH_SWAP_PATH= bonus_headers_push_swap

OBJ_CHECKER_PATH= obj_checker
OBJ_PUSH_SWAP_PATH= obj_push_swap
LIB_PATH= libft


SRC_CHECKER_NAME=checker.c\
			allocation.c\
			operation.c\
			check_affectation.c\
			get_next_line.c\
			get_next_line_utils.c\
			print.c\
			read.c\
			free.c\
			ft_space_split.c\
			ft_atol.c\

SRC_B_CHECKER_NAME=checker_bonus.c\
			allocation_bonus.c\
			operation_bonus.c\
			check_affectation_bonus.c\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			print_bonus.c\
			read_bonus.c\
			free_bonus.c\
			ft_space_split_bonus.c\
			ft_atol_bonus.c\

SRC_PUSH_SWAP_NAME=push_swap.c\
			allocation.c\
			operation.c\
			check_affectation.c\
			free.c\
			print.c\
			logic1.c\
			logic2.c\
			logic3.c\
			logic4.c\
			tools.c\
			ft_space_split.c\
			ft_atol.c\

SRC_B_PUSH_SWAP_NAME=push_swap_bonus.c\
			allocation_bonus.c\
			operation_bonus.c\
			check_affectation_bonus.c\
			free_bonus.c\
			print_bonus.c\
			logic1_bonus.c\
			logic2_bonus.c\
			logic3_bonus.c\
			logic4_bonus.c\
			tools_bonus.c\
			ft_space_split_bonus.c\
			ft_atol_bonus.c\
	

HDR_CHECKER_NAME=checker.h
HDR_PUSH_SWAP_NAME=push_swap.h 

HDR_B_CHECKER_NAME=checker_bonus.h
HDR_B_PUSH_SWAP_NAME=push_swap_bonus.h 

OBJ_CHECKER_NAME= $(SRC_CHECKER_NAME:.c=.o)
OBJ_PUSH_SWAP_NAME= $(SRC_PUSH_SWAP_NAME:.c=.o)

OBJ_B_CHECKER_NAME= $(SRC_B_CHECKER_NAME:.c=.o)
OBJ_B_PUSH_SWAP_NAME= $(SRC_B_PUSH_SWAP_NAME:.c=.o)

OBJ_CHECKER= $(addprefix $(OBJ_CHECKER_PATH)/,$(OBJ_CHECKER_NAME))
SRC_CHECKER= $(addprefix $(SRC_CHECKER_PATH)/,$(SRC_CHECKER_NAME))
HDR_CHECKER= $(addprefix $(HDR_CHECKER_PATH)/,$(HDR_CHECKER_NAME))

OBJ_B_CHECKER= $(addprefix $(OBJ_CHECKER_PATH)/,$(OBJ_B_CHECKER_NAME))
SRC_B_CHECKER= $(addprefix $(SRC_B_CHECKER_PATH)/,$(SRC_B_CHECKER_NAME))
HDR_B_CHECKER= $(addprefix $(HDR_B_CHECKER_PATH)/,$(HDR_B_CHECKER_NAME))

OBJ_PUSH_SWAP= $(addprefix $(OBJ_PUSH_SWAP_PATH)/,$(OBJ_PUSH_SWAP_NAME))
SRC_PUSH_SWAP= $(addprefix $(SRC_PUSH_SWAP_PATH)/,$(SRC_PUSH_SWAP_NAME))
HDR_PUSH_SWAP= $(addprefix $(HDR_PUSH_SWAP_PATH)/,$(HDR_PUSH_SWAP_NAME))

OBJ_B_PUSH_SWAP= $(addprefix $(OBJ_PUSH_SWAP_PATH)/,$(OBJ_B_PUSH_SWAP_NAME))
SRC_B_PUSH_SWAP= $(addprefix $(SRC_B_PUSH_SWAP_PATH)/,$(SRC_B_PUSH_SWAP_NAME))
HDR_B_PUSH_SWAP= $(addprefix $(HDR_B_PUSH_SWAP_PATH)/,$(HDR_B_PUSH_SWAP_NAME))

LIB= libft.a
FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a

H_CHECKER_FLAG= -I $(HDR_CHECKER_PATH)
H_PUSH_SWAP_FLAG= -I $(HDR_PUSH_SWAP_PATH)

H_B_CHECKER_FLAG= -I $(HDR_B_CHECKER_PATH)
H_B_PUSH_SWAP_FLAG= -I $(HDR_B_PUSH_SWAP_PATH)

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

bonus : lib $(LIB_PATH)/$(LIB) $(OBJ_B_CHECKER) $(OBJ_B_PUSH_SWAP)
	@rm -rf checker
	@rm -rf $(NAME)
	@$(COMP) -g $(H_B_CHECKER_FLAG) $(OBJ_B_CHECKER) $(LLIB_FLAG) -o checker
	@$(COMP) -g $(H_B_PUSH_SWAP_FLAG) $(OBJ_B_PUSH_SWAP) $(LLIB_FLAG) -o $@
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

$(OBJ_CHECKER_PATH)/%.o: $(SRC_B_CHECKER_PATH)/%.c $(HDR_B_CHECKER)
	@mkdir -p $(OBJ_CHECKER_PATH) 
	@$(COMP) -g $(FLAGS) $(H_B_CHECKER_FLAG) -g -o $@ -c $<


$(OBJ_PUSH_SWAP_PATH)/%.o:  $(SRC_PUSH_SWAP_PATH)/%.c $(HDR_PUSH_SWAP)
	@mkdir -p $(OBJ_PUSH_SWAP_PATH) 
	@$(COMP) -g $(FLAGS) $(H_PUSH_SWAP_FLAG) -g -o $@ -c $<

$(OBJ_PUSH_SWAP_PATH)/%.o:  $(SRC_B_PUSH_SWAP_PATH)/%.c $(HDR_B_PUSH_SWAP)
	@mkdir -p $(OBJ_PUSH_SWAP_PATH) 
	@$(COMP) -g $(FLAGS) $(H_B_PUSH_SWAP_FLAG) -g -o $@ -c $<

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