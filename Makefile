NAME = libftprintf.a
LIBFT = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ./includes/
HEADER_BONUS = ./includes_bonus/

LIBFT_DIR = src/libft/
SRC_DIR = src/
SRC_DIR_BONUS = src_bonus/

SRC = libftprintf.c \
	ft_processor.c \
	ft_utils.c \
	parser.c \
	ft_output_char.c \
	ft_output_int.c \
	ft_output_str.c \
	ft_output_unsigned.c \
	ft_output_hex.c \
	ft_output_pointer.c \
	ft_check_flags.c

SRC_BONUS = libftprintf_bonus.c \
	ft_processor_bonus.c \
	ft_utils_bonus.c \
	parser_bonus.c \
	ft_output_char_bonus.c \
	ft_output_int_bonus.c \
	ft_output_str_bonus.c \
	ft_output_unsigned_bonus.c \
	ft_output_hex_bonus.c \
	ft_output_pointer_bonus.c \
	ft_check_flags_bonus.c
	

OBJ =	$(addprefix $(SRC_DIR), $(SRC:.c=.o)) 
OBJ_BONUS =	$(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS:.c=.o)) 

all:	$(SRC_DIR) $(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)$(LIBFT) ./$(NAME)
		ar -rc $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	@make OBJ="$(OBJ_BONUS)" all

%.o : %.c
	$(CC) $(FLAGS) -I$(HEADER) -I ${HEADER_BONUS} -I$(LIBFT_DIR) -c $< -o $(<:.c=.o) 

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		rm -f $(LIBFT_DIR)$(LIBFT)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re