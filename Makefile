NAME		=	pipex

UTIL		=	srcs/mandatory/utils.c \
				srcs/mandatory/errors.c \
				srcs/mandatory/clear.c \
				srcs/mandatory/get_path.c
OBJS		=	$(UTIL:%.c=%.o)

MAN_SRCS	=	srcs/mandatory/main.c
MAN_OBJS	=	$(MAN_SRCS:%.c=%.o)

BONUS_SRCS	=	srcs/bonus/utils_bonus.c \
				srcs/bonus/multi_pipes_bonus.c \
				srcs/bonus/here_doc_bonus.c \
				srcs/bonus/main_bonus.c
BONUS_OBJS	=	$(BONUS_SRCS:%.c=%.o)

GNL_SRCS	=	srcs/get_next_line/get_next_line.c \
				srcs/get_next_line/get_next_line_utils.c
GNL_OBJS	=	$(GNL_SRCS:%.c=%.o)

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
	OBJS += $(MAN_OBJS)
endif

$(NAME): $(OBJS) $(LIBFT)
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

bonus:
	$(MAKE) BONUS_FLAG=true

$(LIBFT):
	@echo "$(CYAN)$(BOLD)\nBuilding libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(CYAN)Cleaning up...$(RESET)"
	@sleep 0.3
	rm -f $(MAN_OBJS) $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)
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
