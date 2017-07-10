# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsominsk <gsominsk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 17:08:59 by gsominsk          #+#    #+#              #
#    Updated: 2016/11/30 17:15:50 by gsominsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_atoi.c ./ft_isascii.c ./ft_memchr.c ./ft_memmove.c ./ft_strcmp.c \
./ft_strlen.c ./ft_strnstr.c ./ft_toupper.c ./ft_bzero.c ./ft_isdigit.c \
./ft_memcmp.c ./ft_memset.c ./ft_strcpy.c ./ft_strncat.c ./ft_strrchr.c \
./ft_isalnum.c ./ft_isprint.c ./ft_memcpy.c ./ft_strcat.c ./ft_strdup.c \
./ft_strncmp.c ./ft_strstr.c ./ft_isalpha.c ./ft_memccpy.c ./ft_strchr.c \
./ft_strlcat.c ./ft_strncpy.c ./ft_tolower.c ./ft_itoa.c ./ft_putchar.c \
./ft_putendl_fd.c ./ft_putstr.c ./ft_strdel.c ./ft_striteri.c ./ft_strmapi.c \
./ft_strsplit.c ./ft_memalloc.c ./ft_putchar_fd.c ./ft_putnbr.c ./ft_putstr_fd.c\
./ft_strequ.c ./ft_strjoin.c ./ft_strnequ.c ./ft_strsub.c ./ft_memdel.c \
./ft_putendl.c ./ft_putnbr_fd.c ./ft_strclr.c ./ft_striter.c ./ft_strmap.c \
./ft_strnew.c ./ft_strtrim.c ./ft_lstadd.c ./ft_lstdel.c ./ft_lstdelone.c \
./ft_lstiter.c ./ft_lstmap.c ./ft_lstnew.c

OBJECT = ./ft_atoi.o ./ft_isascii.o ./ft_memchr.o ./ft_memmove.o ./ft_strcmp.o \
./ft_strlen.o ./ft_strnstr.o ./ft_toupper.o ./ft_bzero.o ./ft_isdigit.o \
./ft_memcmp.o ./ft_memset.o ./ft_strcpy.o ./ft_strncat.o ./ft_strrchr.o \
./ft_isalnum.o ./ft_isprint.o ./ft_memcpy.o ./ft_strcat.o ./ft_strdup.o \
./ft_strncmp.o ./ft_strstr.o ./ft_isalpha.o ./ft_memccpy.o ./ft_strchr.o \
./ft_strlcat.o ./ft_strncpy.o ./ft_tolower.o ./ft_itoa.o ./ft_putchar.o \
./ft_putendl_fd.o ./ft_putstr.o ./ft_strdel.o ./ft_striteri.o ./ft_strmapi.o \
./ft_strsplit.o ./ft_memalloc.o ./ft_putchar_fd.o ./ft_putnbr.o ./ft_putstr_fd.o\
./ft_strequ.o ./ft_strjoin.o ./ft_strnequ.o ./ft_strsub.o ./ft_memdel.o \
./ft_putendl.o ./ft_putnbr_fd.o ./ft_strclr.o ./ft_striter.o ./ft_strmap.o \
./ft_strnew.o ./ft_strtrim.o ./ft_lstadd.o ./ft_lstdel.o ./ft_lstdelone.o \
./ft_lstiter.o ./ft_lstmap.o ./ft_lstnew.o

FLAGS = -Wall -Wextra -Werror -I ./

all: $(NAME)

$(NAME): ft_atoi.o ft_isascii.o ft_memchr.o ft_memmove.o ft_strcmp.o \
ft_strlen.o ft_strnstr.o ft_toupper.o ft_bzero.o ft_isdigit.o \
ft_memcmp.o ft_memset.o ft_strcpy.o ft_strncat.o ft_strrchr.o \
ft_isalnum.o ft_isprint.o ft_memcpy.o ft_strcat.o ft_strdup.o \
ft_strncmp.o ft_strstr.o ft_isalpha.o ft_memccpy.o ft_strchr.o \
ft_strlcat.o ft_strncpy.o ft_tolower.o ft_itoa.o ft_putchar.o \
ft_putendl_fd.o ft_putstr.o ft_strdel.o ft_striteri.o ft_strmapi.o \
ft_strsplit.o ft_memalloc.o ft_putchar_fd.o ft_putnbr.o ft_putstr_fd.o\
ft_strequ.o ft_strjoin.o ft_strnequ.o ft_strsub.o ft_memdel.o \
ft_putendl.o ft_putnbr_fd.o ft_strclr.o ft_striter.o ft_strmap.o \
ft_strnew.o ft_strtrim.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o \
ft_lstiter.o ft_lstmap.o ft_lstnew.o
	ar rc libft.a $(OBJECT)
	ranlib libft.a

ft_atoi.o: ./ft_atoi.c
	gcc -c $(FLAGS) ./ft_atoi.c

ft_isascii.o: ./ft_isascii.c
	gcc -c $(FLAGS) ./ft_isascii.c

ft_memchr.o: ./ft_memchr.c
	gcc -c $(FLAGS) ./ft_memchr.c

ft_memmove.o: ./ft_memmove.c
	gcc -c $(FLAGS) ./ft_memmove.c

ft_strcmp.o: ./ft_strcmp.c
	gcc -c $(FLAGS) ./ft_strcmp.c

ft_strlen.o: ./ft_strlen.c
	gcc -c $(FLAGS) ./ft_strlen.c

ft_strnstr.o: ./ft_strnstr.c
	gcc -c $(FLAGS) ./ft_strnstr.c

ft_toupper.o: ./ft_toupper.c
	gcc -c $(FLAGS) ./ft_toupper.c

ft_bzero.o: ./ft_bzero.c
	gcc -c $(FLAGS) ./ft_bzero.c

ft_isdigit.o: ./ft_isdigit.c
	gcc -c $(FLAGS) ./ft_isdigit.c

ft_memcmp.o: ./ft_memcmp.c
	gcc -c $(FLAGS) ./ft_memcmp.c

ft_memset.o: ./ft_memset.c
	gcc -c $(FLAGS) ./ft_memset.c

ft_strcpy.o: ./ft_strcpy.c
	gcc -c $(FLAGS) ./ft_strcpy.c

ft_strncat.o: ./ft_strncat.c
	gcc -c $(FLAGS) ./ft_strncat.c

ft_strrchr.o: ./ft_strrchr.c
	gcc -c $(FLAGS) ./ft_strrchr.c

ft_isalnum.o: ./ft_isalnum.c
	gcc -c $(FLAGS) ./ft_isalnum.c

ft_isprint.o: ./ft_isprint.c
	gcc -c $(FLAGS) ./ft_isprint.c

ft_memcpy.o: ./ft_memcpy.c
	gcc -c $(FLAGS) ./ft_memcpy.c

ft_strcat.o: ./ft_strcat.c
	gcc -c $(FLAGS) ./ft_strcat.c

ft_strdup.o: ./ft_strdup.c
	gcc -c $(FLAGS) ./ft_strdup.c

ft_strncmp.o: ./ft_strncmp.c
	gcc -c $(FLAGS) ./ft_strncmp.c

ft_strstr.o: ./ft_strstr.c
	gcc -c $(FLAGS) ./ft_strstr.c

ft_isalpha.o: ./ft_isalpha.c
	gcc -c $(FLAGS) ./ft_isalpha.c

ft_memccpy.o: ./ft_memccpy.c
	gcc -c $(FLAGS) ./ft_memccpy.c

ft_strchr.o: ./ft_strchr.c
	gcc -c $(FLAGS) ./ft_strchr.c

ft_strlcat.o: ./ft_strlcat.c
	gcc -c $(FLAGS) ./ft_strlcat.c

ft_strncpy.o: ./ft_strncpy.c
	gcc -c $(FLAGS) ./ft_strncpy.c

ft_tolower.o: ./ft_tolower.c
	gcc -c $(FLAGS) ./ft_tolower.c

ft_itoa.o: ./ft_itoa.c
	gcc -c $(FLAGS) ./ft_itoa.c

ft_putchar.o: ./ft_putchar.c
	gcc -c $(FLAGS) ./ft_putchar.c

ft_putendl_fd.o: ./ft_putendl_fd.c
	gcc -c $(FLAGS) ./ft_putendl_fd.c

ft_putstr.o: ./ft_putstr.c
	gcc -c $(FLAGS) ./ft_putstr.c

ft_strdel.o: ./ft_strdel.c
	gcc -c $(FLAGS) ./ft_strdel.c

ft_striteri.o: ./ft_striteri.c
	gcc -c $(FLAGS) ./ft_striteri.c

ft_strmapi.o: ./ft_strmapi.c
	gcc -c $(FLAGS) ./ft_strmapi.c

ft_strsplit.o: ./ft_strsplit.c
	gcc -c $(FLAGS) ./ft_strsplit.c

ft_memalloc.o: ./ft_memalloc.c
	gcc -c $(FLAGS) ./ft_memalloc.c

ft_putchar_fd.o: ./ft_putchar_fd.c
	gcc -c $(FLAGS) ./ft_putchar_fd.c

ft_putnbr.o: ./ft_putnbr.c
	gcc -c $(FLAGS) ./ft_putnbr.c

ft_putstr_fd.o: ./ft_putstr_fd.c
	gcc -c $(FLAGS) ./ft_putstr_fd.c

ft_strequ.o: ./ft_strequ.c
	gcc -c $(FLAGS) ./ft_strequ.c

ft_strjoin.o: ./ft_strjoin.c
	gcc -c $(FLAGS) ./ft_strjoin.c

ft_strnequ.o: ./ft_strnequ.c
	gcc -c $(FLAGS) ./ft_strnequ.c

ft_strsub.o: ./ft_strsub.c
	gcc -c $(FLAGS) ./ft_strsub.c

ft_memdel.o: ./ft_memdel.c
	gcc -c $(FLAGS) ./ft_memdel.c

ft_putendl.o: ./ft_putendl.c
	gcc -c $(FLAGS) ./ft_putendl.c

ft_putnbr_fd.o: ./ft_putnbr_fd.c
	gcc -c $(FLAGS) ./ft_putnbr_fd.c

ft_strclr.o: ./ft_strclr.c
	gcc -c $(FLAGS) ./ft_strclr.c

ft_striter.o: ./ft_striter.c
	gcc -c $(FLAGS) ./ft_striter.c

ft_strmap.o: ./ft_strmap.c
	gcc -c $(FLAGS) ./ft_strmap.c

ft_strnew.o: ./ft_strnew.c
	gcc -c $(FLAGS) ./ft_strnew.c

ft_strtrim.o: ./ft_strtrim.c
	gcc -c $(FLAGS) ./ft_strtrim.c

ft_lstadd.o: ./ft_lstadd.c
	gcc -c $(FLAGS) ./ft_lstadd.c

ft_lstdel.o: ./ft_lstdel.c
	gcc -c $(FLAGS) ./ft_lstdel.c

ft_lstdelone.o: ./ft_lstdelone.c
	gcc -c $(FLAGS) ./ft_lstdelone.c

ft_lstiter.o: ./ft_lstiter.c
	gcc -c $(FLAGS) ./ft_lstiter.c

ft_lstmap.o: ./ft_lstmap.c
	gcc -c $(FLAGS) ./ft_lstmap.c

ft_lstnew.o: ./ft_lstnew.c
	gcc -c $(FLAGS) ./ft_lstnew.c

clean:
	/bin/rm -f $(OBJECT) *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

