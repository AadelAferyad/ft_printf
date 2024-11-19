NAME := libftprintf.a
COMPILER := cc
FLAGS := -Wextra -Werror -Wall -c
REMOVE := rm -f

src := printf.c print_unsigned.c print_int.c print_hex.c print_characters.c print_address.c map_array_of_struct.c bonus_parsing.c bonus_print.c bonus_functions.c
obj = $(src:%.c=%.o) 

all: $(NAME)

$(NAME): $(obj)
	ar rcs $(NAME) $(obj)

%.o: %.c
	$(COMPILER) $(FLAGS) $< -o $@

clean:
	$(REMOVE) $(obj)
fclean:
	$(REMOVE) $(obj) $(NAME)

re: fclean all
