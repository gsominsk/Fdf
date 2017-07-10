# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apyvovar <apyvovar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 14:40:31 by apyvovar          #+#    #+#              #
#    Updated: 2017/03/19 13:23:34 by gsominsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################	LIBFT BASIC 	################################
LIB_DIR = src_lib/
LIB_FILES = ft_atoi ft_isascii ft_memchr ft_memmove ft_strcmp \
			ft_strlen ft_strnstr ft_toupper ft_bzero ft_isdigit \
			ft_memcmp ft_memset ft_strcpy ft_strncat ft_strrchr \
			ft_isalnum ft_isprint ft_memcpy ft_strcat ft_strdup \
			ft_strncmp ft_strstr ft_isalpha ft_memccpy ft_strchr \
			ft_strlcat ft_strncpy ft_tolower ft_itoa ft_putchar \
			ft_putendl_fd ft_putstr ft_strdel ft_striteri ft_strmapi \
			ft_strsplit ft_memalloc ft_putchar_fd ft_putnbr ft_putstr_fd \
			ft_strequ ft_strjoin ft_strnequ ft_strsub ft_memdel \
			ft_putendl ft_putnbr_fd ft_strclr ft_striter ft_strmap \
			ft_strnew ft_strtrim ft_lstadd ft_lstdel ft_lstdelone \
			ft_lstiter ft_lstmap ft_lstnew

LIB_SRC = $(addprefix $(LIB_DIR), $(LIB_FILES))
################################################################################
#
############################		GNL			################################
GNL_DIR = src_gnl/
GNL_FILES = get_next_line
GNL_SRC = $(addprefix $(GNL_DIR), $(GNL_FILES))
################################################################################
#
############################		PRINTF		################################
PRINTF_DIR = src_printf/
PRINTF_FILES = ft_printf dop_func/printf_tools dop_func/itoa_base output/printf_output_line_1 dop_func/tools \
				validation/main_validation validation/specifiers flags/first_part \
				flags/second_part flags/third_part functions/func_one functions/func_two \
				functions/func_three output/print_sharp output/printf_output_line_2 \
				output/string_output output/percent_output output/char_output output/wstring_output

PRINTF_SRC = $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
################################################################################
#
############################		GLOBAL		################################
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3
NAME = libft.a
HEADERS = includes
SRC = $(LIB_SRC) $(GNL_SRC) $(PRINTF_SRC)
################################################################################

all: $(NAME)

$(addsuffix .o, $(SRC)):
	$(CC) $(FLAGS) -I $(HEADERS) -o $@ -c $(@:.o=.c)

$(NAME): $(addsuffix .o, $(SRC))
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	/bin/rm -f $(addsuffix .o, $(SRC))

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
