NAME        = cub3D
CC          = cc
CEXTRA      = -Wall -Wextra -Werror
INC_DIRS    = -Ilibft -Iinc -IMLX42/include
CFLAGS      = $(CEXTRA) $(INC_DIRS) -MMD -MP
SRC_DIR     = ./src
OBJ_DIR     = ./objs
MLX42_DIR   = MLX42
MLX42_LIB   = $(MLX42_DIR)/build/libmlx42.a
LIBFT_LIB   = libft/libft.a
LDLIBS      = $(LIBFT_LIB) $(MLX42_LIB) -ldl -lglfw -pthread -lm

FILES = \
	$(SRC_DIR)/move/move_1.c \
	$(SRC_DIR)/move/move_2.c \
	$(SRC_DIR)/render/errors.c \
	$(SRC_DIR)/render/render.c \
	$(SRC_DIR)/render/draw_columns_1.c \
	$(SRC_DIR)/render/draw_columns_2.c \
	$(SRC_DIR)/minimap/ray_1.c \
	$(SRC_DIR)/minimap/ray_2.c \
	$(SRC_DIR)/minimap/ray_3.c \
	$(SRC_DIR)/minimap/draw_1.c \
	$(SRC_DIR)/minimap/draw_2.c \
	$(SRC_DIR)/minimap/draw_3.c \
	$(SRC_DIR)/minimap/vec2d_1.c \
	$(SRC_DIR)/minimap/vec2d_2.c \
	$(SRC_DIR)/minimap/minimap_1.c \
	$(SRC_DIR)/map/map_color_1.c \
	$(SRC_DIR)/map/map_color_2.c \
	$(SRC_DIR)/map/map_1.c \
	$(SRC_DIR)/map/map_2.c \
	$(SRC_DIR)/map/map_3.c \
	$(SRC_DIR)/map/map_4.c \
	$(SRC_DIR)/map/map_5.c \
	$(SRC_DIR)/map/map_6.c \
	$(SRC_DIR)/map/map_7.c \
	$(SRC_DIR)/map/map_texture_1.c \
	$(SRC_DIR)/map/map_texture_2.c \
	$(SRC_DIR)/map/map_texture_3.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/init/init_2.c \
	$(SRC_DIR)/init/init_1.c

OBJ  = $(FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP  = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX42_LIB)
	$(CC) -o $@ $(OBJ) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🔧Compiling $< 🔨"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C libft

-include $(DEP)

$(MLX42_LIB):
	cd $(MLX42_DIR) && cmake -B build && cmake --build build -j4

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX42_DIR)/build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
