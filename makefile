NAME		=	fdf

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

MLX			=	mlx/Makefile.gen

LFT			=	libft/libft.a

INC			=	-I ./include -I ./libft -I ./mlx

LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm

SRC			=	mandatory/main.c mandatory/reader.c mandatory/connecter.c mandatory/colors.c \
				mandatory/mover.c mandatory/validator.c mandatory/connecter_way.c \
				mandatory/basic_colors.c mandatory/float_func.c mandatory/get_next_line.c \
				mandatory/get_next_line_utils.c mandatory/width_counter.c

SRC_BONUS	= 	bonus/main_bonus.c bonus/reader_bonus.c bonus/connecter_bonus.c bonus/colors_bonus.c \
				bonus/mover_bonus.c bonus/validator_bonus.c bonus/connecter_way_bonus.c \
				bonus/basic_colors_bonus.c bonus/float_func_bonus.c bonus/get_next_line_bonus.c \
				bonus/get_next_line_utils_bonus.c bonus/width_counter_bonus.c

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	= 	$(SRC_BONUS:.c=.o)

RM		=	rm -rf

all:	 $(MLX) $(NAME)

bonus: $(MLX) $(OBJ_BONUS)
	@rm -rf $(OBJ)
	@make -s -C libft
	$(CC) $(FLAGS) -fsanitize=address -o fdf $(OBJ_BONUS) $(LIB)


$(NAME):	$(OBJ) 
			@rm -rf $(OBJ_BONUS)
			@make -s -C libft
			$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $(OBJ) $(LIB)

$(MLX):
			@make -s -C mlx

%.o:	%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@$(RM) $(OBJ) $(OBJ_BONUS)

fclean:		clean
			@make -s $@ -C libft
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re