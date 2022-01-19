NAME		=	fdf

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

MLX			=	mlx/Makefile.gen

LFT			=	libft/libft.a

INC			=	-I ./include -I ./libft -I ./mlx

LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm

SRC			=	main.c reader.c connecter.c colors.c mover.c

OBJ			=	$(SRC:.c=.o)

RM		=	rm -rf

all:		$(MLX) $(NAME)

$(NAME):	$(OBJ)
			@make -s -C libft
			$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)

$(MLX):
			@make -s -C mlx

%.o:	%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@$(RM) $(OBJ)

fclean:		clean
			@make -s $@ -C libft
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re