NAME		=	pipex
SRCS		=	srcs/pipex.c \
				srcs/main.c

LIBFT_DIR	=	srcs/libft/
LIBFT		=	$(LIBFT_DIR)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
OBJS		=	$(SRCS:%.c=%.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(BONUS): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

all:	$(NAME)

bonus:
	$(MAKE) BONUS_FLAG=true all

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

.PHONY: all bonus clean fclean re