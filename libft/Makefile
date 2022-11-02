# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:08:43 by mflores-          #+#    #+#              #
#    Updated: 2022/11/02 12:24:48 by mflores-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

#FILES AND PATHS
INC_PATH = ./includes/
INC		= $(addprefix -I,$(INC_PATH))

SRC_NAME = ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_islower.c ft_isupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_split.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_tolower.c \
		ft_toupper.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c get_next_line_utils.c \
		ft_printf.c ft_printf_utils.c ft_printf_unsigned.c

SRC_PATH = ./srcs/
SRC	= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./objs/
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# RULES
all:	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@echo "$(YELLOW)[COMPILING]$(WHITE) libft"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_PATH)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

norme:
	norminette $(SRC) $(INC_PATH)libft.h

.PHONY:	all clean fclean re norme

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
