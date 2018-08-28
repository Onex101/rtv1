# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 13:45:05 by xrhoda            #+#    #+#              #
#    Updated: 2018/08/28 13:30:01 by xrhoda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lib_mstr.a
CFLAGS		= -Wall -Werror -Wextra -c
INCLUDES	= -I includes

LIB_MAT_SRCS =	matrix_lib.c \
				matrix_util.c
LIB_MAT = $(addprefix lib_mat/, $(LIB_MAT_SRCS)) 

LIB_RAY_SRCS =	calc_pnt.c \
				inter_check.c \
				inter_cpy.c \
				inter_init.c \
				inter_new.c \
				inter_pos.c \
				ray_cpy.c \
				ray_init.c \
				ray_new.c
LIB_RAY = $(addprefix lib_ray/, $(LIB_RAY_SRCS))

LIB_SHAPE_SRCS =	plane_inter.c \
					plane_new.c \
					shapes_inter.c \
					sphere_inter.c \
					sphere_new.c
LIB_SHAPE = $(addprefix lib_shape/, $(LIB_SHAPE_SRCS))

LIB_VEC_SRCS =	vec3_add.c \
				vec3_crs.c \
				vec3_div.c \
				vec3_dot.c \
				vec3_len.c \
				vec3_mul.c \
				vec3_nor.c \
				vec3_sub.c \
				vec3_lib.c \
				vec2_add.c \
				vec2_div.c \
				vec2_lib.c \
				vec2_mul.c \
				vec2_sub.c
LIB_VEC = $(addprefix lib_vec/, $(LIB_VEC_SRCS))

SRCS =	$(LIB_VEC) \
		$(LIB_SHAPE) \
		$(LIB_RAY) \
		$(LIB_MAT)

OBJ_LIST = $(patsubst %.c, %.o, $(SRCS))


OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

FT_INC	= -I ../libft/includes
FT_LIB	= -L. ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(INCLDUES) $(FILES)

$(FT_LIB):
 	make -C $(FT)

so: $(NAME)
	gcc $(CFLAGS) -fpic $(FILES)
	gcc -shared -o lib_vec.so $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
