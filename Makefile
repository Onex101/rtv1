# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 13:06:01 by xrhoda            #+#    #+#              #
#    Updated: 2018/08/30 18:20:59 by xeno             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rtv1
FILES	= main.c \
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
INC		= -I includes

FILES =	camera.c \
		exit_programc. \
		image.c \
		main.c
SRCS_DIR = srcs
SRCS = $(addprefix %, $(SRC_DIR)%, $(FILES));

OBJ_DIR = obj
OBJ	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:%.o=%.d)

MLX_INC	= -I /usr/X11/include -g
#MLX_LNK	= -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
MLX_LNK = -Wl,--no-as-needed -I /usr/local/include  -lX11 -lXext -L. /usr/local/lib/libmlx_Linux.a

LIB_DIR = libraries
LIB		= libraries/lib_mstr.a
LIB_INC = -I libraries/includes
LIB_LNK = -L ./libraries -lraries

INC = $(RTV1_INC) $(MLX_INC) $(LIB_INC)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INC) -lm -o $@ $^ $(LIB) $(MLX_LNK)

obj: 
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

$(LIB):
 	make -C $(LIB_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re : fclean all
