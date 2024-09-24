NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -framework OpenGL -framework AppKit
SRC_DIR = ./
CFILES = $(addsuffix .c, main mlx_ctr play move draw minimap exit map_check valid_and_init get_data_from_file parsing_utils \
valid_map init_structs init_structs_2 free_data free_data_2 errors_and_msg)
OBJS_DIR = ./objs
OBJS = $(CFILES:%.c=$(OBJS_DIR)/%.o)
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
HDRS = -I. -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR)/gnl -I $(LIBFT_DIR)/printf
SANIT = -g3 -fsanitize=address
LEAK = Leaks -atExit --
RM = rm -rf
HEADER = cub3D.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(MLXFLAGS) -o $@

$(OBJS_DIR)/%.o: %.c $(HEADER) | dirobj
	@$(CC) $(CFLAGS) $(HDRS) -c -o $@ $<

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

dirobj: 
	@mkdir -p $(OBJS_DIR)

sanit: $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(MLXFLAGS) -o $(NAME) $^ $(SANIT)

leak:
	$(LEAK) ./cub3D maps/test_map.cub

clean :
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(OBJS_DIR)/$(OBJS)
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

run: 
	./cub3D maps/test_map.cub

re: fclean all

.PHONY: all re clean fclean leak run