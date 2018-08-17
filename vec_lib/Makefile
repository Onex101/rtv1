# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 13:45:05 by xrhoda            #+#    #+#              #
#    Updated: 2018/08/17 14:52:41 by xeno             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= vec_lib.a
CFLAGS		= -Wall -Werror -Wextra -I includes -c
FILES		=	vec3_add.c \
				vec3_crs.c \
				vec3_div.c \
				vec3_dot.c \
				vec3_len.c \
				vec3_mul.c \
				vec3_nor.c \
				vec3_sub.c \
				vec2_add.c \
				vec2_div.c \
				vec2_lib.c \
				vec2_mul.c \
				vec2_sub.c \
				test.c \

OBJ			= $(FILES:%.c=%.o)
#FT_INC		= -I ../libft/includes
#FT_LIB		= -L. ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

$(FT_LIB):
	make -C $(FT)

so: $(NAME)
	gcc $(CFLAGS) -fpic $(FILES)
	gcc -shared -o vec3_lib.so $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
