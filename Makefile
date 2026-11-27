# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrpetr <andrpetr@marvin.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 18:24:15 by ejoguet           #+#    #+#              #
#    Updated: 2026/11/27 23:16:09 by andrpetr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBS_DIR = libs
OBJS_DIR = objs


SRCS_DIR = ./srcs/
MINILIB_DIR = ./srcs/minilib/
PRINTING_DIR = ./srcs/printing/

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

vpath %.c $(SRCS_DIR) $(MINILIB_DIR) $(PRINTING_DIR)


SRCS = \
$(addprefix $(SRCS_DIR), ft_printf.c flags_and_format.c format_helpers.c process_arg.c tools.c) \
$(addprefix $(MINILIB_DIR), ft_atoi.c ft_bzero.c ft_isdigit.c ft_putchar_unsigned.c ft_putstr.c ft_strlen.c) \
$(addprefix $(PRINTING_DIR), printing_logic.c print_dui_tools.c print_tools.c)
	
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
re: fclean all

bonus : re
.PHONY: all clean fclean re
