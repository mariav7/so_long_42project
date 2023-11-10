# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:41:02 by mflores-          #+#    #+#              #
#    Updated: 2023/11/10 16:10:07 by mflores-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#	GENERAL																	   #
#------------------------------------------------------------------------------#
NAME = so_long
BONUS_NAME = bonus_so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f

#------------------------------------------------------------------------------#
#	HEADERS																	   #
#------------------------------------------------------------------------------#
HEADER_FILES = so_long
HEADER_PATH = includes/
HEADER = $(addsuffix .h, $(addprefix $(HEADER_PATH), $(HEADER_FILES)))
HEADER_INC = $(addprefix -I, $(HEADER_PATH) $(LIB_HEADER_PATH) /usr/include/$(MLX_HEADER_PATH))

BONUS_HEADER_FILES = bonus_so_long
BONUS_HEADER_PATH = bonus/includes/
BONUS_HEADER = $(addsuffix .h, $(addprefix $(BONUS_HEADER_PATH), $(BONUS_HEADER_FILES)))
BONUS_HEADER_INC = $(addprefix -I, $(BONUS_HEADER_PATH) $(LIB_HEADER_PATH) /usr/include/$(MLX_HEADER_PATH))

#------------------------------------------------------------------------------#
#	LIBFT																	   #
#------------------------------------------------------------------------------#
LIB_NAME = ft
LIB_PATH = libft/
LIB = -L$(LIB_PATH) -l$(LIB_NAME)
LIB_HEADER_PATH = $(LIB_PATH)includes/

#------------------------------------------------------------------------------#
#	MINILIBX																   #
#------------------------------------------------------------------------------#
MLX_HEADER_FILES = mlx mlx_init
MLX_HEADER_PATH = $(addsuffix .h, $(addprefix $(MLX_PATH), $(MLX_HEADER_FILES)))
MLX_NAME = mlx
MLX_PATH = mlx/
MLX_FLAGS = -lXext -lX11 -lm -lz
MLX = -L$(MLX_PATH) -l$(MLX_NAME) $(MLX_FLAGS) 

#------------------------------------------------------------------------------#
#	SO_LONG FILES															   #
#------------------------------------------------------------------------------#
SRCS_PATH = srcs/
SRCS_NAMES = main exit_handling key_hooks check_file get_map check_map \
			check_map2 render_map screen utils
SRCS = $(addsuffix .c, $(SRCS_NAMES))

OBJS_PATH = objs/
OBJS_NAMES = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAMES))

# Gcc/Clang will create these .d files containing dependencies
DEPS = $(OBJS:.o=.d)

#------------------------------------------------------------------------------#
#	SO_LONG BONUS FILES														   #
#------------------------------------------------------------------------------#
BONUS_SRCS_PATH = bonus/srcs/
BONUS_SRCS_NAMES = bonus_main bonus_exit_handling bonus_key_hooks \
					bonus_check_file bonus_get_map bonus_check_map \
					bonus_check_map2 bonus_render_map bonus_screen bonus_utils
BONUS_SRCS = $(addsuffix .c, $(BONUS_SRCS_NAMES))

BONUS_OBJS_PATH = $(addprefix $(OBJS_PATH), bonus/)
BONUS_OBJS_NAMES = $(BONUS_SRCS:.c=.o)
BONUS_OBJS = $(addprefix $(BONUS_OBJS_PATH), $(BONUS_OBJS_NAMES))

# Gcc/Clang will create these .d files containing dependencies
DEPS_BONUS = $(BONUS_OBJS:.o=.d)

#------------------------------------------------------------------------------#
#	BASIC RULES																   #
#------------------------------------------------------------------------------#
all: header $(NAME)
	@echo "\n$(BOLD)$(GREEN)[ ✔ ]\tSO_LONG$(RESET)"
	@echo "$(BOLD)\n▶ TO LAUNCH:\t./$(NAME) map_file.ber\n$(RESET)"

# Actual target of the binary - depends on all .o files
$(NAME): lib mlx $(HEADER) $(OBJS)
# Link all the object files
	@$(CC) $(FLAGS) $(HEADER_INC) $(OBJS) $(LIB) $(MLX) -o $(NAME)
# Build target for every single object file
# The potential dependency on header files is covered
# by calling `-include $(DEPS)`
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
# Create objs directory
	@mkdir -p $(OBJS_PATH)
  # The -MMD flags additionaly creates a .d file with
  # the same name as the .o file.
	@$(CC) $(FLAGS) $(HEADER_INC) -MMD -MP -o $@ -c $<
	@printf "$(YELLOW). . . compiling $(NAME) objects . . . => $(ITALIC)$(GREY)%-33.33s\r$(RESET)" $@

$(BONUS_NAME): lib mlx $(BONUS_HEADER) $(BONUS_OBJS)
	@$(CC) $(FLAGS) $(BONUS_HEADER_INC) $(BONUS_OBJS) $(LIB) $(MLX) -o $(BONUS_NAME)

$(BONUS_OBJS_PATH)%.o: $(BONUS_SRCS_PATH)%.c
	@mkdir -p $(BONUS_OBJS_PATH)
	@$(CC) $(FLAGS) $(BONUS_HEADER_INC) -MMD -MP -o $@ -c $<
	@printf "$(YELLOW). . . compiling $(BONUS_NAME) objects . . . => $(ITALIC)$(GREY)%-33.33s\r$(RESET)" $@

lib:
	@$(MAKE) --no-print-directory -C $(LIB_PATH)
	@echo "\n$(BOLD)$(GREEN)[ ✔ ]\tLIBFT$(RESET)"

mlx: $(MLX_PATH)
	@if [ ! -e "$(MLX_PATH)lib$(MLX_NAME).a" ]; then \
		echo "$(YELLOW). . . compiling Minilibx . . . $(RESET)"; \
		chmod +rx $(MLX_PATH)configure ; \
		$(MAKE) --no-print-directory -sC $(MLX_PATH); \
	fi
	@echo "$(BOLD)$(GREEN)[ ✔ ]\tMINILIBX$(RESET)"

bonus: header $(BONUS_NAME)
	@echo "\n$(BOLD)$(GREEN)[ ✔ ]\tBONUS SO_LONG$(RESET)"
	@echo "$(BOLD)\n▶ TO LAUNCH:\t./$(BONUS_NAME) map_file.ber\n$(RESET)"

clean:
	@if [ -d "$(OBJS_PATH)" ]; then \
		echo "$(YELLOW). . . cleaning objects . . .$(RESET)"; \
		$(MAKE) --no-print-directory clean -C $(LIB_PATH); \
		$(MAKE) --no-print-directory clean -sC $(MLX_PATH); \
		$(RM) -rd $(OBJS_PATH); \
	fi
	@echo "$(BOLD)$(GREEN)[ ✔ ]\tOBJECTS CLEANED$(RESET)"

fclean:	clean
	@if [ -e $(NAME) ]; then \
		echo "$(YELLOW). . . cleaning executable $(NAME) . . .$(RESET)"; \
		$(RM) $(NAME); \
	fi
	@if [ -e $(BONUS_NAME) ]; then \
		echo "$(YELLOW). . . cleaning executable $(BONUS_NAME) . . .$(RESET)"; \
		$(RM) $(BONUS_NAME); \
	fi
	@$(MAKE) --no-print-directory fclean -C $(LIB_PATH)
	@echo "$(BOLD)$(GREEN)[ ✔ ]\tALL CLEANED$(RESET)"

re:	fclean all

# Include all .d files
-include $(DEPS) $(DEPS_BONUS)

.PHONY:	all clean fclean re header lib mlx bonus

#------------------------------------------------------------------------------#
#	CUSTOM RULES															   #
#------------------------------------------------------------------------------#
GITHUB_PROF = https://github.com/mariav7

define HEADER_PROJECT
     _______.  ______            __        ______   .__   __.   _______ 
    /       | /  __  \          |  |      /  __  \  |  \ |  |  /  _____|
   |   (----`|  |  |  |         |  |     |  |  |  | |   \|  | |  |  __  
    \   \    |  |  |  |         |  |     |  |  |  | |  . `  | |  | |_ | 
.----)   |   |  `--'  |         |  `----.|  `--'  | |  |\   | |  |__| | 
|_______/     \______/   ______ |_______| \______/  |__| \__|  \______| 
                        |______|                                           
endef
export HEADER_PROJECT

header:
	clear
	@echo "$(MAGENTA)$$HEADER_PROJECT $(RESET)"
	@printf "\n$(BLUE)%20s Coded by:$(BLINK)$(WHITE) \e]8;;$(GITHUB_PROF)\e\\mflores-\e]8;;\e\\ $(RESET)\n\n"

# COLORS
RESET = \033[0m
WHITE = \033[37m
GREY = \033[90m
RED = \033[91m
DRED = \033[31m
GREEN = \033[92m
DGREEN = \033[32m
YELLOW = \033[93m
DYELLOW = \033[33m
BLUE = \033[94m
DBLUE = \033[34m
MAGENTA = \033[95m
DMAGENTA = \033[35m
CYAN = \033[96m
DCYAN = \033[36m

# FORMAT
BOLD = \033[1m
ITALIC = \033[3m
UNDERLINE = \033[4m
STRIKETHROUGH = \033[9m
BLINK	= \033[5m
