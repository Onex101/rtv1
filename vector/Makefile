# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 13:45:05 by xrhoda            #+#    #+#              #
#    Updated: 2018/06/07 07:39:30 by xrhoda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= vector.a
CFLAGS		= -Wall -Werror -Wextra -I includes -c
FILES		=	vector_add.c \
				vector_delete.c \
				vector_free.c \
				vector_get.c \
				vector_init.c \
				vector_resize.c \
				vector_set.c \
				vector_total.c \

OBJ			= $(FILES:%.c=%.o)
FT_INC		= -I ../libft/includes
FT_LIB		= -L. ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES) $(FT_INC)

$(FT_LIB):
	make -C $(FT)

so: $(NAME)
	gcc $(CFLAGS) -fpic $(FILES) $(FT_LIB)
	gcc -shared -o vector.so $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
