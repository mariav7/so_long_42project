# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:41:02 by mflores-          #+#    #+#              #
#    Updated: 2022/11/10 20:02:46 by mflores-         ###   ########.fr        #
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
PATH_BADMAP	= ./maps/bad_maps/
PATH_MAP	= ./maps/

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

test = valgrind --leak-check=full --error-exitcode=3 ./$(NAME) $(PATH_BADMAP)
test2 = valgrind --leak-check=full --error-exitcode=3 ./so_long ./maps/map1.ber;

test: header $(NAME)
	@echo "$(BLUE)TEST: NORMAL$(YELLOW)\n"
	@cat $(PATH_MAP)map1.ber
	@echo "$(WHITE)\n"
	@if $(test2) then \
        echo "\n$(GREEN)[ ✔ ] TEST$(WHITE)\n\n"; \
	else \
		echo "\n$(RED)[ ✗ ] TEST$(WHITE)\n\n"; \
    fi

tests: header $(NAME)
	@echo "\n$(YELLOW)... RUNNING ERROR TESTS ...$(WHITE)\n"

	@echo "$(BLUE)TEST: NOT VALID FILE$(YELLOW)\n"
	@cat $(PATH_BADMAP)not-valid-file.txt
	@echo "$(WHITE)\n"
	@if $(test)not-valid-file.txt; then \
		echo "\n$(RED)[ ✗ ] TEST NOT VALID FILE$(WHITE)\n\n"; \
	else \
        echo "\n$(GREEN)[ ✔ ] TEST NOT VALID FILE$(WHITE)\n\n"; \
    fi

	@echo "$(BLUE)TEST: EMPTY MAP$(YELLOW)\n"
	@cat $(PATH_BADMAP)emptymap.ber
	@echo "$(WHITE)\n"
	@if $(test)emptymap.ber; then \
        echo "\n$(RED)[ ✗ ] TEST EMPTY MAP$(WHITE)\n\n"; \
	else \
		echo "\n$(GREEN)[ ✔ ] TEST EMPTY MAP$(WHITE)\n\n"; \
    fi
	
	@echo "$(BLUE)TEST: NOT VALID CHARACTERS$(YELLOW)\n"
	@cat $(PATH_BADMAP)not-valid-characters.ber
	@echo "$(WHITE)\n"
	@if $(test)not-valid-characters.ber; then \
        echo "\n$(RED)[ ✗ ] TEST NOT VALID CHARACTERS$(WHITE)\n\n"; \
	else \
		echo "\n$(GREEN)[ ✔ ] TEST NOT VALID CHARACTERS$(WHITE)\n\n"; \
    fi

	@echo "$(BLUE)TEST: MIN. CHARACTERS$(YELLOW)\n"
	@cat $(PATH_BADMAP)not-min-characters.ber
	@echo "$(WHITE)\n"
	@if $(test)not-min-characters.ber; then \
        echo "\n$(RED)[ ✗ ] TEST MIN. CHARACTERS$(WHITE)\n\n"; \
	else \
		echo "\n$(GREEN)[ ✔ ] TEST MIN. CHARACTERS$(WHITE)\n\n"; \
    fi

	@echo "$(BLUE)TEST: IS NOT RECTANGULAR$(YELLOW)\n"
	@cat $(PATH_BADMAP)not-rectangular.ber
	@echo "$(WHITE)\n"
	@if $(test)not-rectangular.ber; then \
        echo "\n$(RED)[ ✗ ] TEST IS NOT RECTANGULAR$(WHITE)\n\n"; \
	else \
		echo "\n$(GREEN)[ ✔ ] TEST IS NOT RECTANGULAR$(WHITE)\n\n"; \
    fi

	@echo "$(BLUE)TEST: IS NOT WALLED$(YELLOW)\n"
	@cat $(PATH_BADMAP)not-walled.ber
	@echo "$(WHITE)\n"
	@if $(test)not-walled.ber; then \
        echo "\n$(RED)[ ✗ ] TEST IS NOT WALLED$(WHITE)\n\n"; \
	else \
		echo "\n$(GREEN)[ ✔ ] TEST IS NOT WALLED$(WHITE)\n\n"; \
    fi

	@echo "$(BLUE)TEST: NOT VALID PATH$(YELLOW)\n"
	@cat $(PATH_BADMAP)not-valid-path.ber
	@echo "$(WHITE)\n"
	@if $(test)not-valid-path.ber; then \
		echo "\n$(RED)[ ✗ ] TEST NOT VALID PATH$(WHITE)\n\n"; \
	else \
		echo "\n$(GREEN)[ ✔ ] TEST NOT VALID PATH$(WHITE)\n\n"; \
    fi

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
