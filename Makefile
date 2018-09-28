# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 13:06:01 by xrhoda            #+#    #+#              #
#    Updated: 2018/09/27 15:13:29 by shillebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RTV1_INC = -I includes

FILES = main.c \
		new_cam.c \
		init_cam.c \
		init_param.c \
		make_ray.c \
		new_image.c \
		exit_program.c \
		destroy_image.c \
		new_image.c \
		ray_trace.c \
		render.c \
		input.c \
		ft_advance.c \
		ft_strcheck.c \
		get_double.c \
		get_tvec3.c \
		cam_info.c \
		read_camera.c \
		read_dir_light.c \
		read_lights.c \
		read_objects.c \
		read_plane.c \
		read_cone.c \
		read_cyl.c \
		read_scene.c \
		read_sphere.c \
		get_colour.c \
		get_tcol.c \
		calc_light.c \
		cast_ray.c \
		get_radius.c
SRC_DIR = srcs
SRCS = $(FILES:$(SRC_DIR)/%=%)

OBJ_DIR = obj
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:%.o=%.d)

MLX_INC = -I /usr/X11/include -g

uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ifeq ($(uname_S),Linux)
    MLX_LNK = -Wl,--no-as-needed -I /usr/local/include  -lm -lX11 -lXext -L. /usr/local/lib/libmlx_Linux.a
endif
ifeq ($(uname_S),Darwin)
    MLX_LNK	= -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
endif

LIB_DIR = libraries
LIB = libraries/lib_mstr.a
LIB_INC = -I libraries/includes
LIB_LNK = -L ./libraries -lraries

INC = $(RTV1_INC) $(MLX_INC) $(LIB_INC)

all: lib $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INC) -MMD -lm -o $@ $^ $(LIB) $(MLX_LNK)

obj :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

# $(LIB):
lib :
	make -C $(LIB_DIR)

clean :
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re : fclean all

debug: 
	echo $(OBJ)