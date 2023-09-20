NAME	:= cub3d

LIBFT_DIR = ./lib/libft/
SRC_DIR	:= ./src
LIBMLX	:= ./lib/MLX42
VPATH = src:libft
HEADER := ./inc

OBJ_DIR	:= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC		:= -I $(HEADER) -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm

O_FLAGS	:= #-DDEBUG=1
C_FLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

SRC		:= cub3d.c \
			error_msg.c start_map.c\

DEP		:= $(OBJ:.o=.d)

GNL_DIR = ./lib/get_next_line/
GNL = $(GNL_DIR)/get_next_line.c
GNL_UTILS = $(GNL_DIR)/get_next_line_utils.c


###############################################################

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cc $(C_FLAGS) $(INC) $(OBJ) $(LIBS) $(GNL) $(GNL_UTILS) $(O_FLAGS) -o $(NAME) 

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(C_FLAGS) $(INC) -c $< -o $@ && printf "Compiling: $(notdir $<)"

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx