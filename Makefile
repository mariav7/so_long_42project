# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:41:02 by mflores-          #+#    #+#              #
#    Updated: 2022/11/08 19:58:32 by mflores-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME	= so_long
CC		= cc
FLAGS	= -g -Wall -Wextra -Werror
RM		= rm -f

# HEADERS
HEADERS_PATHS 	= ./includes/ $(LIB_PATH)/includes/ $(MLX_PATH)
HEADERS			= $(addprefix -I,$(HEADERS_PATHS))

# LIBFT
LIB_NAME 	= ft
LIB_PATH	= ./libft/
LIB			= -L$(LIB_PATH) -l$(LIB_NAME)

# MINILIBX
MLX_NAME	= mlx_Linux
MLX_PATH 	= ./mlx-linux
MLX_FLAGS	= -lXext -lX11 -lmlx
MLX			= -L$(MLX_PATH) -l$(MLX_NAME) $(MLX_FLAGS) 

# SO_LONG
SRCS_NAMES 	= main.c exit_handling.c key_hooks.c check_file.c get_map.c \
			check_map.c check_map2.c
SRCS_PATH 	= ./srcs/
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_NAMES))
OBJS_NAMES	= $(SRCS_NAMES:.c=.o)
OBJS_PATH 	= ./objs/
OBJS		= $(addprefix $(OBJS_PATH), $(OBJS_NAMES))

# SO_LONG BONUS
BONUS_SRCS_NAMES 	= so_long_bonus.c
BONUS_SRCS_PATH 	= ./bonus/srcs/
BONUS_SRCS			= $(addprefix $(BONUS_SRCS_PATH), $(BONUS_SRCS_NAMES))
BONUS_OBJS_NAMES	= $(BONUS_SRCS_NAMES:.c=.o)
BONUS_OBJS_PATH 	= ./bonus/objs/
BONUS_OBJS			= $(addprefix $(BONUS_OBJS_PATH), $(BONUS_OBJS_NAMES))

# RULES
all:	header $(NAME)
	@echo "$(GREEN)[ ✔ ] $(MAGENTA)SO_LONG READY$(WHITE)"

$(NAME): lib mlx $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIB) $(HEADERS) $(MLX) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo "$(YELLOW)\n. . . COMPILING . . .$(WHITE) $(NAME)\n"
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(FLAGS) $(LIB) $(HEADERS) $(MLX) -o $@ -c $<

#$(BONUS_OBJS_PATH)%.o: $(BONUS_SRCS_PATH)%.c
#	@mkdir -p $(BONUS_OBJS_PATH)
#	@echo "$(YELLOW)\n. . . COMPILING . . .$(WHITE) $(NAME) bonus\n"
#	@$(CC) $(FLAGS) $(LIB) $(HEADERS) $(MLX) -o $@ -c $<

lib:
	@$(MAKE) --no-print-directory -C $(LIB_PATH)
	@echo "$(GREEN)[ ✔ ] LIBFT READY$(WHITE)"

mlx:
	@echo "$(YELLOW)\n. . . COMPILING . . . $(WHITE)minilibx\n"
	@$(MAKE) --no-print-directory -sC $(MLX_PATH)
	@echo "$(GREEN)[ ✔ ] MINILIBX READY$(WHITE)"

clean:
	@echo "$(YELLOW)\n. . . CLEANING . . .\n$(WHITE)"
	@$(MAKE) --no-print-directory clean -C $(LIB_PATH)
	@$(MAKE) --no-print-directory clean -sC $(MLX_PATH)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(RM) -r $(OBJS_PATH) $(BONUS_OBJS_PATH)
	@echo "$(GREEN)[ ✔ ][ OBJECTS CLEANED ]$(WHITE)"

fclean:	clean
	@echo "$(YELLOW)\n. . . CLEANING . . .\n$(WHITE)"
	@$(MAKE) --no-print-directory fclean -C $(LIB_PATH)
	@$(RM) $(NAME)
	@echo "$(GREEN)[ ✔ ][ ALL CLEANED ]$(WHITE)"

#bonus:	lib mlx $(BONUS_OBJS)
#		@echo "$(YELLOW). . . COMPILING . . .$(WHITE) so_long bonus\n"
#		@$(CC) $(FLAGS) $(BONUS_OBJS) $(LIB) $(HEADERS) $(MLX) -o $(NAME)
#		@echo "$(BLUE)[ ✔ ]$(CYAN)	SO_LONG BONUS READY"

re:	fclean all

define HEADER_PROJECT
$(MAGENTA)
     _______.  ______            __        ______   .__   __.   _______ 
    /       | /  __  \          |  |      /  __  \  |  \ |  |  /  _____|
   |   (----`|  |  |  |         |  |     |  |  |  | |   \|  | |  |  __  
    \   \    |  |  |  |         |  |     |  |  |  | |  . `  | |  | |_ | 
.----)   |   |  `--'  |         |  `----.|  `--'  | |  |\   | |  |__| | 
|_______/     \______/   ______ |_______| \______/  |__| \__|  \______| 
                        |______|                                           
$(WHITE)
endef
export HEADER_PROJECT

header:
		clear
		@echo "$$HEADER_PROJECT"

# CUSTOM RULES
FNCTION		= $(shell ls -l $(LIB_PATH)/srcs | grep ft_ | sed 's/^.*ft_//' | sed 's/..$$//')
FORBID		= printf $(FNCTION)
FN1			= $(addprefix -e $\" ,$(addsuffix $\", $(FORBID)))
FN2			= $(addprefix -e $\" ,$(addsuffix $\", $(FORBID)))

check:
	@grep -qe ${USER} -e ${MAIL} srcs/* includes/* && \
	echo "$(GREEN)[ ✔ ]$(WHITE)	Username and email" || echo "$(RED)[ ✗ ]$(BLUE)	Username and email"
	@cat $(SRCS) | grep -q $(FN1) $(FN2) && echo "$(RED)[ ✗ ]$(BLUE)	Forbidden functions" ||\
	echo "$(GREEN)[ ✔ ]$(WHITE)	Forbidden functions"
	@ls | grep -q -U $(NAME) && echo "$(GREEN)[ ✔ ]$(WHITE)	Executable name" ||\
	echo "$(RED)[ ✗ ]$(BLUE)	Executable name"
	@$(MAKE) norme | grep -B 1 Error && echo "$(RED)[ ✗ ]$(BLUE)	Norme" || \
	echo "$(GREEN)[ ✔ ]$(WHITE)	Norme"
	@ls $(LIB_PATH) | grep -q $(LIB_NAME) && echo "$(GREEN)[ ✔ ]$(WHITE)	Libft" ||\
	echo "$(RED)[ ✗ ]$(BLUE)	Libft"

norme:
	@$(MAKE) --no-print-directory -C $(LIB_PATH) norme
	norminette $(SRCS_PATH) ./includes/ $(LIB_PATH)/includes/
#$(BONUS_SRCS_PATH)

#test:		$(NAME)	
#	$(eval ARG = $(shell seq -50 50 | shuf -n 19))
#	@valgrind ./push_swap $(ARG)

#test3:		$(NAME)	
#	$(eval ARG = $(shell seq -50 50 | shuf -n 3))
#	./push_swap $(ARG) | ./checker_linux $(ARG)
#	@echo -n "$(BLUE)Instructions: $(WHITE)"
#	@./push_swap $(ARG) | wc -l

.PHONY:	all clean fclean re bonus norme check

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[0;94m
MAGENTA = \033[1;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
