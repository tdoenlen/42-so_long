
MODULE_SRC = mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ = $(MODULE_SRC:.swift=.swiftmodule)

SRC = interface.swift $(MODULE_SRC)
OBJ = $(SRC:.swift=.o)

C_SRC	= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ	= $(C_SRC:.c=.o)
CFLAGS	= -O3

ABSPATH	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME = libmlx.dylib

INC		= -I.
#OPTI	= -Ounchecked

# added vars
ERASE	= \033[2K\r
RED		= \033[31m
GREEN	= \033[32m
CYAN	= \033[36m
WHITE	= \033[37m
E		= \033[0m
BOLD	= \033[1m
INTRO_W		= $(BOLD)$(ERASE)$(RED)$(NAME)$(WHITE) : 
INTRO_G		= $(INTRO_W)$(GREEN)
FORM_NAME	= $(CYAN)'$(NAME)'$(WHITE)
$(shell printf "" > .compiled_files)


all:	$(NAME)

$(NAME):	$(MODULE_OBJ) $(OBJ) $(C_OBJ)
	count=$$(cat .compiled_files | wc -w | sed -e 's/ //g'); \
	if [ "$$count" = "0" ]; then \
		printf "$(INTRO_W)No object compiled$(E)\n"; \
	else \
		printf "$(INTRO_G)$$count object(s) compiled$(E)\n"; \
	fi
	rm -rf .compiled_files
	printf "$(INTRO_W)Compiling $(CYAN)'$@'$(WHITE)...$(E)"
	swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz \
		-Xlinker -install_name -Xlinker "$(ABSPATH)$(NAME)"
	printf "$(INTRO_G)Made$(E)\n"

%.o:	%.c
	printf "$(INTRO_W)Compiling $(CYAN)'$@'$(WHITE)...$(E)"
	gcc $(CFLAGS) -c $< -o $@
	echo $@ >> .compiled_files

%.o:	%.swift
	printf "$(INTRO_W)Compiling $(CYAN)'$@'$(WHITE)...$(E)"
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
	echo $@ >> .compiled_files

%.swiftmodule:	%.swift
	printf "$(INTRO_W)Compiling $(CYAN)'$@'$(WHITE)...$(E)"
	swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module \
		-module-name $(patsubst %.swift,%,$<) -module-link-name \
		$(patsubst %.swift,%,$<)
	echo $@ >> .compiled_files

clean:
	printf "$(INTRO_W)Removing files...$(E)"
	count=$$(rm -rfv $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~) \
	count=$$(echo "$$count" | wc -w | sed -e 's/ //g'); \
	if [ "$$count" = "0" ]; then \
		printf "$(INTRO_W)No file$(E)\n"; \
	else \
		printf "$(INTRO_G)$$count file(s) deleted$(E)\n"; \
	fi

fclean:
	printf "$(INTRO_W)Removing $(FORM_NAME)...$(E)"
	count=$$(rm -rfv $(NAME) | wc -w | sed -e 's/ //g'); \
	if [ "$$count" = "0" ]; then \
		printf "$(INTRO_W)No file $(FORM_NAME)$(E)\n"; \
	else \
		printf "$(INTRO_G)$(FORM_NAME)$(GREEN) deleted$(E)\n"; \
	fi

.PHONY:		all clean fclean
.SILENT:	$(NAME) $(C_OBJ) $(OBJ) $(MODULE_OBJ) clean fclean
