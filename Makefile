NAME		=	pipex

OBJ_DIR		=	./obj/

UTIL_DIR	=	srcs/mandatory/

UTIL		=	utils.c \
				errors.c \
				clear.c \
				get_path.c

OBJS		=	$(UTIL:%.c=$(OBJ_DIR)%.o)

MAIN_DIR	=	srcs/mandatory/

MAIN_SRCS	=	main.c
MAIN_OBJS	=	$(MAIN_SRCS:%.c=$(OBJ_DIR)%.o)

BONUS_DIR	=	srcs/bonus/

BONUS_SRCS	=	utils_bonus.c \
				multi_pipes_bonus.c \
				here_doc_bonus.c \
				main_bonus.c
BONUS_OBJS	=	$(BONUS_SRCS:%.c=$(OBJ_DIR)%.o)

GNL_DIR		=	srcs/get_next_line/

GNL_SRCS	=	get_next_line.c \
				get_next_line_utils.c
GNL_OBJS	=	$(GNL_SRCS:%.c=$(OBJ_DIR)%.o)

LIBFT_DIR	=	srcs/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

HEADER		=	include/

# Define colors
GREEN  := \033[0;32m
YELLOW := \033[0;33m
CYAN   := \033[0;36m
RESET  := \033[0m

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -I $(HEADER)

ifeq ($(BONUS_FLAG), true)
	OBJS += $(BONUS_OBJS) $(GNL_OBJS)
else
	OBJS += $(MAIN_OBJS)
endif

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	@echo "\n$(GREEN)$(BOLD)Linking $@...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(MAGENTA)$(BOLD)"
	@echo "╱╲┈┈╱╲"
	@echo "▏┈╲┈▏┈╲"
	@echo "╲┈▕┈╲┈▕"
	@echo "┈╲▕┈┈╲▕"
	@echo "┈╱┈▔▔▔┈╲"
	@echo "▕╭┈╮┈╭┈╮▏"
	@echo "╱┊▉┊┈┊▉┊╲"
	@echo "▏┈┳▕▇▏┳┈▕"
	@echo "╲┈╰┳┻┳╯┈╱"
	@echo "┈▔▏┗┻┛▕▔┈╱╲"
	@echo "┈╱▕╲▂╱▏╲╱┈╱"
	@echo "╱┈▕╱▔╲▏┈┈╱"
	@echo "┈╱▏┈┈┈▕╲╱"
	@echo "$(RESET)"
	@echo "$(GREEN)$(BOLD)Build complete! ✨$(RESET)"

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus:
	@$(MAKE) BONUS_FLAG=true

$(LIBFT):
	@echo "$(CYAN)$(BOLD)\nBuilding libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(UTIL_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(MAIN_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(CYAN)Cleaning up...$(RESET)"
	@sleep 0.3
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Clean complete! 🧹$(RESET)"

fclean: clean
	@echo "$(CYAN)Removing executable and cleaning libft...$(RESET)"
	@sleep 0.3
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Full clean complete! 🧼$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
