
NAME		= lib_mstr.a
CFLAGS		= -Wall -Werror -Wextra
INC			= -I includes

LIB_FT_SRCS = ft_memset.c \
				ft_bzero.c	\
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strlcat.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strsplit.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_strctrim.c \
				ft_strcount.c \
				ft_zero.c \
				ft_intlen.c \
				ft_poparr.c \
				ft_pull.c \
				ft_strclen.c \
				ft_strcdup.c \
				ft_chrcount.c \
				get_next_line.c \
				ft_sqr.c \
				isnum.c \
				ft_atod.c

LIB_FT = $(addprefix lib_ft/, $(LIB_FT_SRCS)) 

LIB_MAT_SRCS =	matrix_vec_mult.c \
				matrix_mult.c \
				matrix_master.c \
				matrix_identity.c \
				matrix_cpy.c \
				matrix_rotate.c \
				matrix_scale.c \
				matrix_translate.c \
				matrix_print.c \
				matrix_divide_row.c \
				matrix_get_row.c \
				matrix_inverse.c \
				matrix_sub_row.c \
				matrix_swap_row.c \
				matrix_transpose.c \
				matrix_axis_rot.c

LIB_MAT = $(addprefix lib_mat/, $(LIB_MAT_SRCS)) 

LIB_COLOUR_SRCS =	clamp_colour.c \
					colour_operations_new.c \
					colour_operations.c \
					gamma_correction.c \
					rgb_to_hex.c

LIB_COLOUR = $(addprefix lib_colour/, $(LIB_COLOUR_SRCS))

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
					set_inter.c \
					sphere_inter.c \
					sphere_hit_norm.c \
					sphere_new.c \
					cyl_inter.c \
					cyl_new.c \
					cone_new.c \
					cone_inter.c

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
				vec2_sub.c \
				vec3_project.c \
				vec3_prnt.c

LIB_VEC = $(addprefix lib_vec/, $(LIB_VEC_SRCS))

LIB_VECLST_SRCS =	vector_add.c \
					vector_delete.c \
					vector_free.c \
					vector_get.c \
					vector_init.c \
					vector_resize.c \
					vector_set.c \
					vector_total.c \
					vector_new.c
LIB_VECLST = $(addprefix lib_veclst/, $(LIB_VECLST_SRCS))

LIB_LIGHT_SRCS =	light_new.c

LIB_LIGHT = $(addprefix lib_light/, $(LIB_LIGHT_SRCS)) 

SRCS =	$(LIB_VEC) \
		$(LIB_SHAPE) \
		$(LIB_RAY) \
		$(LIB_MAT) \
		$(LIB_VECLST) \
		$(LIB_COLOUR) \
		$(LIB_FT) \
		$(LIB_LIGHT)

OBJ_LIST = $(patsubst %.c, %.o, $(SRCS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_LIST))
DEP := $(OBJ:%.o=%.d)

# debug:
	# @echo $(DEP)

all : $(NAME)
	@echo $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $?
	ranlib $@

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(dir $<))
	gcc $(CFLAGS) $(INC) -MMD -c $< -o $@

-include $(DEP)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
