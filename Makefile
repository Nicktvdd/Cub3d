NAME	:= cub3d

LIBFT_DIR = ./libraries/libft/
LIBFT := $(LIBFT_DIR)/libft.a
SRC_DIR	:= ./src
LIBMLX	:= ./libraries/MLX42
VPATH = src:libft
HEADER := ./inc

OBJ_DIR	:= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC		:= -I $(HEADER) -I $(LIBMLX)/include
#School Macs#
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
#For Linux#
#LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
#MacHome
#LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -pthread -lm

O_FLAGS	:= #-DDEBUG=1
C_FLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g

SRC		:=  main.c parse_map_utils.c parse_utils.c\
			error_msg.c ft_free.c start_map.c check_map.c \
			check_map_utils.c #cub3d.c\

DEP		:= $(OBJ:.o=.d)

GNL_DIR = ./libraries/get_next_line/
GNL = $(GNL_DIR)/get_next_line.c
GNL_UTILS = $(GNL_DIR)/get_next_line_utils.c


###############################################################

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cc $(C_FLAGS) $(INC) $(OBJ) $(LIBS) $(GNL) $(GNL_UTILS) $(LIBFT) $(O_FLAGS) -o $(NAME) 

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(C_FLAGS) $(INC) -c $< -o $@ && printf "Compiling: $(notdir $<)"

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)
	#make -C $(LIBFT_DIR) fclean

re: fclean all

test: all
	./cub3d maps/map.cub

.PHONY: all, clean, fclean, re, libmlx