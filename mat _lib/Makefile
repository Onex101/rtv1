# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 13:45:05 by xrhoda            #+#    #+#              #
#    Updated: 2018/08/16 18:26:04 by xeno             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= mat_lib.a
CFLAGS		= -Wall -Werror -Wextra -I includes -c
FILES		=	vec3_add.c \
				vec3_crs.c \
				vec3_div.c \
				vec3_dot.c \
				vec3_len.c \
				vec3_mul.c \
				vec3_nor.c \
				vec3_sub.c \

OBJ			= $(FILES:%.c=%.o)

VEC3			= ../../vec3_lib/
VEC3_LIB		= $(addprefix $(V_),vec3_lib.a)
VEC3_INC		= -I ../../vec3_lib/includes
VEC3_LINK		= -L. ../../vec3_lib/vec3_lib.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(VEC3_LINK)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES) $(VEC3_INC)

$(VEC3_LIB):
	make -C $(VEC3)

so: $(NAME)
	gcc $(CFLAGS) -fpic $(FILES)
	gcc -shared -o mat_lib.so $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
