NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC = ft_printf.c\
	parse.c\
	get_flag.c\
	get_width.c\
	get_precision.c\
	get_length.c\
	get_index.c\
	convert_and_apply.c\
	create_unsigned.c\
	create_signed.c\
	create_char_string.c\
	create_wchar_string.c\
	check_params.c\
	apply_param_unsigned.c\
	apply_param_signed.c\
	apply_param_string.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

INC = ./includes

SRCS = $(addprefix $(SRC_PATH), $(SRC))

all: $(NAME)

$(NAME):
	make -C libft/
	cp libft/libft.a ./$(NAME)
	gcc -c $(FLAG) $(SRCS) -I $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make fclean -C libft/
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
