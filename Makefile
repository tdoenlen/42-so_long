# Files
SRCS	= \
	animation/new_anim.c \
	animation/update_anim.c \
	game/display/bg_img.c \
	game/display/put_ttr_to_dest_tile.c \
	game/display/win_img.c \
	game/foes/foe_utils.c \
	game/foes/move_foes_utils.c \
	game/foes/move_foes.c \
	game/input/key_just_pressed.c \
	game/loop/update.c \
	game/init_bg.c \
	game/init_game.c \
	game/load_ttrs.c \
	game/reset_game.c \
	image/get_img_pixel.c \
	image/img_pixel_put.c \
	image/new_img.c \
	lib/add_str_to_tab.c \
	lib/ft_itoa.c \
	lib/ft_strlen.c \
	lib/get_next_line.c \
	lib/safe_free_data.c \
	lib/safe_free.c \
	parsing/open_file.c \
	parsing/parse_file.c \
	quit.c \
	main.c
SRCS	:= $(SRCS:%.c=srcs/%.c)
OBJS	= $(SRCS:%.c=%.o)
INCS	= \
	animation.h \
	data.h \
	events.h \
	game.h \
	image.h \
	lib.h \
	master.h \
	parsing.h \
	texture_struct.h
INCS	:= $(INCS:%.h=headers/%.h) mlx/mlx.h
NAME	= so_long

# mlx files
MLX_PATH	= mlx/
MLX			= $(MLX_PATH)libmlx.dylib
MLX_MODULES	= mlx_image.swift mlx_window.swift mlx_init.swift
MLX_SRCS	= interface.swift $(MLX_MODULES)
MLX_SRCS	:= $(MLX_SRCS:%.swift=$(MLX_PATH)%.swift)
MLX_CSRCS	= mlx_xpm.c mlx_png.c mlx_string_put.c
MLX_CSRCS	:= $(MLX_CSRCS:%.c=$(MLX_PATH)%.c)
MLX_OBJS	= \
	$(MLX_MODULES:.swift=.swiftmodule) \
	$(MLX_SRCS:.swift=.o) \
	$(MLX_CSRCS:.c=.o)

# Compilation
CC		= gcc
LDFLAGS	= -Lmlx -Iheaders -Imlx -lmlx
CFLAGS	= -Wall -Wextra -Werror -Iheaders -Imlx -Ofast

# Colors
ERASE		= \033[2K\r
RED			= \033[31m
GREEN		= \033[32m
CYAN		= \033[36m
WHITE		= \033[37m
DEFAULT		= \033[0m
BOLD		= \033[1m

# Messages
INTRO_W		= $(BOLD)$(ERASE)$(RED)$(NAME)$(WHITE) : 
INTRO_G		= $(INTRO_W)$(GREEN)
E			= $(DEFAULT)
FORM_NAME	= $(CYAN)'$(NAME)'$(WHITE)
$(shell printf "" > .compiled_files)

# Norme
NORME_DIRS	= srcs headers

$(NAME):	$(OBJS) $(MLX)
	count=$$(cat .compiled_files | wc -w | sed -e 's/ //g'); \
	if [ "$$count" = "0" ]; then \
		printf "$(INTRO_W)No object compiled$(E)\n"; \
	else \
		printf "$(INTRO_G)$$count object(s) compiled$(E)\n"; \
	fi
	rm -rf .compiled_files
	printf "$(INTRO_W)Compiling $(CYAN)'$@'$(WHITE)...$(E)"
	$(CC) $(LDFLAGS) $^ -o $@
	printf "$(INTRO_G)Made$(E)\n"

bonus:	$(NAME)

all:	$(NAME)

%.o:	%.c $(INCS)
	printf "$(INTRO_W)Compiling $(CYAN)'$@'$(WHITE)...$(E)"
	$(CC) $(CFLAGS) -c $< -o $@
	echo $@ >> .compiled_files

$(MLX):
	make -C $(MLX_PATH)

clean:
	printf "$(INTRO_W)Removing files...$(E)"
	count=$$(rm -rfv $(OBJS) | wc -w | sed -e 's/ //g'); \
	if [ "$$count" = "0" ]; then \
		printf "$(INTRO_W)No file$(E)\n"; \
	else \
		printf "$(INTRO_G)$$count file(s) deleted$(E)\n"; \
	fi
	$(MAKE) -C $(MLX_PATH) $@

fclean:	clean
	printf "$(INTRO_W)Removing $(FORM_NAME)...$(E)"
	count=$$(rm -rfv $(NAME) | wc -w | sed -e 's/ //g'); \
	if [ "$$count" = "0" ]; then \
		printf "$(INTRO_W)No file $(FORM_NAME)$(E)\n"; \
	else \
		printf "$(INTRO_G)$(FORM_NAME)$(GREEN) deleted$(E)\n"; \
	fi
	$(MAKE) -C $(MLX_PATH) $@

re:	fclean all

n:
	printf "Checking norme in $$(printf "$(NORME_DIRS)" | sed "s/ /, /g")\n"
	NORM=$$(/usr/bin/norminette $(NORME_DIRS)); \
	NORM_ERR=$$(printf "$$NORM" | grep -e Error\: | wc -l \
			| sed "s/ //g"); \
	if [ "$$NORM_ERR" = "0" ]; then \
			printf "Everything seems normed!\n"; \
	else \
			NORM_FIL=$$(printf "$$NORM" | grep -e Error\! \
					| wc -l | sed "s/ //g"); \
			printf "\n\t$$NORM_ERR error(s) in $$NORM_FIL file(s):\n\n"; \
			printf "$$(printf "$$NORM" | grep -e Error)\n"; \
	fi

.PHONY:		all clean fclean re n
.SILENT:	$(NAME) $(OBJS) $(MLX) all clean fclean n
