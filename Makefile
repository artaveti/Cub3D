NAME 			= cub3D
HEADERS_DIR		= headers
SOURCES_DIR 	= sources
OBJECTS_DIR		= objects
HEADER_FILES	= $(wildcard $(HEADERS_DIR)/*.h)
SOURCE_FILES	= $(wildcard $(SOURCES_DIR)/*.c)
OBJECT_FILES	= $(patsubst $(SOURCES_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(SOURCE_FILES))

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror #-g -fsanitize=address
INC 	= -I
MLX		= mlx
TO_LINK = -l mlx -framework OpenGL -framework AppKit
AR 		= ar rcs
RM 		= rm -rf
MK 		= mkdir -p

all: $(OBJECTS_DIR) $(NAME)

$(OBJECTS_DIR): $(HEADERS_DIR) $(SOURCES_DIR)
	$(MK) $(OBJECTS_DIR)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) $(INC) $(HEADERS_DIR) $(INC) $(MLX) -c $< -o $@

$(NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(TO_LINK) -o $(NAME) 

clean:
	$(RM) $(OBJECTS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
