# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 11:31:38 by gsominsk          #+#    #+#              #
#    Updated: 2017/03/21 18:10:10 by gsominsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror -g -O3

FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit

FLAGS_X11 = -lmlx -lXext -lX11 -lm

LIB = lib/libft.a

SRCS = src_fdf/fdf.c src_fdf/ft_atoi_base.c src_fdf/key_func.c src_fdf/brazenham.c src_fdf/draw.c src_fdf/dop_func.c

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C lib/

libclean:
	make -C lib/ clean

libfclean:
	make -C lib/ fclean

$(NAME): $(BINS) 
	make -C lib/
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BINS)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all
