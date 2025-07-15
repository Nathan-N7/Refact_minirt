NAME = rt

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
MINILIBX = make_minilibx

SRC_DIR = src
LIB_DIR = lib

LIBFT = $(LIB_DIR)/libft.a
LIBVEC3 = $(SRC_DIR)/vec3/libvec3.a

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/mlx_usage.c \
	$(SRC_DIR)/color.c \
	$(SRC_DIR)/camera.c \
	$(SRC_DIR)/ray.c \
	$(SRC_DIR)/sphere.c \
	$(SRC_DIR)/hittable.c \
	$(SRC_DIR)/interval.c \
	$(SRC_DIR)/material.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBVEC3) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBVEC3) $(MINILIBX_FLAGS) -o $(NAME)
	@clear
	@echo "✅ ${NAME} is compiled."

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIB_DIR)

$(LIBVEC3):
	@make -C $(SRC_DIR)/vec3

make_minilibx:
		make -C minilibx-linux/

val:
	@clear
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

run: all
	@clear
	./$(NAME)

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(SRC_DIR)/vec3 clean
	@make -C minilibx-linux/ clean
	@rm -f $(OBJS)
	@clear
	@echo "🗑️ Objects removed."

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)
	@clear
	@echo "🗑️ Program and objects removed."

re: fclean all
