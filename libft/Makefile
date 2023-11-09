# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 16:08:43 by mflores-          #+#    #+#              #
#    Updated: 2023/11/09 12:19:09 by mflores-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#	GENERAL																   	   #
#------------------------------------------------------------------------------#
NAME	= libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

#------------------------------------------------------------------------------#
#	HEADERS																	   #
#------------------------------------------------------------------------------#
INC_PATH = includes/
INC		= $(addprefix -I,$(INC_PATH))

#------------------------------------------------------------------------------#
#	LIBFT FILES															   	   #
#------------------------------------------------------------------------------#
SRCS_NAME = ft_isascii ft_isprint ft_isalpha ft_isdigit ft_isalnum \
		ft_islower ft_isupper ft_strlen ft_strlcpy ft_strlcat \
		ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi \
		ft_memset ft_bzero ft_memcpy ft_split ft_memmove \
		ft_memchr ft_memcmp ft_strdup ft_calloc ft_itoa \
		ft_substr ft_strjoin ft_strtrim ft_strmapi ft_tolower \
		ft_toupper ft_striteri ft_putchar_fd ft_putstr_fd \
		ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
		ft_lstdelone ft_lstclear ft_lstiter ft_lstmap get_next_line get_next_line_utils \
		ft_printf ft_printf_utils ft_printf_unsigned

SRCS_PATH = srcs/
SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS_NAME = $(SRCS:.c=.o)
OBJS_PATH = objs/
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

#------------------------------------------------------------------------------#
#	BASIC RULES																   #
#------------------------------------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(FLAGS) $(INC) -MMD -o $@ -c $<
	@printf "$(YELLOW). . . compiling $(NAME) objects . . . => $(ITALIC)$(GREY)%-33.33s\r$(RESET)" $@

clean:
	@$(RM) -rd $(OBJS_PATH)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re

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
