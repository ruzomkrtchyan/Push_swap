NAME 			= push_swap
BONUS			= checker
SRC_DIR			= src
SRC				= $(wildcard $(SRC_DIR)/*.c)
MAIN_SRC		= $(filter-out $(SRC_DIR)/bonus%.c, $(SRC))
BONUS_SRC		= $(filter-out $(SRC_DIR)/push_swap.c, $(SRC))
HEADER			= $(wildcard includes/*.h)
OBJ_DIR			= obj/main
BONUS_OBJ_DIR	= obj/bonus
OBJ_ROOT_DIR	= obj
INCS			= -I includes
MAIN_OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(MAIN_SRC))
BONUS_OBJ		= $(patsubst $(SRC_DIR)/%.c, $(BONUS_OBJ_DIR)/%.o, $(BONUS_SRC))
FLAGS 			= -Wall -Wextra -Werror  #-fsanitize=address -g
RM 				= rm -rf
CC 				= cc
MK				= mkdir -p

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) : $(SRC_DIR)
		$(MK) $(OBJ_DIR)

$(BONUS_OBJ_DIR) : $(SRC_DIR)
		$(MK) $(BONUS_OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER)
		$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER)
		$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME) : $(MAIN_OBJ)
		$(CC) $(FLAGS) $(INCS) -o $(NAME) $(MAIN_OBJ)

bonus:	$(BONUS_OBJ_DIR) $(BONUS)

$(BONUS) : $(BONUS_OBJ)
		$(CC) $(FLAGS) $(INCS) -o $(BONUS) $(BONUS_OBJ)

clean : 
		$(RM) $(OBJ_ROOT_DIR)

fclean : clean
		$(RM) $(NAME)
		$(RM) $(BONUS)

re : fclean all bonus


.PHONY: all clean fclean re bonus

# test:	$(NAME)
# 		$(eval ARG = $(shell jot -r 10 0 200000000))
# 		./push_swap $(ARG) | ./checker $(ARG)
# 		@echo -n "Instructions: "
# 		@./push_swap $(ARG) | wc -l