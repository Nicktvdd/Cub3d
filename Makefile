NAME	:= cub3d
SRC_DIR	:= ./src
LIBMLX	:= ./lib/MLX42

OBJ		:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR	:= obj

INC		:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm

O_FLAGS	:= #-DDEBUG=1
C_FLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

SRC		:= cub3d.c
DEP		:= $(OBJ:.o=.d)

###############################################################

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ)
	cc $(C_FLAGS) $(OBJ) -o $(NAME) $(INC) $(LIBS) $(O_FLAGS)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(C_FLAGS) $(INC) -c $< -o $@ && printf "Compiling: $(notdir $<)"

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx